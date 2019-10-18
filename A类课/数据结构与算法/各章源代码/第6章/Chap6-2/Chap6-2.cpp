#include "AdjLinkedGraph.h"
int main()
{
	AdjLinkedGraph<char> graph1(1), graph2(0);
	char c;
	// ��������ͼ
	for (c='A'; c<='E'; c++)
		graph1.AddOneVertex(c);
	graph1.AddOneEdge(0, 1, 2);
	graph1.AddOneEdge(0, 2, 2);
	graph1.AddOneEdge(1, 4, 3);
	graph1.AddOneEdge(2, 0, 5);
	graph1.AddOneEdge(2, 3, 6);
	graph1.AddOneEdge(3, 0, 3);
	// ��ʾ����ͼ�Ķ����д洢�����ݺͱߵ�Ȩ��
	cout<<"����ͼ";
	cout<<"������ȱ��������";
	graph1.BFSTraverse(0);	// ���ù�����ȱ�������
	cout<<endl;
	cout<<"�ݹ�������ȱ��������";
	graph1.DFSTraverse(0, 0);	// ���õݹ�������ȱ�������
	cout<<endl;
	cout<<"�ǵݹ�������ȱ��������";
	graph1.DFSTraverse(0);		// ���÷ǵݹ�������ȱ�������
	cout<<endl;
	// ��������ͼ
	for (c='E'; c>='A'; c--)
		graph2.AddOneVertex(c);
	graph2.AddOneEdge(0, 1, 2);
	graph2.AddOneEdge(0, 2, 5);
	graph2.AddOneEdge(0, 3, 3);
	graph2.AddOneEdge(1, 4, 3);
	graph2.AddOneEdge(2, 3, 6);
	// ��ʾ����ͼ�Ķ����д洢�����ݺͱߵ�Ȩ��
	cout<<"����ͼ";
	cout<<"������ȱ��������";
	graph2.BFSTraverse(0);	// ���ù�����ȱ�������
	cout<<endl;
	cout<<"�ݹ�������ȱ��������";
	graph2.DFSTraverse(0, 0);	// ���õݹ�������ȱ�������
	cout<<endl;
	cout<<"�ǵݹ�������ȱ��������";
	graph2.DFSTraverse(0);		// ���÷ǵݹ�������ȱ�������
	cout<<endl;
	return 0;
}
