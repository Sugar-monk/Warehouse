#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int have_noodle = 0;
//pthread_cond_t cond; //使用函数初始化
//如果有多个角色，需要使用多个条件变量分别去等待，
//不能等待同一条件变量，有肯能出现唤醒角色出错
pthread_cond_t chimian; //吃面的人等待在这里
pthread_cond_t zuomian; //做面的人等待在这里
pthread_mutex_t mutex;
void *thr_sale(void *arg)//做面的
{
    while(1)
    {
        //由于条件变量的使用一定会涉及到外部数据，如果对全局变量进行使用，就应该加锁
        //havenoodle是临界资源，所以需要加锁操作
        pthread_mutex_lock(&mutex);
        //有面了，没人吃，就等待
        while(have_noodle != 0)//说明没有面 if 改为while是为了防止没有面了继续去吃面
        {
            //int pthread_cond_wait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex);
            //cond 条件变量
            //mutex 互斥锁 
            //这个函数中集合了解锁+休眠+被唤醒后加锁的原子操作
            //如果不能做面就要解锁要让人能吃面
            pthread_cond_wait(&zuomian, &mutex);
        }
        printf("sale ------- make noodles\n");//做了一碗面
        have_noodle = 1;
        //int pthread_cond_broadcast(pthread_cond_t *cond);
        //唤醒所有等待线程
        // int pthread_cond_signal(pthread_cond_t *cond);
        //换新至少一个等待线程
        //做完面就唤醒吃面的人
        pthread_cond_signal(&chimian);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}
void *thr_buy(void *arg)//吃面的
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        while(have_noodle == 0) //说明没有面 if 改为while是为了防止没有面了继续去吃面,
                                 //如果使用一个条件变量，有可能会造成唤醒的角色不对
        {
            pthread_cond_wait(&chimian, &mutex);
        }
        printf("buy ------- eat noodles\n");//吃了一碗面
        //吃碗面就换新做面的人
        have_noodle = 0;
        pthread_cond_signal(&zuomian);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t tid1,tid2;

    int ret,i;
    //初始化条件变量
    //int pthread_cond_init(pthread_cond_t *restrict cond,
    //              const pthread_condattr_t *restrict attr);
    //cond 条件变量
    //attr 条件变量属性 （通常置空）

    pthread_cond_init(&chimian, NULL);
    pthread_cond_init(&zuomian, NULL);
    pthread_mutex_init(&mutex, NULL);
    for(i = 1; i < 2; ++i)
    {
        ret = pthread_create(&tid1, NULL, thr_sale, NULL);
        if(ret != 0) 
        {
            printf("thread create error\n");
            return -1;
        }
    }
    for(i = 0;i < 4; ++i)
    {
        ret = pthread_create(&tid2, NULL, thr_buy, NULL);
        if(ret != 0) 
        {
            printf("thread create error\n");
            return -1;
        }
    }
    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    //int pthread_cond_destroy(pthread_cond_t *cond);
    pthread_cond_destroy(&chimian);
    pthread_cond_destroy(&zuomian);
    pthread_mutex_destroy(&mutex);

    return 0;
}
