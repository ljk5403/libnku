#ifndef _STUDENT_H
#define _STUDENT_H
#include <string>
using namespace std;
// ѧ����
class Student
{
	friend istream& operator>>(istream &in, Student &stu);
	friend ostream& operator<<(ostream &out, Student &stu);
public:
	Student() { m_strNo = m_strName = m_strMajor = ""; }	// ���캯��
	// <���������
	bool operator<(Student &stu) { return m_strNo<stu.m_strNo; }
	// ==���������
	bool operator==(Student &stu) { return m_strNo==stu.m_strNo; }
	// >���������
	bool operator>(Student &stu) { return m_strNo>stu.m_strNo; }
private:
	string m_strNo;	// ѧ��
	string m_strName;	// ����
	string m_strMajor;	// רҵ
};
// ��ȡ���������
istream& operator>>(istream &in, Student &stu)
{
	in>>stu.m_strNo>>stu.m_strName>>stu.m_strMajor;
	return in;
}
// �������������
ostream& operator<<(ostream &out, Student &stu)
{
	out<<stu.m_strNo<<' '
		<<stu.m_strName<<' '
		<<stu.m_strMajor<<endl;
	return out;
}
// ��ȡ���������
istream& operator>>(istream &in, TransRecord<Student> &trans)
{
	in>>trans.op>>trans.record;
	return in;
}
#endif	// end of _STUDENT_H
