#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/*
输入n个整数，找出其中最小的K个数。
例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
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