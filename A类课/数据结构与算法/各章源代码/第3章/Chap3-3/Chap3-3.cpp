/*Chap3-3.cpp */
#include <iostream>
using namespace std;
#include "LinkStack.h"
bool Matching(char exp[])			//检查括号匹配是否正确，‘#’为表达式结束符
{
	LinkStack<char> S;			//建立字符型栈，用来存放括号 
	bool flag=true;					//存放是否匹配的状态,1表示匹配，表示不匹配
	char ch1,ch2;
	ch1=*exp++;					//从表达式中读入一个字符
	while(ch1!='#'&& flag)
	{
		switch  (ch1)
		{
			case '[':
			case '(':				//字符是左括号
				S.Push(ch1);		//进栈
				break;
			case ')':				//字符是右圆括号
				if(S.Top(ch2) && ch2=='(')	//栈顶元素是左圆括号，匹配
					S.Pop(ch2);	//出栈
				else 
					flag=false;	//匹配错误
				break;
			case ']':				//字符是右方括号
				if(S.Top(ch2) && ch2=='[')	//栈顶元素是左方括号，匹配
					S.Pop(ch2);	//出栈
				else 
					flag=false;	//匹配错误
				break;
		}
		ch1=*exp++;				//读下一个字符
	}
	return flag;
}
int main()
{
	char str[80];
	cout<<"请输入字符串:"<<endl;
	cin.getline(str,80);
	str[strlen(str)+1]='#';	//表达式后设置表达式结束标识#
	if(Matching(str))
		cout<<"表达式中的括号匹配正确"<<endl;
	else
		cout<<"表达式中的括号匹配不正确"<<endl;
	return 0;
}