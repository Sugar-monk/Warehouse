#include <stdio.h>
#define X 10              //行数
#define Y 10              //列数
#define NUM 8             //左上角第一个数（起始值）
int find_arr(int arr[X][Y], int x, int y)
{
	int input = 0;
	int i = 0;
	int j = 0;
	j = X - 1;
	printf("请输入要查找的数字>\n");
	scanf("%d", &input);
	while (1)
	{
		if (input < arr[i][j])
		{
			j--;
		}

		if (input > arr[i][j])
		{
			i++;
		}

		if (input == arr[i][j])
		{
			return 1;
		}
		if ((i >= (Y - 1)) | (j < 0))
		{
			return 0;
		}
		/*printf("%d %d %d\n", i, j, arr[i][j]);*/
	}
}
//查找函数体
int main()
{
	int arr[X][Y];
	int i = 0;
	int j = 0;
	int num = 0;
	num = NUM;
	for (i = 0; i < Y; i++)
	{
		for (j = 0; j < X; j++)
		{
			arr[i][j] = num + (2*i) + j;
			printf("%3d ", arr[i][j]); 
		}
		printf("\n");
	}
	//数组创建完成

	//返回结果开始调用函数
	if ((find_arr(arr, X, Y)) == 1)
	{
		printf("找到了！\n");
	}
	else
	{
		printf("没找到\n");
	}
	return 0;
}