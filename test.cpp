//ʹ��һ�������������ǳ�����ռ��ͷŶ�ε�����
//ǳ�������ŵ㣺Ч�ʸߣ���������ռ�
//дʱ������ǳ����+���ü���+���������д������ʱ���Ƿ���ҪΪ��ǰ����������Ŀռ�

class String
{
public:

	String(const char *str = "")
		:_pCount(new int(1))
	{
		//�ж�str�Ƿ�Ϊ�գ���������
		//assert(str);  //����һ�ַ���
		if (nullptr == str)
			str = "";

		_str = new char[strlen(str) + 1];   //��1��Ϊ�˱��桮\0��
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

	//��ֵ���������

	String& operator=(const String& s)
	{

		//�ж��ǲ����Լ����Լ���ֵ
		if (this != &s)
		{
			//�жϱ���ֵ�Ķ������Դ��û�к�����������
			if (0 == --(*_pCount) && _str)
			{
				delete _str;
				_str = nullptr;

				delete _pCount;
				_pCount = nullptr;
			}
			//��Ŀ������Դ������ͬһ��ռ��ͬһ��������
			_str = s._str;
			_pCount = s._pCount;

			//�ù���ļ�����+1
			++(*_pCount);
		}


	}

	char& operator[](size_t index)
	{

		//�ж��Ƿ��������������Դ
		if (*_pCount > 1)
		{
			//�����������������Դ����ҪΪ��ǰ���󴴽�һ�������Ŀռ�
			String str(_str);    //����һ����ʱ����
			this->Swap(str);     //����ʱ����͵�ǰ����������ݽ���
			//����ȥ��ǰ��������٣�this�е�_pCount��1
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
	//int _count = 0;    //������ֱ�Ӷ���һ�����������У���Ϊÿ�������ж���һ�ݣ�
	//static int _count;	 //����ÿ������ֻ�ܲ����Լ��ļ�������������Ҫһ����̬�ļ����������Ҳ�������⣬
	//��Ϊ��̬�ĳ�Ա��������������ֻ��һ�ݣ��ǹ���ģ��������ж����Դʱ���ͻ������Դй¶����
	int* _pCount;		 //��һ��ָ������ 

};

// int String::_count = 0;   //��̬���Ա����һ��Ҫ���������ʵ����������
