/* Chap3-1-1.cpp*/
#include <iostream>
using namespace std;
#include "LinkStack.h"
void conversion(int,int);//转换函数
int main()
{
	int n,base;
	cout<<"请输入十进制数和要转换的进制的基数:\n";
	cin>>n>>base;
	conversion(n,base);
	cout<<endl;
	return 0;
}
void conversion(int n,int base)
{
	int x,y;
	y=n;
	LinkStack<int> s;
	while(y)
	{
		s.Push(y%base);
		y = y/base;
	}
	cout<<"十进制数"<<n<<"转换为"<<base<<"进制为:\n";
	while(!s.IsEmpty())
	{
		s.Pop(x);
		cout<<x;
	}
}