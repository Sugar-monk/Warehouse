#include <stdio.h>
#define X 10              //����
#define Y 10              //����
#define NUM 8             //���Ͻǵ�һ��������ʼֵ��
int find_arr(int arr[X][Y], int x, int y)
{
	int input = 0;
	int i = 0;
	int j = 0;
	j = X - 1;
	printf("������Ҫ���ҵ�����>\n");
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
//���Һ�����
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
	//���鴴�����

	//���ؽ����ʼ���ú���
	if ((find_arr(arr, X, Y)) == 1)
	{
		printf("�ҵ��ˣ�\n");
	}
	else
	{
		printf("û�ҵ�\n");
	}
	return 0;
}