#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ret;		//�����򷵻�ֵ��ͬ���ͣ�

		ret.resize(numRows);			//����ռ䣬������һλ����
		//����0�кͶԽ����ϵ�����ȫ����1
		for (size_t i = 0; i < numRows; ++i)
		{
			ret[i].resize(i + 1);
			ret[i][0] = 1;
			ret[i][i] = 1;
		}

		//�ӵ����п�ʼ���
		for (size_t i = 2; i < numRows; i++)
		{
			for (size_t j = 1; j < i; ++j)
				ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
		}
		return ret;
	}
};