// Word.h
#ifndef	_WORD_H
#define	_WORD_H
#include <string>
using namespace std;
class Word
{
public:
	Word(char cEngLetter=' ', string strChinese="")
	{
		m_cEngLetter = cEngLetter;
		m_strChinese = strChinese;
	}
	friend void AddWordToDictionary(LinkedBinTree<Word> *pTree, string strEnglish, string strChinese);
	friend string SearchWordFromDictionary(LinkedBinTree<Word> *pTree, string strEnglish);
private:
	char m_cEngLetter;
	string m_strChinese;
};
#endif	// end of _WORD_H
