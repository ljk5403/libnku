/* Chap2-6.cpp����ѭ��������Լɪ������*/
#include <iostream>
using namespace std;
#include "CircularList.h"
#include "Person.h"
#include <ctime>
#include <cstdlib>
int main()
{
	double random(double,double);
	CircularList<Person> NodeCList;//������NodeΪ����Ԫ�ص�ѭ���������
	Person person;
	int n,m,index;
	cout<<"������������";
	cin>>n;
	//����n�����е�ÿ���˶�����һ���������
	srand(unsigned(time(0)));  
	for (int i=1;i<=n;i++)
	{
		person.SetPerson(i,int(random(0,n)));
		NodeCList.Insert(i,person);
	}
	cout<<"��ǰ���Ԫ��Ϊ��\n"<<NodeCList<<endl;
	//��Ա��Ȧ
	NodeCList.GetData(1,person);//�ӵ�1���˿�ʼ
	index=1;
	cout<<"��Ȧ�˵�˳��Ϊ��\n";
	while (!NodeCList.IsEmpty())
	{
		m=person.GetPassWord();					 //�õ�����
		//�����ҵ�Ҫ��Ȧ����
		if (m!=0) 
		{
			index=(index-1+m)%n;					 
			if (index==0) index=n;
		}
		NodeCList.DeleteByIndex(index,person);	 
										//��Ȧ,������Ȧ�˵���Ϣ����person
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
