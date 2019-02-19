#pragma once
#include <unordered_map>
#include <string>
#include <cppjieba/Jieba.hpp>
class TextSimilarity
{
public:
	typedef std::unordered_map<std::string, int> wordFreq;
	typedef std::unordered_set<std::string, int> wordSet;
	TextSimilarity(std::string);

	wordFreq getWordFreq(const char* file);			//获取词频
	std::string GBKToUTF8(std::string str);
	std::string Utf8ToGBk(std::string str);
private:

	//停用词表
	void getstopWrodTable(const char* stopWordsSet);

	//初始化jiaba为字符串类型
	std::string DICT;
	std::string DICT_PATH;
	std::string HMM_PATH;
	std::string USER_DICT_PATH;
	std::string IDF_PATH;
	std::string STOP_WORD_PATH;
	cppjieba::Jieba _jieba;

	wordSet _stopWordsSet;

};