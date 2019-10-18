/*TestMatrix.cpp     ���Ծ�����Matrix*/
#include <iostream>
using namespace std;
#include "Matrix.h"
int main()
{
	Matrix<float> A(4,5),B(4,5),C(5,4);		//��������A4��5��B4��5��C5��4
	for(int i=1;i<=A.Rows();i++)
	for(int j=1;j<=A.Columns();j++)
	{
		A(i,j)=(float)0.1*i;			//�����±����������Ϊ����A��Ԫ�ظ�ֵ
		B(i,j)=(float)0.3*j;			//�����±����������Ϊ����B��Ԫ�ظ�ֵ
		C(j,i)=(float)0.5*i*j;		//�����±����������Ϊ����C��Ԫ�ظ�ֵ
	}
	cout<<A<<endl;				//�������A
	cout<<B<<endl;				//�������B
	cout<<C<<endl;				//�������C
	Matrix<float> D;				//�����վ���D
	D=A+B;						//���������+�������=
	cout<<D<<endl;				//������A��B�ĺ����
	D=A*C;						//���������*�������=
	cout<<D<<endl;				//������A��C�ĳ˻����
	D=Transpose(A);				//����ת�ò�������Transpos�͸�ֵ�����=
	cout<<D<<endl;				//�������A��ת�þ���
	return 0;
}