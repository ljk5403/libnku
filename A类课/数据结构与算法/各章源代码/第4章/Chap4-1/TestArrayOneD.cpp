/*TestArrayOneD.cpp   ����һά������ArrayOneD*/
#include <iostream>
using namespace std;
#include "ArrayOneD.h"
int main()
{
	ArrayOneD<char> A(10);	//����һ���и�Ԫ�ص�һά����A
	for(int i=0;i<10;i++)		//�����±������[]Ϊ������Ԫ�ظ�ֵ
		A[i]= 'a'+i;
	ArrayOneD<char> B(A);	//���ÿ������캯��������A��������B
	ArrayOneD<char> C;		//����һ���յ�һά����
	C=A;					//�������鸳ֵ�����=��������A������C��ֵ
	cout<<A;					//�������A
	cout<<B;					//�������B
	cout<<C;					//�������C
	cout<<C.Length()<<endl;	//�������C�ĳ���
	C.ReSize(15);				//����Ϊ����C�ķ���ռ�
	cout<<C.Length()<<endl;	//���������C�ĳ���
}
