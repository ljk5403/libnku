// Chap7_1.cpp
#include <iostream>
#include "Sort.h"
#include "Student.h"
using namespace std;
void DisplayStudentInfo(Student stu[], int nStuNum)
{
	int i;
	for (i=1; i<=nStuNum; i++)
		cout<<stu[i].m_strNo<<" "<<stu[i].m_strName
			<<" "<<stu[i].m_nScore<<endl;
}
int main()
{
	Student stu[7];
	stu[1].SetData("1102030", "���", 75);
	stu[2].SetData("1102035", "����", 70);
	stu[3].SetData("1102041", "����", 79);
	stu[4].SetData("1102023", "���", 65);
	stu[5].SetData("1102033", "�Ա�", 85);
	stu[6].SetData("1102045", "����", 75);
	int nStuNum = sizeof(stu)/sizeof(stu[0])-1;
	cout<<"ԭʼ����Ϊ��"<<endl;
	DisplayStudentInfo(stu, nStuNum);
	InsertSort(stu, nStuNum, Student::CompareScore);
	cout<<"���ɼ����������Ϊ��"<<endl;
	DisplayStudentInfo(stu, nStuNum);
	InsertSort(stu, nStuNum, Student::CompareName);
	cout<<"���������������Ϊ��"<<endl;
	DisplayStudentInfo(stu, nStuNum);
	InsertSort(stu, nStuNum, Student::CompareNo);
	cout<<"��ѧ�����������Ϊ��"<<endl;
	DisplayStudentInfo(stu, nStuNum);
	return 0;
}
