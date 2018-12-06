#include<iostream>
using namespace std;

#include<string>

/*
����һ���ַ������ҵ����ĵ�һ�����ظ����ַ�������������������
��������ڣ��򷵻� -1��

*/

class Solution {
public:
	int firstUniqChar(string s) {

		if (s.empty())
			return -1;

		int count[256] = { 0 };

		for (size_t i = 0; i < s.size(); ++i)
		{
			count[s[i]]++;				//���ַ������ַ����ֵĴ���ͳ��
		}

		for (size_t i = 0; i < s.size(); ++i)		//�ҳ��ַ��г���һ�ε��ַ������������±�
		{
			if (1 == count[s[i]])
				return i;
		}

		return -1;
	}
};


/*
�����ַ������һ�����ʵĳ��ȣ������Կո������
��������:
һ���ַ������ǿգ�����С��5000��
�������:
����N�����һ�����ʵĳ��ȡ�   
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