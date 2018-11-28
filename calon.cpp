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
		if (year >= 1600 && month >= 1)  //(2018年1月1日星期一)
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

	//2.打印日历
	void PrintMonthCalen(int year = 1660, int month = 1)
	{
		int i = 0;  //用于控制行数
		int j = 0;	//用于控制列数
		int day = 1;
		Date d1(year, month, 1);	//生成一个日期
		int week = d1.Week(year, month);	//生成该月的第一天是星期几
		if (week != -1)
		{
			cout << year << "年" << endl << month << "月" << endl;		//打印标题
			cout << "★★★★★★★★★★★★★★★" << endl;	//打印分隔
			cout << "  日 " << " 一 " << " 二 " << " 三 " << " 四 " << " 五 " << " 六" << endl;
			for (j = 0; j < week; j++)
				printf("    ");
			for (i = 0; i < 6; i++)		//一个月的天数最多跨越六个星期
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