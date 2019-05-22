/*************************************************************************
-> 文件名: join.c
-> 作者: bean
-> 邮箱: 17331372728@163.com
-> 创建时间: Wed 22 May 2019 06:45:24 AM PDT
-> 备注:
*************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<errno.h>

void* thr_start(void* arg)
{
    sleep(3);
    return "abc";
}
int main(int argc, char* argv[])
{
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, thr_start, NULL);
    if(ret != 0)
    {
        printf("pthread create error\n");
        return -1;
    }

    // int pthread_join(pthread_t thread, void **retval);
    // thread:等待的线程ID
    // retval：用户获取线程的退出返回值
    char *retval;
    pthread_join(tid,(void**)&retval);
    printf("retval:%s\n", retval);
	return 0;
}

