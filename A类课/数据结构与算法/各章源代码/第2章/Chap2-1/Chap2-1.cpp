/* Chap2-1.cpp�������Ա�˳��洢�ṹ��Ӧ������*/
#include <iostream>
using namespace std;
#include "LinearList.h"
int main()
{
	LinearList<int> IntegerLList(10);	//��������и���intΪ����Ԫ�ص�˳������
	int x,y;
	//���β���100��200��300��400����ʾ��ǰ��������Ϣ
	IntegerLList.Insert(1,100);
	IntegerLList.Insert(2,200);
	IntegerLList.Insert(3,300);
	IntegerLList.Insert(4,400);
	cout<<"��ǰ��ĳ���Ϊ��"<<IntegerLList.GetLength()<<endl;
	cout<<"��ǰ���Ԫ��Ϊ��\n"<<IntegerLList<<endl;
	//��ȡ��������еڸ�Ԫ�ص�ֵ���ж�Ԫ���ڱ��е�λ��
	if(IntegerLList.GetData(3,x))
		cout<<"���еڸ�Ԫ��Ϊ��"<<x<<endl;
	x=100;
	cout<<"Ԫ���ڱ��е�λ��Ϊ��"<<IntegerLList.Find(x)<<endl; 
	//��100�޸�Ϊ150��ɾ��200��400����ʾ��ǰ��������Ϣ
	x=150;
	IntegerLList.ModifyData(1,x);
	IntegerLList.DeleteByIndex(2,x);
	x=400;
	IntegerLList.DeleteByKey(x,y);
	cout<<"��ǰ��ĳ���Ϊ��"<<IntegerLList.GetLength()<<endl;
	cout<<"��ǰ���Ԫ��Ϊ��\n"<<IntegerLList<<endl;
	return 0;
}