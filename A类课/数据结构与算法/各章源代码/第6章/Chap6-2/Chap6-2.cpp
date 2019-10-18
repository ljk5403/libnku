#include "AdjLinkedGraph.h"
int main()
{
	AdjLinkedGraph<char> graph1(1), graph2(0);
	char c;
	// 创建有向图
	for (c='A'; c<='E'; c++)
		graph1.AddOneVertex(c);
	graph1.AddOneEdge(0, 1, 2);
	graph1.AddOneEdge(0, 2, 2);
	graph1.AddOneEdge(1, 4, 3);
	graph1.AddOneEdge(2, 0, 5);
	graph1.AddOneEdge(2, 3, 6);
	graph1.AddOneEdge(3, 0, 3);
	// 显示有向图的顶点中存储的数据和边的权重
	cout<<"有向图";
	cout<<"广度优先遍历结果：";
	graph1.BFSTraverse(0);	// 调用广度优先遍历函数
	cout<<endl;
	cout<<"递归深度优先遍历结果：";
	graph1.DFSTraverse(0, 0);	// 调用递归深度优先遍历函数
	cout<<endl;
	cout<<"非递归深度优先遍历结果：";
	graph1.DFSTraverse(0);		// 调用非递归深度优先遍历函数
	cout<<endl;
	// 创建无向图
	for (c='E'; c>='A'; c--)
		graph2.AddOneVertex(c);
	graph2.AddOneEdge(0, 1, 2);
	graph2.AddOneEdge(0, 2, 5);
	graph2.AddOneEdge(0, 3, 3);
	graph2.AddOneEdge(1, 4, 3);
	graph2.AddOneEdge(2, 3, 6);
	// 显示无向图的顶点中存储的数据和边的权重
	cout<<"无向图";
	cout<<"广度优先遍历结果：";
	graph2.BFSTraverse(0);	// 调用广度优先遍历函数
	cout<<endl;
	cout<<"递归深度优先遍历结果：";
	graph2.DFSTraverse(0, 0);	// 调用递归深度优先遍历函数
	cout<<endl;
	cout<<"非递归深度优先遍历结果：";
	graph2.DFSTraverse(0);		// 调用非递归深度优先遍历函数
	cout<<endl;
	return 0;
}
