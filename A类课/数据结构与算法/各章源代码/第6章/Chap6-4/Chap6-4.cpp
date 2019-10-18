#include "AdjLinkedGraph.h"
#include "ShortestPath.h"
int main()
{
	AdjLinkedGraph<char> graph(1);
	char c;

	// ��������ͼ
	for (c='0'; c<='4'; c++)
		graph.AddOneVertex(c);
	graph.AddOneEdge(0, 1, 2);
	graph.AddOneEdge(0, 2, 7);
	graph.AddOneEdge(0, 3, 3);
	graph.AddOneEdge(1, 4, 2);
	graph.AddOneEdge(2, 0, 8);
	graph.AddOneEdge(2, 3, 6);
	graph.AddOneEdge(3, 0, 4);
	graph.AddOneEdge(3, 2, 6);
	graph.AddOneEdge(4, 2, 1);
	// ��Dijkstra�㷨����graph�����·��
	cout<<"��Dijkstra�㷨����graph�����·����"<<endl;
	ShortestPathDij(0, graph);
	ShortestPathDij(1, graph);
	ShortestPathDij(2, graph);
	ShortestPathDij(3, graph);
	ShortestPathDij(4, graph);
	// ��Floyd�㷨����graph�����·��
	cout<<"��Floyd�㷨����graph�����·����"<<endl;
	ShortestPathFloyd(graph);
	return 0;
}