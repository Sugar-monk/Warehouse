//1. �����������α�����ֵ��������ֵ�����ݽ��н�����
#if 0
#include<stdio.h>

void* swap1(int* i, int* j)
{
	int *c = 0;
	c = *i;
	*i = *j;
	*j = c;
}
int main()
{
	int a = 0;
	int b = 0;
	a = 11;
	b = 22;
	//2. ����������ʱ���������������������ݣ������⣩
	a = a + b;
	b = a - b;
	a = a - b;
	//swap1(&a, &b);
	printf("%d\n%d\n ", a, b);
	return 0;
}
#endif

#if 0
//3.��10 �����������ֵ��
#include<stdio.h>
#include<time.h>
#include<stdlib.h>


int main()
{
	int arr[10] = {0};
	srand((unsigned)time(NULL));
	int i = 0;

	for (i = 0; i < 10; ++i)
	{
		arr[i] = rand()%100;
	}

	int Max = 0;
	for (i = 0; i < 10; ++i)
	{
		if (arr[i] > Max)
			Max = arr[i];
	}
	return 0;
}
#endif

//4.�����������Ӵ�С�����

#if 0
#include<stdio.h>
#include<time.h>
#include<stdlib.h>


int main()
{
	int arr[3] = { 0 };
	srand((unsigned)time(NULL));
	int i = 0;
	for (i = 0; i < 3; ++i)
	{
		arr[i] = rand() % 100;
		printf("%d ", arr[i]);
	}
	printf("\n");
	int count = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < count; ++i)
	{
		int j = 0;
		for (j = i + 1; j < count; ++j)
		{
			if (arr[i] < arr[j])
			{
				int tmp;
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	for (i = 0; i < count; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");


	return 0;
}
#endif
