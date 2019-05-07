#include<iostream>
using namespace std;

class Solution {
public:
	void replaceSpace(char *str, int length) {
		if (str == NULL && length <= 0)
			return;
		//����ǿ�ֱ�ӷ���

		int factlength = 0;
		//ʵ���ַ���
		int spacenumber = 0;
		//�ַ����пո������
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

		//��չ�ڶ����ַ���,
		//�ո������*2����Ϊ��%20��һ�������ַ�����Ҫ��ԭ��ÿ���ո��λ���ټ��������ַ��ĳ��ȣ����ǵڶ����ַ�����
		int newlength = factlength + spacenumber * 2;

		if (newlength > length)
		{
			return;
		}

		//�Ӻ���ǰ�滻������������滻�Ĵ���
		char *pStr1 = str + factlength;
		char *pStr2 = str + newlength;
		//���pStr2 <= pStr1 �ˣ�˵��ʣ�µ�pStr2��pStr1���ַ�����ͬ�ˣ�Ҳ��û�С� ���ˣ��Ͳ����滻��
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