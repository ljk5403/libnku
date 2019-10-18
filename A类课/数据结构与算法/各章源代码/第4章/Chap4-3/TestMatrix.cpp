/*TestMatrix.cpp     测试矩阵类Matrix*/
#include <iostream>
using namespace std;
#include "Matrix.h"
int main()
{
	Matrix<float> A(4,5),B(4,5),C(5,4);		//声明矩阵A4×5，B4×5，C5×4
	for(int i=1;i<=A.Rows();i++)
	for(int j=1;j<=A.Columns();j++)
	{
		A(i,j)=(float)0.1*i;			//调用下标运算符（）为矩阵A的元素赋值
		B(i,j)=(float)0.3*j;			//调用下标运算符（）为矩阵B的元素赋值
		C(j,i)=(float)0.5*i*j;		//调用下标运算符（）为矩阵C的元素赋值
	}
	cout<<A<<endl;				//输出矩阵A
	cout<<B<<endl;				//输出矩阵B
	cout<<C<<endl;				//输出矩阵C
	Matrix<float> D;				//声明空矩阵D
	D=A+B;						//调用运算符+和运算符=
	cout<<D<<endl;				//将矩阵A和B的和输出
	D=A*C;						//调用运算符*和运算符=
	cout<<D<<endl;				//将矩阵A和C的乘积输出
	D=Transpose(A);				//调用转置操作函数Transpos和赋值运算符=
	cout<<D<<endl;				//输出矩阵A的转置矩阵
	return 0;
}