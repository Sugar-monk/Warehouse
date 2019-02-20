#include "TextSimilarity.h"
#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <cppjieba/Jieba.hpp>
#include <algorithm>
#include <assert.h>
using namespace std;

TextSimilarity::TextSimilarity(string dict)			//��ʼ��Ŀ¼
	:DICT(dict)
	, DICT_PATH(dict + "/jieba.dict.utf8")
	, HMM_PATH(dict + "/hmm_model.utf8")
	, USER_DICT_PATH(dict + "/user.dict.utf8")
	, IDF_PATH(dict + "/idf.utf8")
	, STOP_WORD_PATH(dict + "/stop_words.utf8")
	, _jieba(DICT_PATH,
			 HMM_PATH,
			 USER_DICT_PATH,
			 IDF_PATH,
			 STOP_WORD_PATH)
	,MaxWordsNumber(10)
{
	getstopWrodTable(STOP_WORD_PATH.c_str());		//��ʼ��ͣ�ôʱ�
}

//��ȡ��Ƶ
TextSimilarity::wordFreq TextSimilarity::getWordFreq(const char* filename)
{
	ifstream fin(filename);		//����һ���ļ�
	
	if (!fin.is_open())		//ȷ���ļ��Ƿ񱻴�
	{
		cout << "open file" << endl;
		return wordFreq();		//����ļ�û�б��򿪣�����һ���յ�map���൱һû�ж�������
	}
	//��ʼ���ļ�
	string line;
	wordFreq wf;
	while (!fin.eof())
	{
		getline(fin, line);			//��ÿ�н��зִʴ�����������浽len��
		line = GBKToUTF8(line);		//��GBK��ʽת��ΪUTF8
		vector<string> words;		//������ŷִʽ��������
		//�Ե�ǰ�ı����зִ�
		_jieba.Cut(line, words, true);
		//ͳ�ƴ�Ƶ
		for (const auto& a : words)
		{
			if (_stopWordsSet.count(a))		//����Ƿ���ͣ�ôʱ��У�����ǽ����˴�ѭ��
				continue;
			else
			{
				if (wf.count(a))				//���������Ѿ����ڣ��ڴ����Ͻ���+1�����û�оͽ�������Ϊ1    
					wf[a]++;
				else
					wf[a] = 1;				
			}
		}
	}
	return wf;
}

//����ͣ�ôʱ�
void TextSimilarity::getstopWrodTable(const char* stopWordFile)
{
	ifstream fin(stopWordFile);   //��ͣ�ôʴ�
	if (!fin.is_open())
	{
		cout << "open file" << stopWordFile << "faile" << endl;		//�����ʧ�ܣ������ʾ��Ϣ
		return;
	}
	
	string line;		//��������ͣ�ôʱ������
	while (!fin.eof())	//��ͣ�ôʴ����line��
	{
		getline(fin, line);	
		_stopWordsSet.insert(line);
	}
	fin.close();		//�ر�ͣ�ô�

}
bool sortRevrse(pair<string, int> lift, pair<string, int> right)
{
	return lift.second > right.second;			//��pair�еĵڶ���Ԫ��������Ҳ����ͨ����Ƶ������
}

//�ؼ�������
vector<pair<string, int>> TextSimilarity::sortByValueReverse(TextSimilarity::wordFreq& wf)
{
	//����storֻ֧����������������Ҫ��map�е���Դ������vector�У�
	vector<pair<string, int>> wfvector(wf.begin(), wf.end());	
	sort(wfvector.begin(), wfvector.end(), sortRevrse);

	return wfvector;
}

//�������ļ���ȡ���ؼ��ʴ����һ��
void TextSimilarity::selectAimWords(vector<pair<string, int>>& wfvec, wordSet& wset)
{
	int len = wfvec.size();
	int size = len > MaxWordsNumber ? MaxWordsNumber : len;			//���ı����ݺ͹涨����ѡ�����ٵ�
	for (int i = 0; i < size; i++)
	{
		wset.insert(wfvec[i].first);								//����ֱ�Ӵ�ţ���Ϊwf������������ֻ��Ҫ��ŵ�һ��
	}
}

//������Ƶ����
vector<double> TextSimilarity::getOneHot(wordSet& wset, wordFreq& wf)
{
	//��������wset�е�ÿһ���ʣ����������ڸ��ı���Ƶ�У�����Ĵ�Ƶ�ŵ�vector�У�û�оͽ�0��Ϊ��Ƶ����ôζ�Ӧ��λ��
	vector<double> oneHot;
	for (const auto& a : wset)
	{
		if (wf.count(a))
			oneHot.push_back(wf[a]);
		else 
			oneHot.push_back(0);
	}
	return oneHot;
}

//��Ƶ�������ƶ�
double TextSimilarity::cosine(vector<double> oneHot1, vector<double> oneHot2)
{
	double modular1 = 0;		//ģ
	double modular2 = 0;
	double products;			//���
	assert(oneHot1.size() == oneHot2.size());
	for (int i = 0; i < oneHot1.size(); i++)
	{
		products = +oneHot1[i] * oneHot2[i];
	}

	for (int i = 0; i < oneHot1.size(); i++)
	{
		modular1 += pow(oneHot1[i], 2);
	}
	for (int i = 0; i < oneHot1.size(); i++)
	{
		modular2 += pow(oneHot2[i], 2);
	}
	modular1 = pow(modular1, 0.5);
	modular2 = pow(modular2, 0.5);

	return products/(modular1*modular2);
}


//��GBK��ʽת��ΪUTF8
string TextSimilarity::GBKToUTF8(string str)
{
	//��GBKת��ΪUTF16
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);		//��ȡbuffer�Ĵ�С	
	wchar_t* wstr = new wchar_t[len];				//wchar_t ���ַ�		//�����������ʽת��ΪUTF16�����ʽ
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, wstr, len);
	//��UTF16ת��ΪUTF8
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);	//��ȡbuffer�Ĵ�С
	char* Utf8Str = new char[len];
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, Utf8Str, len, NULL, NULL);	//��UTF16�����ʽת��Ϊ���������ʽ
	string out(Utf8Str);

	//�ͷſռ䣬��������Ұָ������
	if (wstr)
	{
		delete[] wstr;
		wstr = NULL;
	}
	if (Utf8Str)
	{
		delete[] Utf8Str;
		Utf8Str = NULL;
	}

	return out;
}

string  TextSimilarity::Utf8ToGBk(string str)
{
	//��UTF8ת����UTF16
	int len = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);  //��ȡbuffer�Ĵ�С
	wchar_t* wstr = new wchar_t[len];
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, wstr, len);			//��UTF8�����ʽת��ΪUTF16�����ʽ

	//��UTF16ת��ΪGBK
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);		//��ȡbuffer�Ĵ�С
	char* GbkStr = new char[len];
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, GbkStr, len, NULL, NULL);		//��UTF16�����ʽת��ΪGBK�����ʽ
	string out(GbkStr);

	//�ͷſռ䣬��������Ұָ������
	if (wstr)
	{
		delete[] wstr;
		wstr = NULL;
	}
	if (GbkStr)
	{
		delete[] GbkStr;
		GbkStr = NULL;
	}

	return out;
}