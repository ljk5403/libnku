// kmerge.h
#ifndef _KMERGE_H
#define _KMERGE_H
#include <fstream>
using namespace std;
// K·�鲢
// strFileName������ǰK��Ԫ�أ�strFileName[0], strFileName[1], ..., strFileName[K-1]��
// �Ǵ��鲢���ļ�������K+1��Ԫ�أ�strFileName[K]���ǹ鲢��õ����ļ�
// minRecord��maxRecord�зֱ�洢��¼�����ܴﵽ����Сֵ�����ֵ
template <class T>
void KMerge(string strFileName[], int K, T &minRecord, T &maxRecord)
{
	int nI;
	ifstream *pIn = new ifstream[K];
	ofstream out;
	T *pRecord = new T[K+1];//��Ű������ϵ�K��Ҷ�ӣ�pRecord[K]����һ����Сֵ
	int *pnLoser = new int[K];// ��Ű������ϵķ�֧��㣨pnLoser[0]�б������ʤ�ߣ�
	for (nI=0; nI<K; nI++)	// �򿪴��鲢��K���ļ�����ȡ��һ����¼
	{
		pIn[nI].open(strFileName[nI].c_str());	// ���ļ�
		pIn[nI]>>pRecord[nI];	// ��ȡ��¼
		if (pIn[nI].eof())
			pRecord[nI] = maxRecord;
	}
	out.open(strFileName[K].c_str());	// �򿪹鲢����ļ�
		// ����������
	for (nI=0; nI<K; nI++)	// ��ʼ��������
		pnLoser[nI] = K;
	// pRecord[K]Ϊ��¼�����ܴﵽ����Сֵ����������K�ֵ��������Խ�K���ļ���
	// ��һ����¼��Ϊ��������K��Ҷ�ӽ��
	pRecord[K] = minRecord;
	for (nI=K-1; nI>=0; nI--)	// ��pRecord[K-1]��pRecord[0]�����γɰ�����
		Adjust(pRecord, pnLoser, K, nI);
	// �Ӱ�������ȡ��ʤ�ߣ���pnLoser[0]��
	while (pRecord[pnLoser[0]]!=maxRecord)	// ��ȡ����ʤ�ߵ��ڲ����ܴﵽ�����
										// ֵ����˵���鲢�����ѽ���
	{
		out<<pRecord[pnLoser[0]];	// ��ʤ�߼�¼������ļ���
		pIn[pnLoser[0]]>>pRecord[pnLoser[0]];	//��ʤ�������ļ��ж�ȡ��һ����¼
		if (pIn[pnLoser[0]].eof())	// ���ļ������޼�¼�����丳ֵΪ�������¼��
									// ���ܴﵽ�����ֵ�����ں�̰������ع�������
									// ��Զ��Ϊ����
			pRecord[pnLoser[0]] = maxRecord;
		Adjust(pRecord, pnLoser, K, pnLoser[0]);	// ���µ���������
	}
	for (nI=0; nI<K; nI++)	// �ر�K�����ϲ����ļ�
		pIn[nI].close();	// �ر��ļ�
	out.close();	// �رպϲ�����ļ�
	delete []pnLoser;
	delete []pRecord;
	delete []pIn;
}

// ����������
template <class T>
void Adjust(T *pRecord, int *pnLoser, int K, int nQ)
{
	int nTemp;
	int nT = (K+nQ)/2;	// pnLoser[nT]��nQ��˫�׽��
	while (nT !=0 )
	{
		// ��nQ����еļ�¼����pnLoser[nT]����еļ�¼����nQ�������Ϊ��
		// �ߣ�����nQ��ֵ��Ϊ��һ�ֱȽϵ�ʤ�ߣ���ԭ��֧����д洢�İ��ߣ���
		// nQһֱ�����洢ʤ�ߣ��˳�ѭ����nQΪ��һ�ֵ�ʤ�ߣ���pRecord[nQ]Ϊ
		// ��һ�ֵ���Сֵ��
		if (pRecord[pnLoser[nT]] < pRecord[nQ])
		{
			nTemp = pnLoser[nT]; pnLoser[nT] = nQ; nQ = nTemp;
		}
		nT /= 2;
	}
	pnLoser[0] = nQ;
}
#endif	// end of _KMERGE_H
