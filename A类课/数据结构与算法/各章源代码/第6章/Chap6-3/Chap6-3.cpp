#include "AdjLinkedGraph.h"
#include "MSTAlgorithms.h"
void ShowGraph(AdjLinkedGraph<char> &graph)
{
	char c;
	int nI, nJ, nWeight;
	cout<<"顶点中存储的数据为：";
	for (nI=0; nI<graph.GetVertexNum(); nI++)
	{
		if (graph.GetVertexValue(nI, c))
			cout<<c<<' ';
	}
	cout<<endl;
	cout<<"与特定顶点相关联的顶点列表为："<<endl;
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
	cout<<"边的权重为（^表示边不存在）："<<endl;
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
	// 创建无向图
	for (c='0'; c<='3'; c++)
		graph1.AddOneVertex(c);
	graph1.AddOneEdge(0, 1, 3);
	graph1.AddOneEdge(0, 2, 6);
	graph1.AddOneEdge(0, 3, 5);
	graph1.AddOneEdge(1, 2, 4);
	graph1.AddOneEdge(1, 3, 7);
	graph1.AddOneEdge(2, 3, 1);
	// 按Prim算法计算graph1的最小生成树graph2
	if (MSTPrim(0, graph1, graph2))
	{
		cout<<"Prim算法生成的最小生成树：";
		ShowGraph(graph2);
	}
	// 按Kruskal算法计算graph1的最小生成树graph3
	if (MSTKruskal(0, graph1, graph3))
	{
		cout<<"Kruskal算法生成的最小生成树：";
		ShowGraph(graph3);
	}
	return 0;
}
