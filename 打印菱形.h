#pragma once

#include<stdio.h>

void Print(size_t n)   //nΪҪ��ӡ������
{
	int i = 0;
	for (i = 0; i <= n; i+=2)
	{
		for (size_t j = 0; j < i +1 ; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = n - 2; i >0; i -= 2)
	{
		for (size_t j = 0; j < i ; ++j)
		{
			printf("*");
		}
		printf("\n");
	}

}