#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/*
�����ڼ�С��ʹ��΢���յ��ܶ��������ǳ����ġ��ڲ鿴��ȡ�����¼ʱ���֣�ĳ����������ֵĴ��������˺��������һ�롣���С���ҵ��ú����д�������㷨˼·�ʹ���ʵ�֣�Ҫ���㷨�����ܸ�Ч��
����һ������Ľ������gifts�����Ĵ�Сn���뷵���������Ľ�
��û�н���������һ�룬����0��
����������
[1,2,3,2,2],5
���أ�2
*/
class Gift {
public:
	int getValue(vector<int> gifts, int n) {
		// write code here
		sort(gifts.begin(), gifts.end());

		int money = gifts[n / 2];
		int moneycount = count(gifts.begin(), gifts.end(), money);

		if (moneycount > n / 2)
			return money;

		return 0;
	}
};

class Gift1{
public:
	int getValue(vector<int> gifts, int n) {


	}

};