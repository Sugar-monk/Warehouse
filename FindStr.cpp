#include<iostream>
using namespace std;

#include<string>

/*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。
如果不存在，则返回 -1。

*/

class Solution {
public:
	int firstUniqChar(string s) {

		if (s.empty())
			return -1;

		int count[256] = { 0 };

		for (size_t i = 0; i < s.size(); ++i)
		{
			count[s[i]]++;				//将字符串中字符出现的次数统计
		}

		for (size_t i = 0; i < s.size(); ++i)		//找出字符中出现一次的字符，并返回其下标
		{
			if (1 == count[s[i]])
				return i;
		}

		return -1;
	}
};


/*
计算字符串最后一个单词的长度，单词以空格隔开。
输入描述:
一行字符串，非空，长度小于5000。
输出描述:
整数N，最后一个单词的长度。   
*/

#include<string>
#include<iostream>
using namespace std;

int main()
{
	string str;

	while (getline(cin, str))
	{
		cout << str.substr(str.rfind(' ') + 1).size() << endl;
	}

	return 0;
}