#include<iostream>
using namespace std;

#include<vector>

#if 0
/*
链接：https://www.nowcoder.com/questionTerminal/f094aed769d84cf3b799033c82fc1bf6
来源：牛客网

请你实现一个简单的字符串替换函数。
原串中需要替换的占位符为"%s",请按照参数列表的顺序一一替换占位符。
若参数列表的字符数大于占位符个数。则将剩下的参数字符添加到字符串的结尾。
给定一个字符串A，同时给定它的长度n及参数字符数组arg，请返回替换后的字符串。
保证参数个数大于等于占位符个数。保证原串由大小写英文字母组成，同时长度小于等于500。

测试样例：
"A%sC%sE",7,['B','D','F']
返回："ABCDEF"
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
				ret += arg[flag++];              //将arg中的内容+到ret中，如果如果直接用下表的方式来访问会崩溃,因为空间没有给
				i++;
			}
			else
				ret += A[i];
		}

		for (; flag < m; ++flag)              //检测参数列表的字符数是否大于占位符个数。并且将剩下的参数字符添加到字符串的结尾
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
