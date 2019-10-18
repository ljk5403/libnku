/* Chap2-1.cpp：简单线性表顺序存储结构的应用问题*/
#include <iostream>
using namespace std;
#include "LinearList.h"
int main()
{
	LinearList<int> IntegerLList(10);	//声明最多有个以int为数据元素的顺序表对象
	int x,y;
	//依次插入100、200、300、400，显示当前表的相关信息
	IntegerLList.Insert(1,100);
	IntegerLList.Insert(2,200);
	IntegerLList.Insert(3,300);
	IntegerLList.Insert(4,400);
	cout<<"当前表的长度为："<<IntegerLList.GetLength()<<endl;
	cout<<"当前表的元素为：\n"<<IntegerLList<<endl;
	//读取并输出表中第个元素的值，判断元素在表中的位置
	if(IntegerLList.GetData(3,x))
		cout<<"表中第个元素为："<<x<<endl;
	x=100;
	cout<<"元素在表中的位置为："<<IntegerLList.Find(x)<<endl; 
	//将100修改为150，删除200和400后，显示当前表的相关信息
	x=150;
	IntegerLList.ModifyData(1,x);
	IntegerLList.DeleteByIndex(2,x);
	x=400;
	IntegerLList.DeleteByKey(x,y);
	cout<<"当前表的长度为："<<IntegerLList.GetLength()<<endl;
	cout<<"当前表的元素为：\n"<<IntegerLList<<endl;
	return 0;
}