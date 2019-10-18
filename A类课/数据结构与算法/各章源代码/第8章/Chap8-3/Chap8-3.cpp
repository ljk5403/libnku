// Chap8_3.cpp
#include <iostream>
#include "SearchAlgorithms.h"
#include "IndexTable.h"
#include "Student.h"
// 定义哈希函数
int CYF11(const IndexTable<Student*, int> &it)
{
	return ((IndexTable<Student*, int>)it).GetKey()%11;
}
// 重载<<运算符，输出成绩索引表对象it所指向的学生信息
ostream& operator<<(ostream& out, IndexTable<Student*, int> &it)
{
	out<<*(it.GetElem());
	return out;
}
// 重载<<运算符，输出学号索引表对象it所指向的学生信息
ostream& operator<<(ostream& out, IndexTable<Student*, string> &it)
{
	out<<*(it.GetElem());
	return out;
}
int main()
{
	Student stu[7];
	// 设置学生信息
	stu[1].SetData("1102030", "李刚", 65);
	stu[2].SetData("1102035", "王涛", 92);
	stu[3].SetData("1102041", "吴明", 73);
	stu[4].SetData("1102023", "马洪", 85);
	stu[5].SetData("1102033", "赵冰", 90);
	stu[6].SetData("1102045", "陈立", 88);
	int nI, nStuNum = sizeof(stu)/sizeof(stu[0])-1; // 计算学生人数
	Student student; // 用于保存顺序查找的查找条件
	// 根据学生学号进行二叉排序树查找，查找成功则输出学生信息，否则输出“查找
	// 失败！”
	IndexTable<Student*, string> it1;
	LinkedBinTree<IndexTable<Student*, string>> btree;
	LinkedNode<IndexTable<Student*, string>> *pNode; 
	for (nI=1; nI<=nStuNum; nI++)	// 创建以二叉排序树形式存储的学号索引表
	{
		it1.SetData(&stu[nI], stu[nI].GetNo());
		InsertBST(btree, it1);
	}
	it1.SetData(NULL, "1102041");	// 设置查找条件
	// 根据查找条件在学号索引表中进行二叉排序树查找
	pNode = SearchBST(btree.GetRoot(), it1);
	if (pNode != NULL)	// 查找成功
	{
		btree.GetNodeValue(pNode, it1);
		cout<<it1<<endl;
	}
	else
		cout<<"查找失败！"<<endl;
	// 根据学生姓名进行顺序查找，查找成功则输出学生信息，否则输出“查找失败！”
	student.SetData("", "王涛", 0); 	// 设置查找条件
	// 根据查找条件进行顺序查找
	nI = SeqSearch(stu, nStuNum, student, Student::CompareName);
	if (nI != 0)	// 查找成功
		cout<<stu[nI]<<endl;
	else
		cout<<"查找失败！"<<endl;
	
	// 根据学生成绩构建索引表并进行哈希查找
	IndexTable<Student*, int> it2;
	HashTable<IndexTable<Student*, int>> hashtable(11, CYF11);
	for (nI=1; nI<=nStuNum; nI++)	// 创建以哈希表形式存储的成绩索引表
	{
	// 设置成绩索引表中每一个元素的值（包括指向学生地址的指针值和学生成绩
	// 值）
		it2.SetData(&stu[nI], stu[nI].GetScore());
		hashtable.InsertHashTable(it2);	// 将元素插入到哈希表中
	}
	// 设置查找用的给定值（即在成绩索引表中搜索成绩为88的元素）
	it2.SetData(NULL, 88);
	// 根据给定值进行哈希查找，查找成功则将查找结果it所指向的学生信息输出
	// 否则输出“查找失败！”
	if (hashtable.SearchHashTable(it2, it2))
		cout<<it2<<endl;
	else
		cout<<"查找失败！"<<endl;
	return 0;
}
