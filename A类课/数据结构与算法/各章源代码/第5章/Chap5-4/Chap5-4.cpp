/* Chap5_4.cpp：电子词典应用程序*/
#include "LinkedBinTree.h"
#include "Word.h"
#include <iostream>
using namespace std;
// 将英文单词及其中文解释添加到词典中
void AddWordToDictionary(LinkedBinTree<Word> *pTree, string strEnglish, string strChinese)
{
	LinkedNode<Word> *pNode=pTree->GetRoot(), *pPreLevelNode=NULL, *pPreSiblingNode=NULL;
	int nI, nJ;
	bool bMatch;
	Word word;
	if (pNode==NULL)
		return;
	pPreLevelNode = pNode;
	pNode = pTree->GetLeftChild(pNode);
	for (nI=0; nI<(int)strEnglish.length(); nI++)
	{
		pPreSiblingNode = NULL;
		bMatch = false;
		// 对于单词中的每个字符，从第一个孩子结点开始查找，直到找到匹配结点或
		// 所有孩子都比较完毕
		while (pNode)
		{
			pTree->GetNodeValue(pNode, word);
			if (word.m_cEngLetter == strEnglish[nI])
			{
				pPreLevelNode = pNode;
				pNode = pTree->GetLeftChild(pNode);
				bMatch = true;
				break;
			}
			pPreSiblingNode = pNode;
			pNode = pTree->GetRightChild(pNode);
		}
		// 如果当前字符没有找到匹配的结点，则将当前字符及后继字符逐个加到树中
		if (!bMatch)
		{
			word.m_strChinese = "";
			for (nJ=nI; nJ<(int)strEnglish.length()-1; nJ++)
			{
				word.m_cEngLetter = strEnglish[nJ];
				if (pPreSiblingNode)
				{
					pTree->InsertRightChild(pPreSiblingNode, word);
					pPreLevelNode = pTree->GetRightChild(pPreSiblingNode);
					pPreSiblingNode = NULL;
				}
				else
				{
					pTree->InsertLeftChild(pPreLevelNode, word);
					pPreLevelNode = pTree->GetLeftChild(pPreLevelNode);
				}
			}
			// 最后一个字符所对应的结点存储该单词的中文解释
			word.m_cEngLetter = strEnglish[nJ];
			word.m_strChinese = strChinese;
			if (pPreSiblingNode)
				pTree->InsertRightChild(pPreSiblingNode, word);
			else
				pTree->InsertLeftChild(pPreLevelNode, word);
			break;
		}
	}
	// 如果都匹配上，表明单词中的所有字符都能找到匹配的结点，此时在与最后一个
	// 字符匹配的结点中存储该单词的中文解释
	if (nI==(int)strEnglish.length())
	{
		word.m_strChinese = strChinese;
		pTree->ModifyNodeValue(pPreLevelNode, word);
	}
}
// 根据用户输入的英文单词查找其对应的中文解释
string SearchWordFromDictionary(LinkedBinTree<Word> *pTree, string strEnglish)
{
	string strChinese = "";
	LinkedNode<Word> *pNode=pTree->GetRoot();
	int nI;
	Word word;
	// 将用户输入的单词逐个字符与结点中存储的字符比较
	for (nI=0; nI<(int)strEnglish.length(); nI++)
	{
		// 如果在上一次比较中没有找到匹配的结点，则要查找的单词不存在
		if (pNode==NULL)
			break;
		// 获取第一个孩子结点
		pNode = pTree->GetLeftChild(pNode);
		// 从第一个孩子结点开始与strEnglish[nI]比较，直到找到匹配的结点或者所有
		// 孩子结点都比较完毕
		while (pNode)
		{
			pTree->GetNodeValue(pNode, word);
			if (word.m_cEngLetter == strEnglish[nI])
				break;
			pNode = pTree->GetRightChild(pNode);
		}
	}
	// 如果单词中的所有字符都能找到匹配的结点，则查找成功，将最后匹配结点中存
	// 储的中文解释赋给strChinese作为返回值
	if (pNode!=NULL)
		strChinese = word.m_strChinese;
	return strChinese;
}
int main()
{
	LinkedBinTree<Word> btree;
	char cAnswer;
	string strEnglish, strChinese;
	Word word;

	// 创建根结点，根结点中不存储任何数据
	btree.CreateRoot(word);
	while (1)
	{
		cout<<"是否添加新单词到词典中？(y/n)";
		cin>>cAnswer;
		if (cAnswer == 'n')
			break;
		cout<<"请输入英文单词：";
		cin>>strEnglish;
		cout<<"请输入中文解释：";
		cin>>strChinese;
		AddWordToDictionary(&btree, strEnglish, strChinese);
	}
	while (1)
	{
		cout<<"是否要查询单词？(y/n)";
		cin>>cAnswer;
		if (cAnswer == 'n')
			break;
		cout<<"请输入要查询的英文单词：";
		cin>>strEnglish;
		strChinese = SearchWordFromDictionary(&btree, strEnglish);
		if (strChinese != "")
			cout<<"英文单词"<<strEnglish<<"的中文解释为："<<strChinese<<endl;
		else
			cout<<"英文单词"<<strEnglish<<"不存在！"<<endl;
	}
	return 0;
}
