#pragma once

#include<stdio.h>

void Print(size_t n)   //nΪҪ��ӡ������
{
	int i = 0;
	for (i = 0; i <= n; i+=2)
	{
		for (size_t k = 0; k < (n - i - 1) / 2; ++k)   //��ӡ*ǰ��Ŀո�ʹ���θ�����
			printf(" ");
		for (size_t j = 0; j < i +1 ; ++j)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = n - 2; i >0; i -= 2)
	{
		for (size_t k = 0; k < (n - i) / 2; ++k)   //��ӡ*ǰ��Ŀո�ʹ���θ�����
			printf(" ");
		for (size_t j = 0; j < i ; ++j)
		{
			printf("*");
		}
		printf("\n");
	}

}