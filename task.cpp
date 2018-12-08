#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


class String
{
public:
typedef char* Iterator;

public:
	String(const char* str)
	{
		if (str)
			str = "";
		_size = strlen(str);
		_str = new char[_size + 1];
		_capacity = _size;

		strcpy(_str, str);
	}
	String(const char* str, size_t size)
	{
		if (str)
			str = "";
		_size = size;
		_str = new char[_size + 1];
		_capacity = _size;

		strncpy(_str, str, size);
	}
	String(const String& s)
		:_str(new char[s._capacity + 1])
		, _size(s._size)
		, _capacity(s._capacity)
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pStr = new char[s._capacity + 1];
			strcpy(pStr, _str);
			delete[] _str;
			_str = pStr;

			_size = s._size;
			_capacity = s._capacity;
		}

		return *this;

	}
	~String()
	{
		if (nullptr != _str)
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}
	}
	Iterator Begin()
	{
		return _str;
	}
	Iterator End()
	{
		return _str + _size;
	}
	Iterator RBegin()
	{
		return End();
	}
	Iterator REnd()
	{
		return Begin();
	}
	void PushBack(char c)
	{
		_str[_size++] = c;
		_str[_size] = '\0';
	}
	void Append(const char* str)
	{
		size_t len = strlen(str);
		if (len > _capacity - _size)
			Reserve(2*_capacity + len);
		strcat(_str, str);
	}

		//////////////////////////////////////////////
	char& operator[](size_t index)
	{
		return _str[index];
	}

	const char& operator[](size_t index)const
	{
		return _str[index];
	}
		

	///////////////////////////////////////////
	void ReSize(size_t newSize, char c)
	{
		if (newSize > _size)
		{
			/*方法一
			size_t size = _size;
			for (size_t i = 0; i < newSize; ++i)
			{
			pStr[size++] = c;
			}
			delete[] _str;
			_str = pStr;
			*/

			Reserve(newSize);
			memset(_str + _size, c, newSize - _size);
			_str[newSize] = '\0';
			_capacity = newSize;
		}
		else if (newSize < _size)
		{
			/*方法一
			char* pStr = new char[newSize + 1];
			for (size_t i = 0; i < newSize; ++i)
			{
			pStr[i] = _str[i];
			}
			delete[] _str;
			_str = pStr;
			*/
			memset(_str + newSize, '\0', 1);
		}
		_size = newSize;
	}
	void Reserve(size_t newCapacity)
	{
		if (_capacity <= newCapacity && _capacity != newCapacity)
		{
			char* pStr = new char[newCapacity + 1];
			strcpy(pStr, _str);
			delete[] _str;
			_str = pStr;
			_capacity = newCapacity;
		}
	}
	int Size()const
	{
		return _size;
	}
	bool Empty()const
	{
		return(_capacity == 0);
	}
	void Clear()
	{
		if (_str)
		{
			_str = nullptr;
			_size = 0;
		}
	}
	int Find(char c, size_t pos = 0)
	{
		for (size_t i = pos; i < _size; ++i)
		{
			if (_str[i] == c)
				return i;
		}
		
		return npos;
	}
	int rFind(char c)
	{
		for (size_t i = (_size - 1); i > 0; --i)
		{
			if (_str[i] == c)
				return i;
		}

		return npos;
	}
	const char* C_Str()const
	{
		return _str;
	}
	void Swap(String& s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}
	String StrSub(size_t pos, size_t size)
	{
		int len = strlen(_str + pos);     

		if (len < size)					
			size = len;
		return String(_str + pos, size);  
	}
	
	bool operator<(const String& s)
	{

		return !strcmp(_str, s._str);
	}
	bool operator<=(const String& s)
	{
		if (strcmp(_str, s._str) == 1)
			return npos;
		return 1;
	}
	bool operator>(const String& s)
	{
		return strcmp(_str, s._str);
	}
	bool operator>=(const String& s)
	{
		if (strcmp(_str, s._str) != 1)
			return npos;
		return 1;
	}
	bool operator==(const String& s)
	{
		return (strcmp(_str, s._str) == 0);
	}
	bool operator!=(const String& s)
	{
		return (strcmp(_str, s._str) != 0);
	}
	friend ostream& operator<<(ostream& _cout, const String& s)
	{
		_cout << s._str;

		return _cout;
	}
	friend istream& operator>>(istream& _cin, String& s)
	{
		_cin >> s._str;

		return _cin;
	}

	
private:
	char* _str;
	size_t _capacity;
	size_t _size;
	static int npos;
};

int String::npos = -1;

