/*Chap3-4.cpp*/
#include <iostream>
using namespace std;
#include "LinkQueue.h"
const int N=20;
bool FindConflict(int R[][N],int* Group,int n,int CurrentNum)//判断是否时间冲突
{
	for (int i=0;i<n;i++)
		if (Group[i]==1 && R[i][CurrentNum]==1)
			return true;
	return false;
}

void DivideIntoGroup(int R[][N], int n)
{
	LinkQueue<int> Q;							//带划分的项目号队列
	int *Result=new int[n];						//划分结果数组
	int *Group=new int[n];						//记录当前划分到同一组的项目
	int SportsNum,PreSportsNum;				//项目号
	int GroupNum;							//组号
	for(int i=0;i<n;i++)							//初始化
	{
		Q.Insert(i);							//项目号入队
		Result[i]=0;							//分组结果数组初始为
	}
	GroupNum=0;				
	PreSportsNum=n;
	while(!Q.IsEmpty())
	{
		Q.Delete( SportsNum);					//项目号出队
		if (SportsNum<PreSportsNum)  
		//当项目号比前面项目号小表明需要将剩下的项目划分到新的一组
		{
			GroupNum++;				
			for(int i=0;i<n;i++)	//初始化
				Group[i]=0;					//新前组中还没有任何项目
		}
		if(!FindConflict(R,Group,n,SportsNum))	//不冲突则将该项目进组
		{
			Group[SportsNum]=1;				//项目进组
			Result[SportsNum]=GroupNum;
		}
		else									//时间冲突则将项目重新入队
			Q.Insert(SportsNum);
		PreSportsNum=SportsNum;
	}
	//输出运动会项目安排
	for(int i=1;i<=GroupNum;i++)
	{
		cout<<"第"<<i<<"组同时比赛的项目包括：";
		for(int j=0;j<n;j++)
			if(Result[j]==i)
				cout<<j+1<<"号项目";
		cout<<endl;
	}
}
int main()
{
	int n;
	int R[N][N];//存放冲突矩阵
	cout<<"请输入运动会项目数："<<endl;
	cin>>n;
	cout<<"请输入运动员项目时间冲突矩阵:"<<endl;
	for (int i=0;i<n;i++)
	for (int j=0;j<n;j++)
		cin>>R[i][j];
	DivideIntoGroup(R,n);
}
