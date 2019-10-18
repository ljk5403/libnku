// 按Prim算法从下标为nV的顶点开始计算最小生成树
template <class T>
void GetMinWeightEdge(AdjLinkedGraph<T> &graph, AdjLinkedGraph<T> &tree, bool bAddToTree[], int &nV1, int &nV2);
template <class T>
bool MSTPrim(int nV, AdjLinkedGraph<T> &graph, AdjLinkedGraph<T> &tree)
{
	bool bAddToTree[MAX_VERTEX_NUM];	// 记录顶点是否已被加到树中
	T vertex;
	int nVertex1, nVertex2, nVertexNum=0, nI, nWeight;
	// 若nV不是图中顶点，则计算失败
	if (nV<0 || nV>graph.GetVertexNum())
		return false;
	memset(bAddToTree, 0, sizeof(bAddToTree)); // 所有顶点都不在树中
	// 构建一个包含原图中所有顶点但没有任何边的子图（这里为了操作方便将图中
	//所有顶点都加到树中，但判断一个顶点是否已加到树中实际是根据bAddToTree
	//中的元素值来确定）
	for (nI=0; nI<graph.GetVertexNum(); nI++)
	{
		graph.GetVertexValue(nI, vertex);
		tree.AddOneVertex(vertex);
	}
	bAddToTree[nV] = true;	// 将下标为nV的顶点加到树中
	nVertexNum++;
	while (nVertexNum<graph.GetVertexNum())// 若仍有顶点没加到树中则一直循环
	{
		// 调用GetMinWeightEdge函数从已加到树中顶点到未加到树中顶点的边中
		//获取具有最小权的边
		GetMinWeightEdge(graph, tree, bAddToTree, nVertex1, nVertex2); 
		// 若获取不到边，则说明原图是非连通图或非强连通图，不存在最小生成树
		if (nVertex1 == -1)
			return false;
		// 将该边添加到树中，并将与该边相关联的未加到树中的那个顶点加到树中
		graph.GetEdgeWeight(nVertex1, nVertex2, nWeight);
		tree.AddOneEdge(nVertex1, nVertex2, nWeight);
		bAddToTree[nVertex2] = true;
		nVertexNum++;
	}
	return true;
}
// 从已加到树中顶点到未加到树中顶点的边中获取具有最小权的边
template <class T>
void GetMinWeightEdge(AdjLinkedGraph<T> &graph, AdjLinkedGraph<T> &tree, bool bAddToTree[], int &nV1, int &nV2)
{
	int nI, nJ, nMinWeight=INFINITY, nWeight;
	nV1 = nV2 = -1;
	for (nI=0; nI<tree.GetVertexNum(); nI++)
	{
		// 对树中的每个顶点根据bAddToTree判断其是否已加到树中，
		//若还未加到树中，则不进行处理
		if (!bAddToTree[nI])
			continue;
		// 获取与树中顶点相邻接的顶点，若该顶点未加到树中，则判断其是否是从
		//已加到树中顶点到未加到树中顶点的边中具有最小权的边
		nJ = graph.GetFirstEdge(nI);
		while (nJ >= 0)
		{
			if (!bAddToTree[nJ])
			{
				graph.GetEdgeWeight(nI, nJ, nWeight);
				if (nMinWeight > nWeight)
				{
					nMinWeight = nWeight;
					nV1 = nI;
					nV2 = nJ;
				}
			}
			nJ = graph.GetNextEdge(nI, nJ);
		}
	}
	// 退出循环后，(nV1,nV2)或<nV1,nV2>就是从已加到树中顶点到未加到树中顶点
	// 的边中具有最小权的边
}
int GetRoot(int nParent[], int nV);
template <class T>
void GetMinWeightEdge(AdjLinkedGraph<T> &graph, AdjLinkedGraph<T> &tree, bool bVisited[][MAX_VERTEX_NUM], int nParent[], int &nV1, int &nV2);
// 按Kruskal算法从下标为nV的顶点开始计算最小生成树
template <class T>
bool MSTKruskal(int nV, AdjLinkedGraph<T> &graph, AdjLinkedGraph<T> &tree)
{
	bool bVisited[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
												// 记录边是否已加到树中
	int nParent[MAX_VERTEX_NUM];	// 记录树中某一结点的双亲结点（用于判断
	//结点的连通性，若两个结点具有同样的根，则表明这两个结点在同一棵树中）
	T vertex;
	int nVertex1, nVertex2, nEdgeNum=0, nI, nWeight;
	// 若nV不是图中顶点，则计算失败
	if (nV<0 || nV>graph.GetVertexNum())
		return false;
	// 初始所有顶点都在不同的树中作为根结点
	for (nI=0; nI<MAX_VERTEX_NUM; nI++)
		nParent[nI] = -1;
	memset(bVisited, 0, sizeof(bVisited));	// 初始所有边都未添加到树中
	// 将所有顶点添加到树中
	for (nI=0; nI<graph.GetVertexNum(); nI++)
	{
		graph.GetVertexValue(nI, vertex);
		tree.AddOneVertex(vertex);
	}
	// 若树中边数小于图中顶点数-1则一直循环
	while (nEdgeNum<graph.GetVertexNum()-1)
	{
		// 从未被添加到树中的边中获取具有最小权的
		//边(nVertex1,nVertex2)或<nVertex1,nVertex2>
		GetMinWeightEdge(graph, tree, bVisited, nParent, nVertex1, nVertex2);
		// 未获取到边，则表明原图是非连通图或非强连通图，不存在最小生成树
		if (nVertex1 == -1)
			return false;
		// 将具有最小权的边添加到树中，并设置nVertex2的双亲结点为nVertex1
		graph.GetEdgeWeight(nVertex1, nVertex2, nWeight);
		tree.AddOneEdge(nVertex1, nVertex2, nWeight);
		nParent[nVertex2] = nVertex1;
		bVisited[nVertex1][nVertex2] = true;
		nEdgeNum++;
	}
	return true;
}
// 获取指定结点的根结点
int GetRoot(int nParent[], int nV)
{
	// 不断获取双亲结点，直到遇到根结点（即没有双亲结点的结点）
	while (nParent[nV]!=-1)
		nV = nParent[nV];
	return nV;
}
// 从未被添加到树中的边中获取具有最小权的边
template <class T>
void GetMinWeightEdge(AdjLinkedGraph<T> &graph, AdjLinkedGraph<T> &tree, bool bVisited[][MAX_VERTEX_NUM], int nParent[], int &nV1, int &nV2)
{
	int nI, nJ, nMinWeight=INFINITY, nWeight;
	nV1 = nV2 = -1;
	for (nI=0; nI<tree.GetVertexNum(); nI++)
	{
		nJ = graph.GetFirstEdge(nI);
		while (nJ >= 0)
		{
			// 若边(nI,nJ)或<nI,nJ>未被添加到树中，且顶点nI和顶点nJ不在一棵树
			// 中（即不具有相同根结点），则判断该边是否是未被添加到树中的边中
			// 具有最小权的边
			if (!bVisited[nI][nJ] && GetRoot(nParent, nI)!=GetRoot(nParent, nJ))
			{
				graph.GetEdgeWeight(nI, nJ, nWeight);
				if (nMinWeight > nWeight)
				{
					nMinWeight = nWeight;
					nV1 = nI;
					nV2 = nJ;
				}
			}
			nJ = graph.GetNextEdge(nI, nJ);
		}
	}
	// 退出循环后，(nV1,nV2)或<nV1,nV2>就是未被添加到树的边中具有最小权的边
}
