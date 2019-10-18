/* Chap3-2.cpp��˳��ѭ������Ӧ������*/
#include <iostream>
using namespace std;
#include "LinearQueue.h"
/*�����n�еĿո�,����nΪҪ�����������ǵ�������kΪ��ǰ�������*/
void PrintSpace(int n,int k)
{
	for(int i=1;i<=n-k;i++)
		cout<<' ';
}
//���������ǵ�ǰn�У�n>0��
void YangHui(int n)
{
	LinearQueue<int> Q(n+2);
	int x,y;
	PrintSpace(n,1);				//�����һ��ǰ��Ŀո�
	cout<<'1'<<endl;				//�����һ�е�
	Q.Insert(0);					//����п�ʼ��ʶ����
	Q.Insert(1);					//��2�����
	Q.Insert(1);					//��2�����
	for(int i=2;i<=n;i++)
	{
		Q.Insert(0);				//����н�����ʶ����
		PrintSpace(n,i);			//�����i������ǰ��Ŀո�
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
	cout<<"������Ҫ��ʾ��������ǵ�����:";
	cin>>n;
	YangHui(n);
	return 0;
}