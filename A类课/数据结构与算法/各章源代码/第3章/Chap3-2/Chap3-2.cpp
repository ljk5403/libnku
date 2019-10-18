/* Chap3-2.cpp：顺序循环队列应用问题*/
#include <iostream>
using namespace std;
#include "LinearQueue.h"
/*输出第n行的空格,参数n为要输出的杨辉三角的行数，k为当前输出行数*/
void PrintSpace(int n,int k)
{
	for(int i=1;i<=n-k;i++)
		cout<<' ';
}
//输出杨辉三角的前n行（n>0）
void YangHui(int n)
{
	LinearQueue<int> Q(n+2);
	int x,y;
	PrintSpace(n,1);				//输出第一行前面的空格
	cout<<'1'<<endl;				//输出第一行的
	Q.Insert(0);					//添加行开始标识‘’
	Q.Insert(1);					//第2行入队
	Q.Insert(1);					//第2行入队
	for(int i=2;i<=n;i++)
	{
		Q.Insert(0);				//添加行结束标识‘’
		PrintSpace(n,i);			//输出第i行数字前面的空格
		do
		{
			Q.Delete(x);			
			Q.GetElement(y);		
			if(y)
				cout<<y<<' ';
			else 
				cout<<endl;
			Q.Insert(x+y) ;
		}while(y);
	}
	cout<<endl;
}
int main()
{
	int n;
	cout<<"请输入要显示的杨辉三角的行数:";
	cin>>n;
	YangHui(n);
	return 0;
}