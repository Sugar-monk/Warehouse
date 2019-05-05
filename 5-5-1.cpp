#if 0

#include<iostream>
using namespace std;

#include<assert.h>


class Date
{
public:
	//构造函数
	Date(int year = 1990, int month = 1, int day = 1)
		:_year(year)
		,_month(month)
		, _day(day)
	{}
	//拷贝构造函数
	Date(const Date& d)
	{
		_year  = d._year;
		_month = d._month;
		_day   = d._day;
	}

	//判断是否是闰年
	bool IsLeapyear()
	{
		if (!((_year % 4 && !(_year % 100)) || _year % 400))
			return true;
		else
			return false;
	}

	//判断无效日期
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

	//赋值操作符重载
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

	//运算符重载
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
		1.让_day+= days，然后对该日期进行判断
		2.先对月份进行判断
			1.如果月份是2月，需要进行对年的判断是否是闰年
				1.闰年：_day如果大于29天需要进位
				进位：让_day -=29，_month+1（需要封装一个日期的进位函数）
				2.非闰年：_day如果大于28天需要进位
				进位：让_day -=29，_month+1
			2.如果是2、4、6、9、11，需要判断是否进位的条件是是否大于30天
			3.如果是其他的月份，判断是否进位的条件就是是否大于31天
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
		cout << "d2大" << endl;
	else if (d2 < d1)
		cout << "d1大" << endl;
	
	if (d1.IsInvalidDate())
		cout << "是合法" << endl;
	else
		cout << "不是合法" << endl;
		
	
	
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
// 2018 11 4 - （-100） = 2018 11 4 + 100
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