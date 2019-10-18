/*TestArrayOneD.cpp   测试一维数组类ArrayOneD*/
#include <iostream>
using namespace std;
#include "ArrayOneD.h"
int main()
{
	ArrayOneD<char> A(10);	//声明一个有个元素的一维数组A
	for(int i=0;i<10;i++)		//调用下标运算符[]为该数组元素赋值
		A[i]= 'a'+i;
	ArrayOneD<char> B(A);	//调用拷贝构造函数由数组A创建数组B
	ArrayOneD<char> C;		//声明一个空的一维数组
	C=A;					//调用数组赋值运算符=，用数组A给数组C赋值
	cout<<A;					//输出数组A
	cout<<B;					//输出数组B
	cout<<C;					//输出数组C
	cout<<C.Length()<<endl;	//输出数组C的长度
	C.ReSize(15);				//重新为数组C的分配空间
	cout<<C.Length()<<endl;	//输出新数组C的长度
}
