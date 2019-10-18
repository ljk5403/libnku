//permutation.cpp
#include<iostream>
#include"permutation.h"
using namespace std;
permutation::permutation(int n)
{
	m_n=n;
	m_p=new int[n+1];			//为了程序易读性，m_p[0]空闲
	m_used=new int[n+1];		//为了程序易读性，m_used[0]空闲
	for(int i=1;i<=n;i++)		//初始化数组m_p和数组m_used
	{
		m_p[i]=0;
		m_used[i]=0;
	}
}
void permutation::compute(int count)
{
	int i;
	if (count==m_n+1) //已经选出了n个元素，输出这个排列*/
	{
		for (i=1; i<=m_n; i++)
			cout<<m_p[i]<<" ";
		cout<<endl;
		return;
	}
	for (i=1; i<=m_n; i++)				//发现第count个自然数
		if (!m_used[i]) 
		{
			m_p[count] = i;					//把它放置在排列中
			m_used[i]++;					//标记该元素已被使用
			compute(count+1);				//搜索第count+1个自然数
			m_used[i]=0;					//没有成功则恢复递归前的值
		}
}
permutation::~permutation()
{
	delete []m_p;
	delete []m_used;
}