/*Chap3-4.cpp*/
#include <iostream>
using namespace std;
#include "LinkQueue.h"
const int N=20;
bool FindConflict(int R[][N],int* Group,int n,int CurrentNum)//�ж��Ƿ�ʱ���ͻ
{
	for (int i=0;i<n;i++)
		if (Group[i]==1 && R[i][CurrentNum]==1)
			return true;
	return false;
}

void DivideIntoGroup(int R[][N], int n)
{
	LinkQueue<int> Q;							//�����ֵ���Ŀ�Ŷ���
	int *Result=new int[n];						//���ֽ������
	int *Group=new int[n];						//��¼��ǰ���ֵ�ͬһ�����Ŀ
	int SportsNum,PreSportsNum;				//��Ŀ��
	int GroupNum;							//���
	for(int i=0;i<n;i++)							//��ʼ��
	{
		Q.Insert(i);							//��Ŀ�����
		Result[i]=0;							//�����������ʼΪ
	}
	GroupNum=0;				
	PreSportsNum=n;
	while(!Q.IsEmpty())
	{
		Q.Delete( SportsNum);					//��Ŀ�ų���
		if (SportsNum<PreSportsNum)  
		//����Ŀ�ű�ǰ����Ŀ��С������Ҫ��ʣ�µ���Ŀ���ֵ��µ�һ��
		{
			GroupNum++;				
			for(int i=0;i<n;i++)	//��ʼ��
				Group[i]=0;					//��ǰ���л�û���κ���Ŀ
		}
		if(!FindConflict(R,Group,n,SportsNum))	//����ͻ�򽫸���Ŀ����
		{
			Group[SportsNum]=1;				//��Ŀ����
			Result[SportsNum]=GroupNum;
		}
		else									//ʱ���ͻ����Ŀ�������
			Q.Insert(SportsNum);
		PreSportsNum=SportsNum;
	}
	//����˶�����Ŀ����
	for(int i=1;i<=GroupNum;i++)
	{
		cout<<"��"<<i<<"��ͬʱ��������Ŀ������";
		for(int j=0;j<n;j++)
			if(Result[j]==i)
				cout<<j+1<<"����Ŀ";
		cout<<endl;
	}
}
int main()
{
	int n;
	int R[N][N];//��ų�ͻ����
	cout<<"�������˶�����Ŀ����"<<endl;
	cin>>n;
	cout<<"�������˶�Ա��Ŀʱ���ͻ����:"<<endl;
	for (int i=0;i<n;i++)
	for (int j=0;j<n;j++)
		cin>>R[i][j];
	DivideIntoGroup(R,n);
}
