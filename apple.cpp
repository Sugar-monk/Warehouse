#include <stdio.h>
#include <iostream>
using namespace std;
//��Ŀ��
/*ֻ��ţ����һ�ţ�ÿ����ţӵ�� ai ��ƻ����������Ҫ������֮��ת��ƻ����
ʹ�����������ţӵ�е�ƻ��������ͬ��ÿһ�Σ���ֻ�ܴ�һֻ��ţ��������
ǡ������ƻ������һ����ţ�ϣ���������Ҫ�ƶ����ٴο���ƽ��ƻ�������������������� - 1��
*/
//�㷨˼�룺
//��ÿ����ţӵ�е�ƻ�������һ�������У�ƻ��������������ţ�ĸ�����
//�������������ƽ�����䣬û�з�����������ÿ����ţ������ĸ����Ƿ���2����������
//������ǣ�û�з��������򽫶�����ı�����ӾͿ��Եõ�����
int main()
{
	int arr[100] = {0};
	int num = 0;
	int sum = 0;
	bool flag = true;
	int count = 0;
	cin >> num;
	
	for (int i = 0; i < num; ++i)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum%num != 0)
		flag = false;
	else
	{
		int ave = sum / num;
		for (int i = 0; i < num; ++i)
		{
			if ((arr[i] - ave) % 2 != 0)
				flag = false;
			else if (arr[i] > ave)
				count += (arr[i] - ave) / 2;
		}
	}
	if (!flag)
		cout << "-1" << endl;
	else
		cout << count << endl;
	return 0;
}