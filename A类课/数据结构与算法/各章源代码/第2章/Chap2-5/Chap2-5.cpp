/* Chap2-5.cpp����˳�����Լɪ������*/
#include <iostream>
using namespace std;
#include "LinearList.h"
#include "Person.h"
#include <ctime>
#include <cstdlib>
const int MAXSIZE=20; //���������20��
int main()
{	
	double random(double,double);
	LinearList<Person> NodeLList(MAXSIZE);
				//���������MAXSIZE����PersonΪ����Ԫ�ص�˳������
	Person person;
	int n,m,index;
	cout<<"������������";
	cin>>n;
	//����n�����е�ÿ���˶�����һ���������
	srand(unsigned(time(0)));  
	for (int i=1;i<=n;i++)
	{
		person.SetPerson(i,int(random(0,n)));
		NodeLList.Insert(i,person);
	}
	cout<<"��ǰ���Ԫ��Ϊ��\n"<<NodeLList<<endl;
	//��Ա��Ȧ
	NodeLList.GetData(1,person);				//�ӵ�1���˿�ʼ
	index=1;
	cout<<"��Ȧ�˵�˳��Ϊ��\n";
	while (!NodeLList.IsEmpty())
	{
		m=person.GetPassWord();					 //�õ�����
		index=(index-1+m)%n;					 //�ҵ�Ҫ��Ȧ����
		if (index==0) index=n;
		NodeLList.DeleteByIndex(index,person);
										//��Ȧ������Ȧ�˵���Ϣ����person
		n=n-1;									 //������1
		cout<<person.GetNo();					 //�����Ȧ�˱��		
	}
	return 0;
} 
//�������������
double random(double start, double end)
{
    return start+(end-start)*rand()/(RAND_MAX + 1.0);
}
