#include <iostream>
using namespace std;
//1.
//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。
//
void Print(int num)
{
	for (int i = 1; i <= num; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			cout << i << " * " << j << " = " << i*j << "  ";
		}
		cout << endl;
	}
}
//2.
//使用函数实现两个数的交换。
//
void Swap(int &a,int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
//3.
//实现一个函数判断year是不是润年。
//
bool RunYear(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}
//4.
//创建一个数组，
//实现函数init（）初始化数组
void Init(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
		arr[i] = 0;
}
//实现empty（）清空数组、

//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。
//
void Reverse(int arr[], int size)
{
	int left = 0, right = size - 1;
	while (left < right)
	{
		Swap(arr[left], arr[right]);
		++left;
		--right;
	}
}
//5.实现一个函数，判断一个数是不是素数。

int main()
{
	int num;
	/*cin >> num;
	Print(num);*/
	int i = 10, j = 20;
	/*Swap(i, j);
	cout << i << " "<< j << endl;*/

	/*if (RunYear(2000))
		cout << "yes" << endl;
	else
		cout << "No" << endl;*/

	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	//Reverse(arr, size);
	Empty(arr, size);

	for (int i = 0; i < size; ++i)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}