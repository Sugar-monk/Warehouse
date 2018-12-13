#pragma once

#include<stdio.h>

int Sum(int n, size_t num)
{
	int sum = 0;
	int tmp = n;
	for (size_t i = 0; i < num; i++)
	{
 		sum += tmp;
		tmp = (tmp * 10) + n;
	}

	return sum;

}