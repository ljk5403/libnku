#include "AdjGraph.h"
void ShowGraph(AdjGraph<char> &graph)
{
	char c;
	int nI, nJ, nWeight;
	cout<<"�����д洢������Ϊ��";
	for (nI=0; nI<graph.GetVertexNum(); nI++)
	{
		if (graph.GetVertexValue(nI, c))
			cout<<c<<' ';
	}
	cout<<endl;
	cout<<"���ض�����������Ķ����б�Ϊ��"<<endl;
	for (nI=0; nI<graph.GetVertexNum(); nI++)
	{
		cout<<'\t'<<nI<<':';
		nJ = graph.GetFirstEdge(nI);
		while (nJ >= 0)
		{
			cout<<nJ<<' ';
			nJ = graph.GetNextEdge(nI, nJ);
		}
		cout<<endl;
	}
	cout<<"�ߵ�Ȩ��Ϊ��^��ʾ�߲����ڣ���"<<endl;
	for (nI=0; nI<graph.GetVertexNum(); nI++)
	{
		for (nJ=0; nJ<graph.GetVertexNum(); nJ++)
		{
			if (graph.GetEdgeWeight(nI, nJ, nWeight))
				cout<<'\t'<<nWeight;
			else
				cout<<"\t^";
		}
		cout<<endl;
	}
	cout<<endl;
}
int main()
{
	AdjGraph<char> graph1(1), graph2(0);
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
	ShowGraph(graph1);
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
	ShowGraph(graph2);
	return 0;
}
