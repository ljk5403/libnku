// Chap9_1.cpp
#include "SequentialFile.h"
#include "Student.h"
int main()
{
	Student stu;
	SequentialFileBatchProcess("student.txt", "studenttrans.txt", "studentnew.txt", stu);
	return 0;
}
