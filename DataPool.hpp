#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <semaphore.h>

class DataPool
{
	private:
		std::vector<std::string> pool;		//数据池
		int cap;							//容量
		sem_t data_sem;						//保护数据的信号量
		sem_t black _sem;					//保护格子的信号量
		int product_step;
		int consume_step;
	public:
		DataPool(int cap_ = 512):cap(cap_),pool(cap_)
		{
			sem_init(&data_sem, 0, 0);
			sem_init(&black_sem, 0, cap);
			product_step = 0;
			consume_step = 0;
		}
		void PutMessage(const std::string &msg)
		{
			sem_wait(&blank_sem);
			pool[product_step] = msg;
			product_step++;
			product_step %= cap;
			sem_post(&data_sem);			//防止越界
		}
		void GetMessage(const std::string &msg)
		{
			sem_wait(&data_sem);
			msg = pool[consume_step];
			consume_step++;
			consume_step %= cap;			//防止越界
			sem_post(&black_sem)
		}
		~DataPool()
		{
			sem_destroy(&data_sem);
			sem_destroy(&black_sem);
		}
		
}
