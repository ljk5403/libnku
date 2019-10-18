// Student.h
#ifndef _STUDENT_H
#define _STUDENT_H
#include <string>
using namespace std;
class Student	//学生类定义
{
public:
	void SetData(string strNo, string strName, int nScore)	// 设置学生信息
	{
		m_strNo = strNo;
		m_strName = strName;
		m_nScore = nScore;
	}
	string& GetNo() { return m_strNo; }		// 获取学号
	string& GetName() { return m_strName; }	// 获取姓名
	int& GetScore() { return m_nScore; }		// 获取成绩
	static inline int CompareName(Student& s1, Student& s2)// 按姓名比较
	{
		if (s1.m_strName == s2.m_strName)
			return 0;
		if (s1.m_strName > s2.m_strName)
			return 1;
		return -1;
	}
private:
	string m_strNo;	// 学号
	string m_strName;	// 姓名
	int m_nScore;		// 成绩
};
// 重载<<运算符，输出学生信息
ostream& operator<<(ostream& out, Student &stu)
{
	out<<stu.GetNo()<<'\t'<<stu.GetName()<<'\t'<<stu.GetScore();
	return out;
}
#endif	// end of _STUDENT_H
