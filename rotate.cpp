#include<iostream>
using namespace std;


/*
�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ�����ָ�����������
����һ���������ַ�����S���������ѭ������Kλ������������
���磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc����
�ǲ��Ǻܼ򵥣�OK���㶨����
*/



class Solution1 {
public:
	string LeftRotateString(string str, int n) {
		if (n < 0)
			return NULL;
		if (n == 0)
			return str;

		string tmp = "";
		tmp = str.substr(0, n);        ///��str�е��ַ���0��ʼn�������ַ�����ֵ��tmp��
		str.erase(0, n);               ///��str��ǰn���ַ�������
		str += tmp;					   ///��str��tmp���

		return str;

	}
};

//��дһ���������������ǽ�������ַ�����ת������


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
