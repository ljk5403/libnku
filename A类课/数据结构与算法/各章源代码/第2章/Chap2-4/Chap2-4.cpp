#include <iostream>
using namespace std;
#include "LinkList.h"
#include "Node.h"
int main()
{
	LinkList<Node> NodeLList;//������NodeΪ����Ԫ�صĵ����������
	int grade1[3]={99,100,95};
	int grade2[3]={95,98,88};
	int grade3[3]={90,90,90};
	Node Node1("1010001","�¹�Ӣ",grade1);
	Node Node2("1010002","���ڱ�",grade2);
	Node Node3("1010003","������",grade3);
	Node x;
	//���������������
	NodeLList.Insert(1,Node1);
	NodeLList.Insert(2,Node2);
	//��ʾ��ǰ���״̬
	cout<<"��ǰ��ĳ���Ϊ��"<<NodeLList.GetLength()<<endl;
	cout<<"��ǰ���Ԫ��Ϊ��\n"<<NodeLList<<endl;
	//�����е�2��Ԫ�����
	NodeLList.GetData(2,x);
	cout<<"���е�2��Ԫ��Ϊ��\n"<<x<<endl;
	//ɾ�����еڸ�Ԫ��,�޸ĵڸ�Ԫ�ص���Ϣ����ʾ��ǰ���״̬
	NodeLList.DeleteByIndex(2,x);
	cout<<"�ո�ɾ����Ԫ��Ϊ��\n"<<x<<endl;
	NodeLList.ModifyData(1,Node3);
	cout<<"��ǰ��ĳ���Ϊ��"<<NodeLList.GetLength()<<endl;
	cout<<"��ǰ���Ԫ��Ϊ��\n"<<NodeLList<<endl;
	return 0;
}
