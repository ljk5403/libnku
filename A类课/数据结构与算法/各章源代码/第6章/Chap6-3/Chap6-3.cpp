#include "AdjLinkedGraph.h"
#include "MSTAlgorithms.h"
void ShowGraph(AdjLinkedGraph<char> &graph)
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
	AdjLinkedGraph<char> graph1(0), graph2(0), graph3(0);
	char c;
	// ��������ͼ
	for (c='0'; c<='3'; c++)
		graph1.AddOneVertex(c);
	graph1.AddOneEdge(0, 1, 3);
	graph1.AddOneEdge(0, 2, 6);
	graph1.AddOneEdge(0, 3, 5);
	graph1.AddOneEdge(1, 2, 4);
	graph1.AddOneEdge(1, 3, 7);
	graph1.AddOneEdge(2, 3, 1);
	// ��Prim�㷨����graph1����С������graph2
	if (MSTPrim(0, graph1, graph2))
	{
		cout<<"Prim�㷨���ɵ���С��������";
		ShowGraph(graph2);
	}
	// ��Kruskal�㷨����graph1����С������graph3
	if (MSTKruskal(0, graph1, graph3))
	{
		cout<<"Kruskal�㷨���ɵ���С��������";
		ShowGraph(graph3);
	}
	return 0;
}
