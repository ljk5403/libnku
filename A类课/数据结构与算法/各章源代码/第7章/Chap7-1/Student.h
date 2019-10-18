// Student.h
#ifndef _STUDENT_H
#define _STUDENT_H
#include <string>
using namespace std;
class Student
{
public:
	void SetData(string, string, int);	// 设置学生信息
	static inline int CompareNo(Student&, Student&);	// 按学号比较
	static inline int CompareName(Student&, Student&);// 按姓名比较
	static inline int CompareScore(Student&, Student&);// 按成绩比较
	friend void DisplayStudentInfo(Student stu[], int nStuNum);
private:
	string m_strNo;	// 学号
	string m_strName;	// 姓名
	int m_nScore;	// 成绩
};
void Student::SetData(string strNo, string strName, int nScore)
{
	m_strNo = strNo;
	m_strName = strName;
	m_nScore = nScore;
}
int Student::CompareNo(Student &s1, Student &s2)
{
	if (s1.m_strNo == s2.m_strNo)
		return 0;
	if (s1.m_strNo > s2.m_strNo)
		return 1;
	return -1;
}
int Student::CompareName(Student &s1, Student &s2)
{
	if (s1.m_strName == s2.m_strName)
		return 0;
	if (s1.m_strName > s2.m_strName)
		return 1;
	return -1;
}
int Student::CompareScore(Student &s1, Student &s2)
{
	if (s1.m_nScore == s2.m_nScore)
		return 0;
	if (s1.m_nScore > s2.m_nScore)
		return 1;
	return -1;
}
#endif	// end of _STUDENT_H
