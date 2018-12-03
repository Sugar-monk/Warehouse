#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
如果不存在则输出0。
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