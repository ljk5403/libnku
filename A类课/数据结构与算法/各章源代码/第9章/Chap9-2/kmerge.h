// kmerge.h
#ifndef _KMERGE_H
#define _KMERGE_H
#include <fstream>
using namespace std;
// K路归并
// strFileName数组中前K个元素（strFileName[0], strFileName[1], ..., strFileName[K-1]）
// 是待归并的文件名，第K+1个元素（strFileName[K]）是归并后得到的文件
// minRecord和maxRecord中分别存储记录不可能达到的最小值和最大值
template <class T>
void KMerge(string strFileName[], int K, T &minRecord, T &maxRecord)
{
	int nI;
	ifstream *pIn = new ifstream[K];
	ofstream out;
	T *pRecord = new T[K+1];//存放败者树上的K个叶子，pRecord[K]保存一个最小值
	int *pnLoser = new int[K];// 存放败者树上的分支结点（pnLoser[0]中保存的是胜者）
	for (nI=0; nI<K; nI++)	// 打开待归并的K个文件并读取第一条记录
	{
		pIn[nI].open(strFileName[nI].c_str());	// 打开文件
		pIn[nI]>>pRecord[nI];	// 读取记录
		if (pIn[nI].eof())
			pRecord[nI] = maxRecord;
	}
	out.open(strFileName[K].c_str());	// 打开归并结果文件
		// 创建败者树
	for (nI=0; nI<K; nI++)	// 初始化败者树
		pnLoser[nI] = K;
	// pRecord[K]为记录不可能达到的最小值，这样经过K轮调整，可以将K个文件的
	// 第一个记录作为败者树的K个叶子结点
	pRecord[K] = minRecord;
	for (nI=K-1; nI>=0; nI--)	// 从pRecord[K-1]到pRecord[0]调整形成败者树
		Adjust(pRecord, pnLoser, K, nI);
	// 从败者树中取出胜者（即pnLoser[0]）
	while (pRecord[pnLoser[0]]!=maxRecord)	// 若取出的胜者等于不可能达到的最大
										// 值，则说明归并排序已结束
	{
		out<<pRecord[pnLoser[0]];	// 将胜者记录输出到文件中
		pIn[pnLoser[0]]>>pRecord[pnLoser[0]];	//从胜者所在文件中读取下一条记录
		if (pIn[pnLoser[0]].eof())	// 若文件中已无记录，则将其赋值为待排序记录不
									// 可能达到的最大值，即在后继败者树重构过程中
									// 永远作为败者
			pRecord[pnLoser[0]] = maxRecord;
		Adjust(pRecord, pnLoser, K, pnLoser[0]);	// 重新调整败者树
	}
	for (nI=0; nI<K; nI++)	// 关闭K个待合并的文件
		pIn[nI].close();	// 关闭文件
	out.close();	// 关闭合并结果文件
	delete []pnLoser;
	delete []pRecord;
	delete []pIn;
}

// 调整败者树
template <class T>
void Adjust(T *pRecord, int *pnLoser, int K, int nQ)
{
	int nTemp;
	int nT = (K+nQ)/2;	// pnLoser[nT]是nQ的双亲结点
	while (nT !=0 )
	{
		// 若nQ结点中的记录大于pnLoser[nT]结点中的记录，则将nQ结点设置为败
		// 者，并将nQ的值置为这一轮比较的胜者（即原分支结点中存储的败者），
		// nQ一直用来存储胜者，退出循环后nQ为这一轮的胜者（即pRecord[nQ]为
		// 这一轮的最小值）
		if (pRecord[pnLoser[nT]] < pRecord[nQ])
		{
			nTemp = pnLoser[nT]; pnLoser[nT] = nQ; nQ = nTemp;
		}
		nT /= 2;
	}
	pnLoser[0] = nQ;
}
#endif	// end of _KMERGE_H
