#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/*
����n���������ҳ�������С��K������
��������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��
*/
class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {

		vector<int> ret;

		if (k > input.size())
			return ret;

		sort(input.begin(), input.end());
		for (size_t i = 0; i < k; ++i)
			ret.push_back(input[i]);
		return ret;
	}
};