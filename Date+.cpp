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
	return *this;
}