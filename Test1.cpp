#include<iostream>
using namespace std;

#include<vector>

#if 0
/*
���ӣ�https://www.nowcoder.com/questionTerminal/f094aed769d84cf3b799033c82fc1bf6
��Դ��ţ����

����ʵ��һ���򵥵��ַ����滻������
ԭ������Ҫ�滻��ռλ��Ϊ"%s",�밴�ղ����б��˳��һһ�滻ռλ����
�������б���ַ�������ռλ����������ʣ�µĲ����ַ���ӵ��ַ����Ľ�β��
����һ���ַ���A��ͬʱ�������ĳ���n�������ַ�����arg���뷵���滻����ַ�����
��֤�����������ڵ���ռλ����������֤ԭ���ɴ�СдӢ����ĸ��ɣ�ͬʱ����С�ڵ���500��

����������
"A%sC%sE",7,['B','D','F']
���أ�"ABCDEF"
*/
class StringFormat {
public:
	string formatString(string A, int n, vector<char> arg, int m) {
		// write code here
		string ret;
		int flag = 0;
		for (size_t i = 0; i < A.size(); ++i)
		{
			if (A[i] == '%' && A[i + 1] == 's')
			{
				ret += arg[flag++];              //��arg�е�����+��ret�У�������ֱ�����±�ķ�ʽ�����ʻ����,��Ϊ�ռ�û�и�
				i++;
			}
			else
				ret += A[i];
		}

		for (; flag < m; ++flag)              //�������б���ַ����Ƿ����ռλ�����������ҽ�ʣ�µĲ����ַ���ӵ��ַ����Ľ�β
			ret += arg[flag];


		return ret;
	}
};

#endif

class StringFormat {
public:
	string formatString(string A, int n, vector<char> arg, int m)
	{

	}
};
