/* Chap3-1.cpp��˳��ջ�ļ�Ӧ������*/
#include <iostream>
using namespace std;
#include "LinearStack.h"
void conversion(int,int);	//ת������
int main()
{
	int n,base;
	cout<<"������ʮ��������Ҫת���Ľ��ƵĻ���:\n ";
	cin>>n>>base;
	conversion(n,base);
	cout<<endl;
	return 0;
}
void conversion(int n,int base)
{
	int x,y;
	y=n;
	LinearStack<int> s(100);
	while(y)
	{
		s.Push(y%base);
		y = y/base;
	}
	cout<<"ʮ������"<<n<<"ת��Ϊ"<<base<<"����Ϊ:\n";
	while(!s.IsEmpty())
	{
		s.Pop(x);
		cout<<x;
	}
}