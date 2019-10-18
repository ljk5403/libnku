/* Chap5_4.cpp�����Ӵʵ�Ӧ�ó���*/
#include "LinkedBinTree.h"
#include "Word.h"
#include <iostream>
using namespace std;
// ��Ӣ�ĵ��ʼ������Ľ�����ӵ��ʵ���
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
		// ���ڵ����е�ÿ���ַ����ӵ�һ�����ӽ�㿪ʼ���ң�ֱ���ҵ�ƥ�����
		// ���к��Ӷ��Ƚ����
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
		// �����ǰ�ַ�û���ҵ�ƥ��Ľ�㣬�򽫵�ǰ�ַ�������ַ�����ӵ�����
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
			// ���һ���ַ�����Ӧ�Ľ��洢�õ��ʵ����Ľ���
			word.m_cEngLetter = strEnglish[nJ];
			word.m_strChinese = strChinese;
			if (pPreSiblingNode)
				pTree->InsertRightChild(pPreSiblingNode, word);
			else
				pTree->InsertLeftChild(pPreLevelNode, word);
			break;
		}
	}
	// �����ƥ���ϣ����������е������ַ������ҵ�ƥ��Ľ�㣬��ʱ�������һ��
	// �ַ�ƥ��Ľ���д洢�õ��ʵ����Ľ���
	if (nI==(int)strEnglish.length())
	{
		word.m_strChinese = strChinese;
		pTree->ModifyNodeValue(pPreLevelNode, word);
	}
}
// �����û������Ӣ�ĵ��ʲ������Ӧ�����Ľ���
string SearchWordFromDictionary(LinkedBinTree<Word> *pTree, string strEnglish)
{
	string strChinese = "";
	LinkedNode<Word> *pNode=pTree->GetRoot();
	int nI;
	Word word;
	// ���û�����ĵ�������ַ������д洢���ַ��Ƚ�
	for (nI=0; nI<(int)strEnglish.length(); nI++)
	{
		// �������һ�αȽ���û���ҵ�ƥ��Ľ�㣬��Ҫ���ҵĵ��ʲ�����
		if (pNode==NULL)
			break;
		// ��ȡ��һ�����ӽ��
		pNode = pTree->GetLeftChild(pNode);
		// �ӵ�һ�����ӽ�㿪ʼ��strEnglish[nI]�Ƚϣ�ֱ���ҵ�ƥ��Ľ���������
		// ���ӽ�㶼�Ƚ����
		while (pNode)
		{
			pTree->GetNodeValue(pNode, word);
			if (word.m_cEngLetter == strEnglish[nI])
				break;
			pNode = pTree->GetRightChild(pNode);
		}
	}
	// ��������е������ַ������ҵ�ƥ��Ľ�㣬����ҳɹ��������ƥ�����д�
	// �������Ľ��͸���strChinese��Ϊ����ֵ
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

	// ��������㣬������в��洢�κ�����
	btree.CreateRoot(word);
	while (1)
	{
		cout<<"�Ƿ�����µ��ʵ��ʵ��У�(y/n)";
		cin>>cAnswer;
		if (cAnswer == 'n')
			break;
		cout<<"������Ӣ�ĵ��ʣ�";
		cin>>strEnglish;
		cout<<"���������Ľ��ͣ�";
		cin>>strChinese;
		AddWordToDictionary(&btree, strEnglish, strChinese);
	}
	while (1)
	{
		cout<<"�Ƿ�Ҫ��ѯ���ʣ�(y/n)";
		cin>>cAnswer;
		if (cAnswer == 'n')
			break;
		cout<<"������Ҫ��ѯ��Ӣ�ĵ��ʣ�";
		cin>>strEnglish;
		strChinese = SearchWordFromDictionary(&btree, strEnglish);
		if (strChinese != "")
			cout<<"Ӣ�ĵ���"<<strEnglish<<"�����Ľ���Ϊ��"<<strChinese<<endl;
		else
			cout<<"Ӣ�ĵ���"<<strEnglish<<"�����ڣ�"<<endl;
	}
	return 0;
}
