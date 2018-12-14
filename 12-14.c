//#include <stdio.h>
//#define SWAP(num) ( (((num)&0X55555555)<<1) | (((num)&0XAAAAAAAA)>>1) ) //16进制
//                //奇数位01010 1010...0101     偶数位1010 1010 1010...1010
//#define MAX(a,b)  ((a)>(b)?(a):(b))        //运用三目运算符
//int main()
//{
//	printf("%d\n ", MAX(15, 8));
//	printf("%d\n",SWAP(120));
//	return 0;
//}

//
#include <stdio.h>
int main()
{
	int arr[] = { 3,4,8,12,11,18,20,1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int left = 0;
	int right = 0;
	int i = 0;
	right = sizeof(arr) / sizeof(arr[0]);
	while (left < right)
	{
		if ((arr[left] % 2) == 0)
		{
			while (left < right)
			{
				if ((arr[right] % 2) ==1)
				{
					arr[left] = arr[left] ^ arr[right];
					arr[right] = arr[left] ^ arr[right];
					arr[left] = arr[left] ^ arr[right];
					break;
				}
				right--;
			}
		}
		else
		{
			left++;
		}
	}

	for (i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}