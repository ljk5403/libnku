/*TestArrayTwoD.cpp     ���Զ�ά������ArrayTwoD*/
#include <iostream>
using namespace std;
#include "ArrayTwoD.h"
int main()
{
	ArrayTwoD<int> A(4,5);		//�������ж�ά����A
	for(int i=0;i<4;i++)
	for(int j=0;j<5;j++)
		A[i][j]=(i+1)*(j+1);			//�����±������[]ΪԪ�ظ�ֵ
	ArrayTwoD<int> B(A);			//���ÿ������캯��������A��������B
	ArrayTwoD<int> C;			//����һ���յĶ�ά����
	C=A;						//���ø�ֵ�����=
	cout<<A;						//�������A
	cout<<B;						//�������B
	cout<<C;						//�������C
	cout<<C.Rows()<<endl;			//�������C������
	cout<<C.Columns()<<endl;		//�������C������
}
