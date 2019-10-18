// Chap9_2.cpp
#include "kmerge.h"
#include "Student.h"
#include "SortAlgorithms.h"	// 第7章中创建的排序算法头文件
const int g_nMaxRecordNum = 8;	// 一次内排序最多处理的记录数
template <class T>
int SplitFile(const string &strInputFileName, int nMaxRecordNum, T &record);
int main()
{
	Student minStu, maxStu;
	string strInputFileName = "data.txt";	// 待排序文件名
	string strOutputFileName = "sortdata.txt";	// 排序后文件名
	string *pStrFileName;	// 保存子文件名和排序后文件名
	char cFileNo[10];	// 子文件编号（从开始）
	int nI;
	// 生成子文件
	int nK = SplitFile(strInputFileName, g_nMaxRecordNum, minStu);
	pStrFileName = new string[nK+1];
	for (nI=0; nI<nK; nI++)	// 设置子文件名
	{
		_itoa_s(nI, cFileNo, 10);
		pStrFileName[nI] = strInputFileName+cFileNo;
	}
	pStrFileName[nK] = strOutputFileName;	// 设置输出文件名
	minStu.SetNo("00000000");	// 设置不可能达到的最小学号
	maxStu.SetNo("99999999");	// 设置不可能达到的最大学号
	KMerge(pStrFileName, nK, minStu, maxStu);	// 进行K路归并排序
	delete []pStrFileName;
	return 0;
}
	
// 将待排序文件分成若干子文件，每个子文件中最多nMaxRecordNum个记录，返回生
// 成的子文件数量
template <class T>
int SplitFile(const string &strInputFileName, int nMaxRecordNum, T &record)
{
	int nI;	// 循环计数变量
	int nK = 0;	// 生成的子文件数量
	int nRecordNum = 0;	// 子文件中的实际记录数
	T *pRecord = new Student[nMaxRecordNum+1];	// 根据最大记录数分配内存，
// pRecord[0]作为监视哨
	char cFileNo[10];	// 子文件编号（从开始）
	ofstream outfile;
	ifstream infile(strInputFileName.c_str());	// 打开待排序文件
	if (!infile)
		return nK;
	while (1)
	{
		infile>>pRecord[nRecordNum+1];	// 从待排序文件中读取记录
		if (infile.eof() || nRecordNum+1==nMaxRecordNum)	// 若文件中已无记录或已
// 达到最大记录数
		{
			if (!infile.eof())	// 若文件中仍有记录，则新读取记录有效
				nRecordNum++;
			if (nRecordNum != 0)	// 若有记录需写入当前打开子文件中
			{
				SelectSort(pRecord, nRecordNum);	// 选择排序
				_itoa_s(nK, cFileNo, 10);	// 将数字转为字符串
				// 打开子文件
				outfile.open((strInputFileName+cFileNo).c_str());
				for (nI=1; nI<=nRecordNum; nI++)//将排序后记录写入子文件
					outfile<<pRecord[nI];
				outfile.close();	// 关闭子文件
				nK++;	// 子文件数量加
				nRecordNum = 0;	// 写入子文件的记录数清0
			}
			if (infile.eof())	// 若文件中已无记录,则退出循环
				break;
		}
		else
			nRecordNum++;	// 当前子文件的记录数增1
	}
	infile.close();	// 关闭待排序文件
	delete []pRecord;	// 释放内存
	return nK;
}
