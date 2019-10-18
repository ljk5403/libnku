#include <iostream>
using namespace std;
#include "LinkList.h"
#include "Node.h"
int main()
{
	LinkList<Node> NodeLList;//声明以Node为数据元素的单向链表对象
	int grade1[3]={99,100,95};
	int grade2[3]={95,98,88};
	int grade3[3]={90,90,90};
	Node Node1("1010001","穆桂英",grade1);
	Node Node2("1010002","杨宗保",grade2);
	Node Node3("1010003","杨六郎",grade3);
	Node x;
	//将两个结点插入表中
	NodeLList.Insert(1,Node1);
	NodeLList.Insert(2,Node2);
	//显示当前表的状态
	cout<<"当前表的长度为："<<NodeLList.GetLength()<<endl;
	cout<<"当前表的元素为：\n"<<NodeLList<<endl;
	//将表中第2个元素输出
	NodeLList.GetData(2,x);
	cout<<"表中第2个元素为：\n"<<x<<endl;
	//删除表中第个元素,修改第个元素的信息，显示当前表的状态
	NodeLList.DeleteByIndex(2,x);
	cout<<"刚刚删除的元素为：\n"<<x<<endl;
	NodeLList.ModifyData(1,Node3);
	cout<<"当前表的长度为："<<NodeLList.GetLength()<<endl;
	cout<<"当前表的元素为：\n"<<NodeLList<<endl;
	return 0;
}
