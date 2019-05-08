#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int have_noodle = 0;
pthread_cond_t cond; //使用函数初始化
pthread_mutex_t mutex;
void *thr_sale(void *arg)//做面的
{
	while(1)
	{
        pthread_mutex_lock(&mutex);
        //有面了，没人吃，就等待
		if(have_noodle != 0)    //说明有面
        {
        //int pthread_cond_wait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex);
        //cond 条件变量
        //mutex 互斥锁 由于条件变量的使用一定会涉及到外部数据，如果对全局变量进行使用，就应该加锁
            pthread_cond_wait(&cond, &mutex);
        }
		printf("sale ------- make noodles\n");//做了一碗面
        have_noodle = 1;
        //int pthread_cond_broadcast(pthread_cond_t *cond);
        //唤醒所有等待线程
        // int pthread_cond_signal(pthread_cond_t *cond);
        //换新至少一个等待线程
        //昨完面就唤醒吃面的人
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
	}
	return NULL;
}
void *thr_buy(void *arg)//吃面的
{
	while(1)
	{
        pthread_mutex_lock(&mutex);
		if(have_noodle == 0)//说明没有面
        {
            pthread_cond_wait(&cond, &mutex);
        }
		printf("buy ------- eat noodles\n");//吃了一碗面
        //吃碗面就换新做面的人
        have_noodle = 0;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t tid1,tid2;

	int ret;
    //初始化条件变量
    //int pthread_cond_init(pthread_cond_t *restrict cond,
    //              const pthread_condattr_t *restrict attr);
    //cond 条件变量
    //attr 条件变量属性 （通常置空）

    pthread_cond_init(&cond, NULL);
    pthread_mutex_init(&mutex, NULL);

	ret = pthread_create(&tid1, NULL, thr_sale, NULL);
	if(ret != 0) 
	{
		printf("thread create error\n");
		return -1;
	}
	ret = pthread_create(&tid2, NULL, thr_buy, NULL);
	if(ret != 0) 
	{
		printf("thread create error\n");
		return -1;
	}

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
    //int pthread_cond_destroy(pthread_cond_t *cond);
    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&mutex);

	return 0;
}
