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
			printf("��ƥ�䣡����\n");
			return 0;
		}
		else if (tmp == '}' && count != 0)
			count--;
	}

	if (count == 0)
		printf("ƥ��ɹ�����\n");
	else
		printf("ƥ�䲻�ɹ�����\n");
}