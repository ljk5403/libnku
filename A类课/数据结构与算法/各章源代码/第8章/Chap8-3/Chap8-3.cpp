// Chap8_3.cpp
#include <iostream>
#include "SearchAlgorithms.h"
#include "IndexTable.h"
#include "Student.h"
// �����ϣ����
int CYF11(const IndexTable<Student*, int> &it)
{
	return ((IndexTable<Student*, int>)it).GetKey()%11;
}
// ����<<�����������ɼ����������it��ָ���ѧ����Ϣ
ostream& operator<<(ostream& out, IndexTable<Student*, int> &it)
{
	out<<*(it.GetElem());
	return out;
}
// ����<<����������ѧ�����������it��ָ���ѧ����Ϣ
ostream& operator<<(ostream& out, IndexTable<Student*, string> &it)
{
	out<<*(it.GetElem());
	return out;
}
int main()
{
	Student stu[7];
	// ����ѧ����Ϣ
	stu[1].SetData("1102030", "���", 65);
	stu[2].SetData("1102035", "����", 92);
	stu[3].SetData("1102041", "����", 73);
	stu[4].SetData("1102023", "���", 85);
	stu[5].SetData("1102033", "�Ա�", 90);
	stu[6].SetData("1102045", "����", 88);
	int nI, nStuNum = sizeof(stu)/sizeof(stu[0])-1; // ����ѧ������
	Student student; // ���ڱ���˳����ҵĲ�������
	// ����ѧ��ѧ�Ž��ж������������ң����ҳɹ������ѧ����Ϣ���������������
	// ʧ�ܣ���
	IndexTable<Student*, string> it1;
	LinkedBinTree<IndexTable<Student*, string>> btree;
	LinkedNode<IndexTable<Student*, string>> *pNode; 
	for (nI=1; nI<=nStuNum; nI++)	// �����Զ�����������ʽ�洢��ѧ��������
	{
		it1.SetData(&stu[nI], stu[nI].GetNo());
		InsertBST(btree, it1);
	}
	it1.SetData(NULL, "1102041");	// ���ò�������
	// ���ݲ���������ѧ���������н��ж�������������
	pNode = SearchBST(btree.GetRoot(), it1);
	if (pNode != NULL)	// ���ҳɹ�
	{
		btree.GetNodeValue(pNode, it1);
		cout<<it1<<endl;
	}
	else
		cout<<"����ʧ�ܣ�"<<endl;
	// ����ѧ����������˳����ң����ҳɹ������ѧ����Ϣ���������������ʧ�ܣ���
	student.SetData("", "����", 0); 	// ���ò�������
	// ���ݲ�����������˳�����
	nI = SeqSearch(stu, nStuNum, student, Student::CompareName);
	if (nI != 0)	// ���ҳɹ�
		cout<<stu[nI]<<endl;
	else
		cout<<"����ʧ�ܣ�"<<endl;
	
	// ����ѧ���ɼ��������������й�ϣ����
	IndexTable<Student*, int> it2;
	HashTable<IndexTable<Student*, int>> hashtable(11, CYF11);
	for (nI=1; nI<=nStuNum; nI++)	// �����Թ�ϣ����ʽ�洢�ĳɼ�������
	{
	// ���óɼ���������ÿһ��Ԫ�ص�ֵ������ָ��ѧ����ַ��ָ��ֵ��ѧ���ɼ�
	// ֵ��
		it2.SetData(&stu[nI], stu[nI].GetScore());
		hashtable.InsertHashTable(it2);	// ��Ԫ�ز��뵽��ϣ����
	}
	// ���ò����õĸ���ֵ�����ڳɼ��������������ɼ�Ϊ88��Ԫ�أ�
	it2.SetData(NULL, 88);
	// ���ݸ���ֵ���й�ϣ���ң����ҳɹ��򽫲��ҽ��it��ָ���ѧ����Ϣ���
	// �������������ʧ�ܣ���
	if (hashtable.SearchHashTable(it2, it2))
		cout<<it2<<endl;
	else
		cout<<"����ʧ�ܣ�"<<endl;
	return 0;
}
