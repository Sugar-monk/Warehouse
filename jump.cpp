#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/*
һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
�����������һ��n����̨���ܹ��ж�����������
*/

class Solution{
public:
	int jumpFloorII(int number){

		if (number == 1)
			return 1;
		return 2 * jumpFloorII(number - 1);
	}

};
