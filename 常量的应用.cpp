#include<istream>
using namespace std;
#include<utility>

//1.将数组A中的内容和数组B中的内容进行交换。（数组一样大）
#if 0
int main()
{
	int arr1[] = { 1,2,3,4 };
	int arr2[] = { 4,5,6,7 };
	size_t size = sizeof(arr1) / sizeof(arr1[0]);
	for (size_t i = 0; i < size; ++i)
	{
		int tmp = 0;
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}

	return 0;
}
#endif
//2. 计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值。

#if 0
int main()
{
	int n = 1;
	double sum = 0;
	
	while (n <= 100)
	{
		if (n % 2)
		{
			sum += (1 / (double)n++);
		}
		else
		{
			sum -= (1 / (double)n++);
		}
	}

	return 0;
}

#endif
//3. 编写程序数一下 1到 100 的所有整数中出现多少次数字9。

int main()
{

	int count = 0;
	
	for (int i = 1; i < 100; i++)
	{
		if ((i%10) / 9 )
			count++;
	}

	return 0;
}

