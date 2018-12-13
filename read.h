#pragma once

#include<stdio.h>

void Read()
{
	char tmp = ' ';
	size_t count = 0;
	//size_t count2 = 0;
	while ((tmp = getchar()) != EOF)
	{
		if (tmp == '{')
			count++;
		else if (tmp == '}' && count == 0)
		{
			printf("不匹配！！！\n");
			return 0;
		}
		else if (tmp == '}' && count != 0)
			count--;
	}

	if (count == 0)
		printf("匹配成功！！\n");
	else
		printf("匹配不成功！！\n");
}