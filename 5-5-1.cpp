#if 0

#include<iostream>
using namespace std;

#include<assert.h>


class Date
{
public:
	//���캯��
	Date(int year = 1990, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		, _day(day)
	{}
	//�������캯��
	Date(const Date& d)
	{
		_year  = d._year;
		_month = d._month;
		_day   = d._day;
	}

	//�ж��Ƿ�������
	bool IsLeapyear()
	{
		if (!((_year % 4 && !(_year % 100)) || _year % 400))
			return true;
		else
			return false;
	}

	//�ж���Ч����
	bool IsInvalidDate()
	{
		if (_year > 0)
		{
			if (_month <= 12 && _month >0)
			{
				if (_month == 2)
				{
					if (IsLeapyear())
					{
						if (_day <= 29 && _day >= 1)
							return true;
						else
							return false;

					}
					else if (_day <= 28 && _day >= 1)
						return true;
					else
						return false;
				}
				else if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
				{
					if (_day <= 30 && _day >= 1)
						return true;
					else
						return false;
				}
				else if (_day <= 31 && _day >= 1)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}

	//��ֵ����������
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	//���������
	bool operator==(const Date& d)const
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}

	bool operator>(const Date& d)const
	{
		if (nullptr == &d)
			return false;
		if (_year == d._year)
		{
			if (_month == d._month)
			{
				return _day > d._day;
			}
			else
				return _month > d._month;
		}
		else
			return _year > d._year;
	}

	bool operator<(const Date& d)const
	{
		if (nullptr == &d)
			return false;
		if (_year == d._year)
		{
			if (_month == d._month)
			{
				return _day < d._day;
			}
			else
				return _month < d._month;
		}
		else
			return _year < d._year;
	}

	Date operator+(int days)
	{
		_day += days;
		while (!IsInvalidDate())
		{
			if (_month <= 12 && _month > 0)
			{
				if (_month == 2)
				{
					if (_day > 29 && IsLeapyear())
					{
						_month++;
						_day -= 29;
					}
					else
					{
						_month++;
						_day -= 28;
					}
				}
				else if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
				{
					if (_day > 30)
					{
						_month++;
						_day -= 30;
					}
				}
				else if (_day > 31)
				{
					_month++;
					_day -= 31;
				}
			}
			else
			{
				_month = 1;
				_year++;
			}
		}
		/*
		1.��_day+= days��Ȼ��Ը����ڽ����ж�
		2.�ȶ��·ݽ����ж�
			1.����·���2�£���Ҫ���ж�����ж��Ƿ�������
				1.���꣺_day�������29����Ҫ��λ
				��λ����_day -=29��_month+1����Ҫ��װһ�����ڵĽ�λ������
				2.�����꣺_day�������28����Ҫ��λ
				��λ����_day -=29��_month+1
			2.�����2��4��6��9��11����Ҫ�ж��Ƿ��λ���������Ƿ����30��
			3.������������·ݣ��ж��Ƿ��λ�����������Ƿ����31��
		*/
		return *this;
	}

#if 0
	Date operator-(int days)
	{
		_day -= days;
		while (!IsInvalidDate())
		{
			if (_month <= 12 && _month > 0)
			{
				if (_month == 2)
				{
					if (_day > 29 && IsLeapyear())
					{
						_month--;
						_day -= 29;
					}
					else
					{
						_month++;
						_day -= 28;
					}
				}
				else if (_month == 4 || _month == 6 || _month == 9 || _month == 11)
				{
					if (_day > 30)
					{
						_month++;
						_day -= 30;
					}
				}
				else if (_day > 31)
				{
					_month++;
					_day -= 31;
				}
			}
			else
			{
				_month = 1;
				_year++;
			}
		}
		
		return *this;
	}
#endif
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	


private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2000, 3, 29);
	Date d2(2016, 12, 11);
	
	d1 = d1 + 62;
	if (d2 > d1)
		cout << "d2��" << endl;
	else if (d2 < d1)
		cout << "d1��" << endl;
	
	if (d1.IsInvalidDate())
		cout << "�ǺϷ�" << endl;
	else
		cout << "���ǺϷ�" << endl;
		
	
	
	return 0;
}

/*

class Date
{
public:
Date(int year = 1900, int month = 1, int day = 1)
: _year(year)
, _month(month)
, _day(day)
{
if (!IsInvalidDate())
{
_year = 1900;
_month = 1;
_day = 1;
}
}

// 2018 11 1 + 100
Date operator+(int days);
// 2018 11 4 - 100 = 2018 11 -94
// 2018 11 4 - ��-100�� = 2018 11 4 + 100
Date operator-(int days);
Date& operator++();
Date operator++(int);
Date& operator--();
Date operator--(int);

// 2018 11 4
// 2019 1 1
int operator-(const Date& d);
bool operator==(const Date& d)const;
bool operator!=(const Date& d)const;
bool operator>(const Date& d)const;


private:
bool IsInvalidDate();
int _GetDaysOfMonth(int year, int month);
friend ostream& operator<<(ostream& _cout, const Date& d);
friend istream& operator>>(istream& _cin, Date& d);

private:
int _year;
int _month;
int _day;
};

*/

#endif