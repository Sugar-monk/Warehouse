#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	getline(cin, s);

	//��ת��������
	reverse(s.begin(), s.end());

	//��ʼ��תÿ������
	auto start = s.begin();
	while (start != s.end())		//���ַ����Ŀ�ʼ����β
	{
		auto end = start;			//��startλ�ÿ�ʼ�����������ո��ʾ�õ��ʽ���
		while (end != s.end() && *end != ' ')
			end++;

		reverse(start, end);		//��ת�������

		if (end != s.end())			//����Ƿ������һ�����ʵ�
			start = end + 1;
		else
			break;
	}

	cout << s << endl;

	return 0;
}