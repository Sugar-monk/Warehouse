#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/*
��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
��������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}��
��������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2��
��������������0��
*/

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {

		sort(numbers.begin(), numbers.end());
		int tmp = numbers[(numbers.size()) / 2];
		int Count = count(numbers.begin(), numbers.end(), tmp);

		if (Count > (numbers.size()) / 2)
			return tmp;
		return 0;
	}
};