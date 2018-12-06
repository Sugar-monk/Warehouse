#include<string>
using namespace std;

/*
���������ַ�����ʽ�ķǸ����� num1 ��num2 ���������ǵĺ͡�

ע�⣺
1��num1 ��num2 �ĳ��ȶ�С�� 5100.
2��num1 ��num2 ��ֻ�������� 0-9.
3��num1 ��num2 ���������κ�ǰ���㡣
�㲻��ʹ���κ΃Ƚ� BigInteger �⣬ Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ��
*/

class Solution {
public:
	string addStrings(string num1, string num2) {

		if (num1.size() < num2.size())
			num1.swap(num2);
		size_t LSize = num1.size();
		size_t RSize = num2.size();

		//��������Ľ��
		string StrRet(LSize + 1, 0);
		//��Ž�λ
		int tmp = 0;
		for (size_t i = 0; i < LSize; ++i)
		{
			//����num1��num��ӵ�ֵ
			char Ret = num1[LSize - i - 1] - '0' + tmp;  //��ȥ0��Ϊ�˽��ַ�ת��������,����λtmp�ӵ�����

			if (i < RSize)
				Ret += num2[RSize - i - 1] - '0';
			tmp = 0;
			//�����λ����
			if (Ret > 9)
			{
				tmp = 1;
				Ret -= 10;
			}

			//��ʼ���汾����ӵĽ��
			StrRet[LSize - i] = Ret + '0';
		}

		//�ж��Ƿ��н�λ������н�λ������λ�ӵ���һ���ַ��ϣ����û�У�ɾ����һ���ַ�
		if (tmp)
			StrRet[0] = '1';
		else
			StrRet.erase(0, 1);

		return StrRet;
	}
};