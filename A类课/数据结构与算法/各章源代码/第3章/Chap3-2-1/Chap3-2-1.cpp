/*Chap3-2-1.Cpp*/
#include <iostream>
using namespace std;
#include "LinkQueue.h"
/*�����n�еĿո�,����nΪҪ�����������ǵ�������kΪ��ǰ�������*/
void PrintSpace(int n,int k)
{
	for(int i=1;i<=n-k;i++)
		cout<<' ';
}
//���������ǵ�ǰn�У�n>0��
void YangHui(int n)
{
	LinkQueue<int> Q;
	int x,y;
	PrintSpace(n,1);				//�����һ��1ǰ��Ŀո�
	cout<<'1'<<endl;				//�����һ�е�1
	Q.Insert(0);					//����п�ʼ��ʶ��0��
	Q.Insert(1);					//��2�����
	Q.Insert(1);					//��2�����

	for(int i=2;i<=n;i++)
	{
		Q.Insert(0);				//����н�����ʶ��0��
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
	cout<<"������Ҫ��ӡ��������ǵ���:";
	cin>>n;
	YangHui(n);
	return 0;
}