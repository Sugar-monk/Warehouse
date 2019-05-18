/*************************************************************************
  -> 文件名: rwlock.c
  -> 作者: bean
  -> 邮箱: 17331372728@163.com
  -> 创建时间: Fri 17 May 2019 08:27:38 PM PDT
  -> 备注:读写锁的使用与体会，读共享，写互斥
 *************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<errno.h>

pthread_rwlock_t rwlock;

void *thr_writer(void* arg)
{
    while(1)
    {
        //写者加写锁
        //int pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock);
        //非阻塞加写锁
        //int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock);
        //阻塞加写锁
        pthread_rwlock_wrlock(&rwlock);
        printf("-----------I am writer---------\n");
        usleep(1000);
        //int pthread_rwlock_unlock(pthread_rwlock_t *rwlock);
        //解锁，解锁不管读锁或者写锁
        pthread_rwlock_unlock(&rwlock);
    }
    return NULL;
}
void *thr_reader(void* arg)
{
    while(1)
    {
        //读者加读锁
        //int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock);
        //阻塞加读锁
        //int pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock);
        //非阻塞加读锁
        pthread_rwlock_rdlock(&rwlock);
        printf("---I am reader---\n");
        usleep(1000);
        pthread_rwlock_unlock(&rwlock);
    }
    return NULL;
}
int main(int argc, char* argv[])
{
    pthread_t rtid[4],wtid;
    int i, ret;
    //因为读写锁默认是读者优先，所以要设置读写锁的属性
    //读写锁属性的销毁
    //int pthread_rwlockattr_destroy(pthread_rwlockattr_t *attr);
    //读写锁属性的初始化
    //int pthread_rwlockattr_init(pthread_rwlockattr_t *attr);
    //设置读写锁的优先级
    //int pthread_rwlockattr_setking_np(pthread_rwlockattr_t *attr,int pref);
    //attr: 读写锁
    //pref：PTHREAD_RWLOCK_PREFER_READER_NP 读者优先   
    //      PTHREAD_RWLOCK_PREFER_WRITER_NP 写者优先，目前有BUG，也是读者优先  
    //      PTHREAD_RWLOCK_PREFER_WRITER_NONERCURSIVE_NP 写者优先，但是写者不能递归加锁
   
    
    pthread_rwlockattr_t attr;
    pthread_rwlockattr_init(&attr);
    pthread_rwlockattr_setkind_np(&attr,PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP);
    //初始化读写锁
    //int pthread_rwlock_init(pthread_rwlock_t *restrict rwlock, pthread_rwlockattr_t *restrict attr)
    //rwlock:读写锁
    //attr： 读写锁属性
    pthread_rwlock_init(&rwlock,&attr);

    ret = pthread_create(&wtid,NULL,thr_writer, NULL);
    if(ret != 0)
    {
        printf("thread create error\n");
        return -1;
    }
    for(i = 0; i < 4; ++i)
    {
        ret = pthread_create(&wtid,NULL,thr_reader, NULL);
        if(ret != 0)
        {
            printf("thread create error\n");
            return -1;
        }

    }

    pthread_join(wtid,NULL);
    for(i = 0; i < 4; ++i)
    {
        pthread_join(rtid[i],NULL);
    }

    //读写锁的销毁
    // int pthread_rwlock_destroy(pthread_rwlock_t *rwlock);
    // rwlock：读写锁
    pthread_rwlock_destroy(&rwlock);
    pthread_rwlockattr_destroy(&attr);
    return 0;
}

