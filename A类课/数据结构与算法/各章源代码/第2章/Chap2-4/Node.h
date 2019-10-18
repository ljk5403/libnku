/* Node.h������Ԫ��Node��*/
#ifndef NODE
#define NODE
#include <iostream>
#include <string>
using namespace std;
class Node
{
	public:
		Node(char * NumberOfStudent,char * NameOfStudent,int grade[]);//���캯��
		Node(){};//�޲ι��캯��
		Node& GetNode();  //�õ��������
		void OutPutNode(ostream& out) const;   //����������
	private:
		string StdNumber;
		string StdName;
		int Score[3];
};
//ʵ�ֹ��캯��
Node::Node(char * NumberOfStudent,char * NameOfStudent,int grade[])
{
	StdNumber=NumberOfStudent;
	StdName=NameOfStudent;
	for (int i=0;i<3;i++)
		Score[i]=grade[i];
}
//ʵ�ֵõ�������ݺ���
Node& Node::GetNode()
{
	return *this;
}
//ʵ�����������ݺ���
void Node::OutPutNode(ostream& out) const
{
	out<<StdNumber<<" "<<StdName<<endl;
	out<<"���ģ�"<<Score[0];
	out<<"��ѧ��"<<Score[1];
	out<<"Ӣ�"<<Score[2];
}
//���ز��������<<
ostream& operator<<(ostream& out,const Node& x)
{
	x.OutPutNode(out);
	return out;
}
#endif