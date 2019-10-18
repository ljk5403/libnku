// Student.h
#ifndef _STUDENT_H
#define _STUDENT_H
#include <string>
using namespace std;
class Student	//ѧ���ඨ��
{
public:
	void SetData(string strNo, string strName, int nScore)	// ����ѧ����Ϣ
	{
		m_strNo = strNo;
		m_strName = strName;
		m_nScore = nScore;
	}
	string& GetNo() { return m_strNo; }		// ��ȡѧ��
	string& GetName() { return m_strName; }	// ��ȡ����
	int& GetScore() { return m_nScore; }		// ��ȡ�ɼ�
	static inline int CompareName(Student& s1, Student& s2)// �������Ƚ�
	{
		if (s1.m_strName == s2.m_strName)
			return 0;
		if (s1.m_strName > s2.m_strName)
			return 1;
		return -1;
	}
private:
	string m_strNo;	// ѧ��
	string m_strName;	// ����
	int m_nScore;		// �ɼ�
};
// ����<<����������ѧ����Ϣ
ostream& operator<<(ostream& out, Student &stu)
{
	out<<stu.GetNo()<<'\t'<<stu.GetName()<<'\t'<<stu.GetScore();
	return out;
}
#endif	// end of _STUDENT_H
