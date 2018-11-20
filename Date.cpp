class Date
{
public:
	bool IsLeapyear()
	{
		if (!((_year % 4 && !(_year % 100)) || _year % 400))
			return true;
		else
			return false;
	}
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
				else if (_month == 4 && _month == 6 && _month == 9 && _month == 11)
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

private:
	int _year;
	int _month;
	int _day;
};