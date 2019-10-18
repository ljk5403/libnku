/*TestArrayTwoD.cpp     测试二维数组类ArrayTwoD*/
#include <iostream>
using namespace std;
#include "ArrayTwoD.h"
int main()
{
	ArrayTwoD<int> A(4,5);		//声明行列二维数组A
	for(int i=0;i<4;i++)
	for(int j=0;j<5;j++)
		A[i][j]=(i+1)*(j+1);			//调用下标运算符[]为元素赋值
	ArrayTwoD<int> B(A);			//调用拷贝构造函数由数组A创建数组B
	ArrayTwoD<int> C;			//声明一个空的二维数组
	C=A;						//调用赋值运算符=
	cout<<A;						//输出数组A
	cout<<B;						//输出数组B
	cout<<C;						//输出数组C
	cout<<C.Rows()<<endl;			//输出数组C的行数
	cout<<C.Columns()<<endl;		//输出数组C的列数
}
