#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year, int month, int day)
		:_year(year),
		_month(month),
		_day(day)
	{}
	int Week(int year, int month = 1)
	{
		int week = -1;
		if (year >= 1600 && month >= 1)  //(2018��1��1������һ)
		{
			week = 1;
			int days = 0;
			Date d1(2018, 1, 1);
			Date d2(year, month, 1);
			days = d2 - d1;
			week = (days % 7) + week;
		}

		return week;
	}

	//2.��ӡ����
	void PrintMonthCalen(int year = 1660, int month = 1)
	{
		int i = 0;  //���ڿ�������
		int j = 0;	//���ڿ�������
		int day = 1;
		Date d1(year, month, 1);	//����һ������
		int week = d1.Week(year, month);	//���ɸ��µĵ�һ�������ڼ�
		if (week != -1)
		{
			cout << year << "��" << endl << month << "��" << endl;		//��ӡ����
			cout << "����������������" << endl;	//��ӡ�ָ�
			cout << "  �� " << " һ " << " �� " << " �� " << " �� " << " �� " << " ��" << endl;
			for (j = 0; j < week; j++)
				printf("    ");
			for (i = 0; i < 6; i++)		//һ���µ���������Խ��������
			{
				for (j = week; j < 7; j++)
				{
					if (day <= d1._GetDaysOfMonth(year, month))
						printf("%4d", day++);
					else
						break;
				}
				week = 0;
				cout << endl;
			}
		}
	}
private:
	int _year;
	int _month;
	int _day;
};