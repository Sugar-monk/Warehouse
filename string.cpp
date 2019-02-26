#include<iostream>
using namespace std;


class String
{
public:
	String(const char* str = "")
	{
		//Éî¿½±´
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)
	{
		_str = new char[strlen(s._str) + 1];
		strcpy(_str, s._str);
	}

	String& operator= (const String& s)
	{
		if (this != &s)
		{
			char* pTmp = new char[strlen(s._str) + 1];
			strcpy(pTmp, s._str);
			delete[] _str;
			_str = pTmp;
		}
		return *this;
	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};