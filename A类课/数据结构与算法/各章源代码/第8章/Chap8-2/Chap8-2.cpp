#include <iostream>
#include "SearchAlgorithms.h"
using namespace std;
// 定义哈希函数
int CYF11(const int& n)
{
	return n%11;
}
int main()
{
	int nR[] = {0, 43, 56, 37, 28, 17, 39, 22};
	int nSize=sizeof(nR)/sizeof(nR[0])-1;
	int nK=39, nX=0;
	HashTable<int> hashtable(11, CYF11);
	hashtable.CreateHashTable(nR, nSize);	// 创建哈希表
	hashtable.Display();	// 显示哈希表中的所有元素
	// 根据给定值nK进行哈希查找，查找结果保存在nX中
	if (hashtable.SearchHashTable(nK, nX)) 	// 查找成功
		cout<<"查找成功："<<nX<<endl;
	else
		cout<<"查找失败！"<<endl;
	return 0;
}
