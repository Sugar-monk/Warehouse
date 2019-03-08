#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	getline(cin, s);

	//翻转整个句子
	reverse(s.begin(), s.end());

	//开始翻转每个单词
	auto start = s.begin();
	while (start != s.end())		//从字符串的开始到结尾
	{
		auto end = start;			//从start位置开始遍历，遇到空格表示该单词结束
		while (end != s.end() && *end != ' ')
			end++;

		reverse(start, end);		//翻转这个单词

		if (end != s.end())			//检测是否到了最后一个单词的
			start = end + 1;
		else
			break;
	}

	cout << s << endl;

	return 0;
}