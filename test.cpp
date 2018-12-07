//使用一个计数器来解决浅拷贝空间释放多次的问题
//浅拷贝的优点：效率高，不用申请空间
//写时拷贝：浅拷贝+引用计数+在向对象中写入内容时，是否需要为当前对象给独立的空间

class String
{
public:

	String(const char *str = "")
		:_pCount(new int(1))
	{
		//判断str是否为空，并做处理
		//assert(str);  //其中一种方法
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];   //加1是为了保存‘\0’
		strcpy(_str, str);
		//_count = 1;
	}

	String(String& s)
		:_str(s._str)
		, _pCount(s._pCount)
	{
		//_str = s._str;
		//++_count; 

		++(*_pCount);
	}

	//赋值运算符重载

	String& operator=(const String& s)
	{

		//判断是不是自己给自己赋值
		if (this != &s)
		{
			//判断被赋值的对象的资源有没有和其他对象共享
			if (0 == --(*_pCount) && _str)
			{
				delete _str;
				_str = nullptr;

				delete _pCount;
				_pCount = nullptr;
			}
			//让目标对象和源对象共享同一块空间和同一个计数器
			_str = s._str;
			_pCount = s._pCount;

			//让共享的计数器+1
			++(*_pCount);
		}


	}

	char& operator[](size_t index)
	{

		//判断是否和其他对象共享资源
		if (*_pCount > 1)
		{
			//如果和其他对象共享资源，则要为当前对象创建一个独立的空间
			String str(_str);    //创建一个临时对象
			this->Swap(str);     //用临时对象和当前对象进行内容交换
			//跳出去当前对象会销毁，this中的_pCount减1
		}

		return _str[index];
	}


	void Swap(String& s)
	{
		swap(_str, s._str);
		swap(_pCount, s._pCount);
	}

	~String()
	{
		if (0 == --(*_pCount) && _str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
	//int _count = 0;    //在类中直接定义一个计数器不行，因为每个对象中都有一份，
	//static int _count;	 //并且每个对象只能操作自己的计数器，所以需要一个静态的计数器来完成也存在问题，
	//因为静态的成员变量在整个类中只有一份，是共享的，当类中有多分资源时，就会造成资源泄露问题
	int* _pCount;		 //给一个指针类型 

};

// int String::_count = 0;   //静态测成员变量一定要在类外进行实例化、定义
