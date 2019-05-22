/*************************************************************************
-> 文件名: creat.c
-> 作者: bean
-> 邮箱: 17331372728@163.com
-> 创建时间: Wed 22 May 2019 05:28:03 AM PDT
-> 备注:线程的创建
 ***********************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<errno.h>
#include<pthread.h>

void* thr_start(void *arg)
{
    while(1)
    {
        printf("child thread ---%d----pid->%d\n", arg, getpid());
        sleep(1);
        exit(0);
    }
    return NULL;
}
int main(int argc, char* argv[])
{
     //int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
     //thread :用于保存返回的线程ID
     //attr   :线程的属性，通常为NULL
     //start_routine :线程入口函数
     //arg    :给线程传入的参数
     //返回值：0    失败：errno
     pthread_t tid;
     int ret = pthread_create(&tid, NULL, thr_start, (void*)996);
     if(ret != 0)
     {
         printf("pthread creat error\n");
         return -1;
     }

     while(1)
     {
         printf("main thread-------chile itd->%d  pid->%d \n", tid, getpid());
         sleep(1);
     }
	return 0;
}

