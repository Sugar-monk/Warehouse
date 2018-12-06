#include<string>
using namespace std;

/*
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

注意：
1、num1 和num2 的长度都小于 5100.
2、num1 和num2 都只包含数字 0-9.
3、num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
*/

class Solution {
public:
	string addStrings(string num1, string num2) {

		if (num1.size() < num2.size())
			num1.swap(num2);
		size_t LSize = num1.size();
		size_t RSize = num2.size();

		//保存计算后的结果
		string StrRet(LSize + 1, 0);
		//存放进位
		int tmp = 0;
		for (size_t i = 0; i < LSize; ++i)
		{
			//计算num1与num相加的值
			char Ret = num1[LSize - i - 1] - '0' + tmp;  //减去0是为了将字符转换成数字,将进位tmp加到这里

			if (i < RSize)
				Ret += num2[RSize - i - 1] - '0';
			tmp = 0;
			//处理进位问题
			if (Ret > 9)
			{
				tmp = 1;
				Ret -= 10;
			}

			//开始保存本次相加的结果
			StrRet[LSize - i] = Ret + '0';
		}

		//判断是否有进位，如果有进位，将进位加到第一个字符上，如果没有，删除第一个字符
		if (tmp)
			StrRet[0] = '1';
		else
			StrRet.erase(0, 1);

		return StrRet;
	}
};