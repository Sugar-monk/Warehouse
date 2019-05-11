#include <iostream>
using namespace std;
//1.
//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���
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
//ʹ�ú���ʵ���������Ľ�����
//
void Swap(int &a,int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
//3.
//ʵ��һ�������ж�year�ǲ������ꡣ
//
bool RunYear(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}
//4.
//����һ�����飬
//ʵ�ֺ���init������ʼ������
void Init(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
		arr[i] = 0;
}
//ʵ��empty����������顢

//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��
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
//5.ʵ��һ���������ж�һ�����ǲ���������

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