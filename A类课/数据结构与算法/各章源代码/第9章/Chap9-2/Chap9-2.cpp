// Chap9_2.cpp
#include "kmerge.h"
#include "Student.h"
#include "SortAlgorithms.h"	// ��7���д����������㷨ͷ�ļ�
const int g_nMaxRecordNum = 8;	// һ����������ദ��ļ�¼��
template <class T>
int SplitFile(const string &strInputFileName, int nMaxRecordNum, T &record);
int main()
{
	Student minStu, maxStu;
	string strInputFileName = "data.txt";	// �������ļ���
	string strOutputFileName = "sortdata.txt";	// ������ļ���
	string *pStrFileName;	// �������ļ�����������ļ���
	char cFileNo[10];	// ���ļ���ţ��ӿ�ʼ��
	int nI;
	// �������ļ�
	int nK = SplitFile(strInputFileName, g_nMaxRecordNum, minStu);
	pStrFileName = new string[nK+1];
	for (nI=0; nI<nK; nI++)	// �������ļ���
	{
		_itoa_s(nI, cFileNo, 10);
		pStrFileName[nI] = strInputFileName+cFileNo;
	}
	pStrFileName[nK] = strOutputFileName;	// ��������ļ���
	minStu.SetNo("00000000");	// ���ò����ܴﵽ����Сѧ��
	maxStu.SetNo("99999999");	// ���ò����ܴﵽ�����ѧ��
	KMerge(pStrFileName, nK, minStu, maxStu);	// ����K·�鲢����
	delete []pStrFileName;
	return 0;
}
	
// ���������ļ��ֳ��������ļ���ÿ�����ļ������nMaxRecordNum����¼��������
// �ɵ����ļ�����
template <class T>
int SplitFile(const string &strInputFileName, int nMaxRecordNum, T &record)
{
	int nI;	// ѭ����������
	int nK = 0;	// ���ɵ����ļ�����
	int nRecordNum = 0;	// ���ļ��е�ʵ�ʼ�¼��
	T *pRecord = new Student[nMaxRecordNum+1];	// ��������¼�������ڴ棬
// pRecord[0]��Ϊ������
	char cFileNo[10];	// ���ļ���ţ��ӿ�ʼ��
	ofstream outfile;
	ifstream infile(strInputFileName.c_str());	// �򿪴������ļ�
	if (!infile)
		return nK;
	while (1)
	{
		infile>>pRecord[nRecordNum+1];	// �Ӵ������ļ��ж�ȡ��¼
		if (infile.eof() || nRecordNum+1==nMaxRecordNum)	// ���ļ������޼�¼����
// �ﵽ����¼��
		{
			if (!infile.eof())	// ���ļ������м�¼�����¶�ȡ��¼��Ч
				nRecordNum++;
			if (nRecordNum != 0)	// ���м�¼��д�뵱ǰ�����ļ���
			{
				SelectSort(pRecord, nRecordNum);	// ѡ������
				_itoa_s(nK, cFileNo, 10);	// ������תΪ�ַ���
				// �����ļ�
				outfile.open((strInputFileName+cFileNo).c_str());
				for (nI=1; nI<=nRecordNum; nI++)//��������¼д�����ļ�
					outfile<<pRecord[nI];
				outfile.close();	// �ر����ļ�
				nK++;	// ���ļ�������
				nRecordNum = 0;	// д�����ļ��ļ�¼����0
			}
			if (infile.eof())	// ���ļ������޼�¼,���˳�ѭ��
				break;
		}
		else
			nRecordNum++;	// ��ǰ���ļ��ļ�¼����1
	}
	infile.close();	// �رմ������ļ�
	delete []pRecord;	// �ͷ��ڴ�
	return nK;
}
