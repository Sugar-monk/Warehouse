#include<iostream>
using namespace std;


/*
汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
是不是很简单？OK，搞定它！
*/



class Solution1 {
public:
	string LeftRotateString(string str, int n) {
		if (n < 0)
			return NULL;
		if (n == 0)
			return str;

		string tmp = "";
		tmp = str.substr(0, n);        ///将str中的字符从0开始n结束的字符串赋值到tmp中
		str.erase(0, n);               ///将str的前n个字符串擦除
		str += tmp;					   ///将str与tmp相加

		return str;

	}
};

//编写一个函数，其作用是将输入的字符串反转过来。


class Solution2 {
public:
	string reverseString(string s) {

		if (s.empty())
			return s;

		size_t begin = 0;
		size_t end = s.size() - 1;

		while (begin < end)
			swap(s[begin++], s[end--]);

		return s;
	}
};
