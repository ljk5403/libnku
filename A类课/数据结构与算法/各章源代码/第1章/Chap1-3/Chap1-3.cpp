//Chap1-3.cpp
#include <iostream>
using namespace std;
int main()
{
	int i, j, k, m, n;
	for(i=1; i<=9; i++)					//��ѭ����������λ
		for(j=0; j<=9; j++)				//�в�ѭ��������ʮλ
			for(k=0; k<=9; k++)			//��ѭ����������λ
			{
				m=i*i*i+j*j*j+k*k*k;
				n=100*i+10*j+k;
				if(m==n)
					cout<<m<<endl;		//����ҵ���ˮ�ɻ���
			}
	return 0;
}
