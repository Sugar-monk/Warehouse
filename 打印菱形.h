#pragma once

#include<stdio.h>

void Print(size_t n)   //n为要打印的行数
{
	int i = 0;
	for (i = 0; i <= n; i+=2)
	{
		for (size_t k = 0; k < (n - i - 1) / 2; ++k)   //打印*前面的空格，使菱形更美观
			printf(" ");
		for (size_t j = 0; j < i +1 ; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = n - 2; i >0; i -= 2)
	{
		for (size_t k = 0; k < (n - i) / 2; ++k)   //打印*前面的空格，使菱形更美观
			printf(" ");
		for (size_t j = 0; j < i ; ++j)
		{
			printf("*");
		}
		printf("\n");
	}

}