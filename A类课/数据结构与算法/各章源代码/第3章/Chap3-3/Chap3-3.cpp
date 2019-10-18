/*Chap3-3.cpp */
#include <iostream>
using namespace std;
#include "LinkStack.h"
bool Matching(char exp[])			//�������ƥ���Ƿ���ȷ����#��Ϊ���ʽ������
{
	LinkStack<char> S;			//�����ַ���ջ������������� 
	bool flag=true;					//����Ƿ�ƥ���״̬,1��ʾƥ�䣬��ʾ��ƥ��
	char ch1,ch2;
	ch1=*exp++;					//�ӱ��ʽ�ж���һ���ַ�
	while(ch1!='#'&& flag)
	{
		switch  (ch1)
		{
			case '[':
			case '(':				//�ַ���������
				S.Push(ch1);		//��ջ
				break;
			case ')':				//�ַ�����Բ����
				if(S.Top(ch2) && ch2=='(')	//ջ��Ԫ������Բ���ţ�ƥ��
					S.Pop(ch2);	//��ջ
				else 
					flag=false;	//ƥ�����
				break;
			case ']':				//�ַ����ҷ�����
				if(S.Top(ch2) && ch2=='[')	//ջ��Ԫ���������ţ�ƥ��
					S.Pop(ch2);	//��ջ
				else 
					flag=false;	//ƥ�����
				break;
		}
		ch1=*exp++;				//����һ���ַ�
	}
	return flag;
}
int main()
{
	char str[80];
	cout<<"�������ַ���:"<<endl;
	cin.getline(str,80);
	str[strlen(str)+1]='#';	//���ʽ�����ñ��ʽ������ʶ#
	if(Matching(str))
		cout<<"���ʽ�е�����ƥ����ȷ"<<endl;
	else
		cout<<"���ʽ�е�����ƥ�䲻��ȷ"<<endl;
	return 0;
}