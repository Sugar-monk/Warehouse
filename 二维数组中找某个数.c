#include<stdio.h>

int find(int array[10][10], int cows, int columns,const int num  )
{
	int row = 0;
	int column = columns - 1;
	int ret = -1;

	while (row <= cows && column >= 0)
	{
		if (array[row][column] == num)
		{
			ret = 1;
			break;
		}
		if (num > array[row][column])
		{
			row++;
		}
		if (num < array[row][column])
		{
			column--;
		}
	}
	return ret;
}

int main()
{
	int arr[5][8] = { { 1, 2, 3, 4, 5 }, { 2, 4, 5, 6, 7 }, { 3, 4, 5, 6, 7 } };
	int num = 11;
	int row = sizeof(arr) / sizeof(arr[0]);
	int column = sizeof(arr[0]) / sizeof(int);
	int ret = 0;
	ret = find(arr, row, column, num);
	if (ret == 1)
	{
		printf("找到了\n");
	}
	else
	{
		printf("没有找到！\n");
	}

	return 0;
}


