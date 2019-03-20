#pragma once
#include <unordered_map>
#include <string>
#include <cppjieba/Jieba.hpp>
class TextSimilarity
{
public:
	typedef std::unordered_map<std::string, int> wordFreq;
	typedef std::unordered_set<std::string> wordSet;
	TextSimilarity(std::string);

	wordFreq getWordFreq(const char* file);			//��ȡ��Ƶ
	std::string GBKToUTF8(std::string str);			//����ת��
	std::string Utf8ToGBk(std::string str);
	std::vector<std::pair<std::string, int>> sortByValueReverse(TextSimilarity::wordFreq& wf);					//�ִ�����
	void selectAimWords(std::vector<std::pair<std::string, int>>& wfvec, wordSet& wset);		//���ؼ��ʴ�ŵ�set�У���Ϊset���Զ�ȡ��
	std::vector<double> getOneHot(wordSet& wset, wordFreq& wf);//��Ҫset�еĴʻ㣬��Ҫmap�еĴ�Ƶ
	double cosine(std::vector<double> oneHot1, std::vector<double> oneHot2);
	
private:

	void getstopWrodTable(const char* stopWordsSet);						//ͣ�ôʱ�
	//void selectAimWords(std::vector<std::pair<std::string, int>>& wfvec, wordSet wset);		//���ؼ��ʴ�ŵ�set�У���Ϊset���Զ�ȡ��
	//std::vector<int> getOneHot(wordSet& wset, wordFreq wf);//��Ҫset�еĴʻ㣬��Ҫmap�еĴ�Ƶ
	
	//��ʼ��jiabaΪ�ַ�������
	std::string DICT;
	std::string DICT_PATH;
	std::string HMM_PATH;
	std::string USER_DICT_PATH;
	std::string IDF_PATH;
	std::string STOP_WORD_PATH;
	cppjieba::Jieba _jieba;

	wordSet _stopWordsSet;							//����ͣ�ôʱ�
	int MaxWordsNumber;								//��������ѡ��

};