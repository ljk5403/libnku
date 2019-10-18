#include "AdjLinkedGraph.h"
#include "ShortestPath.h"
int main()
{
	AdjLinkedGraph<char> graph(1);
	char c;

	// 创建有向图
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
	// 按Dijkstra算法计算graph的最短路径
	cout<<"按Dijkstra算法计算graph的最短路径："<<endl;
	ShortestPathDij(0, graph);
	ShortestPathDij(1, graph);
	ShortestPathDij(2, graph);
	ShortestPathDij(3, graph);
	ShortestPathDij(4, graph);
	// 按Floyd算法计算graph的最短路径
	cout<<"按Floyd算法计算graph的最短路径："<<endl;
	ShortestPathFloyd(graph);
	return 0;
}