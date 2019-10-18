//permutation.cpp
#include<iostream>
#include"permutation.h"
using namespace std;
permutation::permutation(int n)
{
	m_n=n;
	m_p=new int[n+1];			//Ϊ�˳����׶��ԣ�m_p[0]����
	m_used=new int[n+1];		//Ϊ�˳����׶��ԣ�m_used[0]����
	for(int i=1;i<=n;i++)		//��ʼ������m_p������m_used
	{
		m_p[i]=0;
		m_used[i]=0;
	}
}
void permutation::compute(int count)
{
	int i;
	if (count==m_n+1) //�Ѿ�ѡ����n��Ԫ�أ�����������*/
	{
		for (i=1; i<=m_n; i++)
			cout<<m_p[i]<<" ";
		cout<<endl;
		return;
	}
	for (i=1; i<=m_n; i++)				//���ֵ�count����Ȼ��
		if (!m_used[i]) 
		{
			m_p[count] = i;					//����������������
			m_used[i]++;					//��Ǹ�Ԫ���ѱ�ʹ��
			compute(count+1);				//������count+1����Ȼ��
			m_used[i]=0;					//û�гɹ���ָ��ݹ�ǰ��ֵ
		}
}
permutation::~permutation()
{
	delete []m_p;
	delete []m_used;
}