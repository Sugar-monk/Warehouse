#include<iostream>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL && length <= 0)
			return;
		//如果是空直接返回

		int factlength = 0;
		//实际字符数
		int spacenumber = 0;
		//字符串中空格的数量
		int i = 0;

		while (str[i] != '\0')
		{
			++factlength;
			if (str[i] == ' ')
			{
				++spacenumber;
			}
			++i;
		}

		//扩展第二个字符串,
		//空格的数量*2是因为“%20”一共三个字符，需要在原来每个空格的位置再加上两个字符的长度，才是第二个字符串的
		int newlength = factlength + spacenumber * 2;

		if (newlength > length)
		{
			return;
		}

		//从后向前替换，这样会减少替换的次数
		char *pStr1 = str + factlength;
		char *pStr2 = str + newlength;
		//如果pStr2 <= pStr1 了，说明剩下的pStr2和pStr1的字符串相同了，也就没有“ ”了，就不用替换了
		while (pStr2 > pStr1 && pStr1 >= 0)
		{
			if (*pStr1 == ' ')
			{
				*pStr2-- = '0';
				*pStr2-- = '2';
				*pStr2-- = '%';
			}
			else
			{
				*pStr2-- = *pStr1;
			}
			--pStr1;
		}
		return;
	}
};

int main()
{
	char str[256] = "holle word";
	Solution s;
	s.replaceSpace(str, 256);
	cout << str << endl;
	return 0;
}