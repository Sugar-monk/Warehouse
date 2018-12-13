#pragma once

#include<stdio.h>
#include<math.h>

void Flower()
{

	for (size_t i = 0; i <= 999; i++)
	{
		int t = i;
		int num = 0;
		while (t)
		{
			double tmp = t % 10;
			num += pow(tmp, 3);
			t = t / 10;
		}
		if (num == i)
			printf("%d ", i);
	}
	printf("\n");
}