#ifndef _STUDENT_H
#define _STUDENT_H
#include <string>
using namespace std;
// 学生类
class Student
{
	friend istream& operator>>(istream &in, Student &stu);
	friend ostream& operator<<(ostream &out, Student &stu);
public:
	Student() { m_strNo = m_strName = m_strMajor = ""; }	// 构造函数
	// <运算符重载
	bool operator<(Student &stu) { return m_strNo<stu.m_strNo; }
	// ==运算符重载
	bool operator==(Student &stu) { return m_strNo==stu.m_strNo; }
	// >运算符重载
	bool operator>(Student &stu) { return m_strNo>stu.m_strNo; }
private:
	string m_strNo;	// 学号
	string m_strName;	// 姓名
	string m_strMajor;	// 专业
};
// 提取运算符重载
istream& operator>>(istream &in, Student &stu)
{
	in>>stu.m_strNo>>stu.m_strName>>stu.m_strMajor;
	return in;
}
// 插入运算符重载
ostream& operator<<(ostream &out, Student &stu)
{
	out<<stu.m_strNo<<' '
		<<stu.m_strName<<' '
		<<stu.m_strMajor<<endl;
	return out;
}
// 提取运算符重载
istream& operator>>(istream &in, TransRecord<Student> &trans)
{
	in>>trans.op>>trans.record;
	return in;
}
#endif	// end of _STUDENT_H
