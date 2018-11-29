#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret;		//定义域返回值相同类型；

		ret.resize(numRows);			//申请空间，先申请一位数组
		//将第0列和对角线上的数据全部置1
		for (size_t i = 0; i < numRows; ++i)
		{
			ret[i].resize(i + 1);
			ret[i][0] = 1;
			ret[i][i] = 1;
		}

		//从第三行开始填充
		for (size_t i = 2; i < numRows; i++)
		{
			for (size_t j = 1; j < i; ++j)
				ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
		}
		return ret;
	}
};