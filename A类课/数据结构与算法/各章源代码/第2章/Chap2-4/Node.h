/* Node.h：数据元素Node类*/
#ifndef NODE
#define NODE
#include <iostream>
#include <string>
using namespace std;
class Node
{
	public:
		Node(char * NumberOfStudent,char * NameOfStudent,int grade[]);//构造函数
		Node(){};//无参构造函数
		Node& GetNode();  //得到结点数据
		void OutPutNode(ostream& out) const;   //输出结点数据
	private:
		string StdNumber;
		string StdName;
		int Score[3];
};
//实现构造函数
Node::Node(char * NumberOfStudent,char * NameOfStudent,int grade[])
{
	StdNumber=NumberOfStudent;
	StdName=NameOfStudent;
	for (int i=0;i<3;i++)
		Score[i]=grade[i];
}
//实现得到结点数据函数
Node& Node::GetNode()
{
	return *this;
}
//实现输出结点数据函数
void Node::OutPutNode(ostream& out) const
{
	out<<StdNumber<<" "<<StdName<<endl;
	out<<"语文："<<Score[0];
	out<<"数学："<<Score[1];
	out<<"英语："<<Score[2];
}
//重载插入运算符<<
ostream& operator<<(ostream& out,const Node& x)
{
	x.OutPutNode(out);
	return out;
}
#endif