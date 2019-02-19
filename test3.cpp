#include "TextSimilarity.h"
#include <iostream>
using namespace std;

void textWordFreq()
{
	TextSimilarity ts("dict");
	TextSimilarity::wordFreq wf = ts.getWordFreq("text1");
	for (const auto& a : wf)
	{
		cout << ts.Utf8ToGBk(a.first) << ":" << a.second;
	}
	cout << endl;


}

int main()
{
	textWordFreq();
	return 0;
}