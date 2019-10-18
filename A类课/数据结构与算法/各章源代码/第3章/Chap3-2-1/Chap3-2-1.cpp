/*Chap3-2-1.Cpp*/
#include <iostream>
using namespace std;
#include "LinkQueue.h"
/*输出第n行的空格,参数n为要输出的杨辉三角的行数，k为当前输出行数*/
void PrintSpace(int n,int k)
{
	for(int i=1;i<=n-k;i++)
		cout<<' ';
}
//输出杨辉三角的前n行（n>0）
void YangHui(int n)
{
	LinkQueue<int> Q;
	int x,y;
	PrintSpace(n,1);				//输出第一行1前面的空格
	cout<<'1'<<endl;				//输出第一行的1
	Q.Insert(0);					//添加行开始标识‘0’
	Q.Insert(1);					//第2行入队
	Q.Insert(1);					//第2行入队

	for(int i=2;i<=n;i++)
	{
		Q.Insert(0);				//添加行结束标识‘0’
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
	cout<<"请输入要打印的杨辉三角的行:";
	cin>>n;
	YangHui(n);
	return 0;
}