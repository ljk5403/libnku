// 按Dijkstra算法计算从下标为nV的顶点到其余各顶点的最短路径
void ShortestPathDij(int nV, AdjLinkedGraph<char> &graph)
{
	bool bAdded[MAX_VERTEX_NUM];// 记录顶点是否已添加到集合S中
	int nMinDis[MAX_VERTEX_NUM];// 记录从指定顶点到某一顶点的最短路径长度
	int nParent[MAX_VERTEX_NUM];
			// 记录从nV到某一顶点nX的最短路径中，位于nX之前的顶点
	int nI, nJ, nWeight, nAdded=0, nMinPos;
	memset(bAdded, 0, sizeof(bAdded)); // 所有顶点都未在集合S中
	bAdded[nV] = true;	// 将顶点nV加到集合S中
	nAdded++;
	// 将nV到所有顶点的最短路径长度置为无穷大，且当前从nV到nI的最短路径中
	//没有位于nI之前的结点
	for (nI=0; nI<graph.GetVertexNum(); nI++)
	{
		nMinDis[nI] = INFINITY;
		nParent[nI] = -1;
	}
	// D(v0', vi')= w(v0', vi')
	nMinDis[nV] = 0;
	nI = graph.GetFirstEdge(nV);
	while (nI != -1)
	{
		graph.GetEdgeWeight(nV, nI, nMinDis[nI]);
		nParent[nI] = nV;
		nI = graph.GetNextEdge(nV, nI);
	}
	while (nAdded < graph.GetVertexNum())
	//若S中元素数目小于图中顶点数目则一直循环
	{
		// 找到第一个未添加到集合S中的顶点nI
		for (nI=0; nI<graph.GetVertexNum(); nI++)
		{
			if (!bAdded[nI])
				break;
		}
		// 选出当前步骤V-S集合中与顶点nV之间路径长度最短的顶点（即
		//  ），并将其添加到集合S中
		nMinPos = nI;
		for (nI=nMinPos+1; nI<graph.GetVertexNum(); nI++)
		{
			if (bAdded[nI])
				continue;
			if (nMinDis[nI]<nMinDis[nMinPos])
				nMinPos = nI;
		}
		bAdded[nMinPos] = true;
		nAdded++;
		// 对集合V-S中的顶点vi'计算 ，
		// 并将最短路径中位于顶点vi'之前的顶点设置为vj'
		for (nI=0; nI<graph.GetVertexNum(); nI++)
		{
			if (bAdded[nI])
				continue;
			for (nJ=0; nJ<graph.GetVertexNum(); nJ++)
			{
				if (!bAdded[nJ])
					continue;
				if (nMinDis[nJ]!=INFINITY && graph.GetEdgeWeight(nJ, nI, nWeight) 
					&& nMinDis[nI]>nMinDis[nJ]+nWeight)
				{
					nMinDis[nI] = nMinDis[nJ]+nWeight;
					nParent[nI] = nJ;
				}
			}
		}
	}
	// 输出从nV到其余各顶点的最短路径及其长度
	for (nI=0; nI<graph.GetVertexNum(); nI++)
	{
		if (nI==nV)
			continue;
		cout<<"从"<<nV<<"到"<<nI<<"的最短路径为（逆序输出）："<<nI;
		nJ = nI;
		while (nParent[nJ]!=-1)
		{
			cout<<"<-"<<nParent[nJ];
			nJ = nParent[nJ];
		}
		cout<<"，其长度为："<<nMinDis[nI]<<endl;
	}
}
// 按Floyd算法计算图中任一对顶点之间的最短路径
void ShortestPathFloyd(AdjLinkedGraph<char> &graph)
{
	int nParent[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	
	// 记录从顶点nI到顶点nJ的最短路径中位于顶点nJ之前的顶点
	int nMinDis[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	
	// 记录从顶点nI到顶点nJ的最短路径长度
	int nI, nJ, nK;
	// 根据各条边初始化nParent并根据边上的权初始化nMinDis
	for (nI=0; nI<graph.GetVertexNum(); nI++)
	{
		for (nJ=0; nJ<graph.GetVertexNum(); nJ++)
		{
			nMinDis[nI][nJ] = INFINITY;
			nParent[nI][nJ] = -1;
		}
		nMinDis[nI][nI] = 0;
		nJ = graph.GetFirstEdge(nI);
		while (nJ != -1)
		{
			graph.GetEdgeWeight(nI, nJ, nMinDis[nI][nJ]);
			nParent[nI][nJ] = nI;
			nJ = graph.GetNextEdge(nI, nJ);
		}
	}
	// 对于图中每一个顶点vi'（i依次取值为0, 1, …, n-1），若
	// D(vj',vk')>D(vj',vi')+D(vi',vk')，则表明路径(vj', …, vi', …, vk')的长度更短，此时令
	// D(vj',vk')=D(vj',vi')+D(vi',vk')并更新从顶点vj'到顶点vk'的路径
	for (nI=0; nI<graph.GetVertexNum(); nI++)
	{
		for (nJ=0; nJ<graph.GetVertexNum(); nJ++)
		{
			for (nK=0; nK<graph.GetVertexNum(); nK++)
			{
				if (nMinDis[nJ][nI]!=INFINITY && nMinDis[nI][nK]!=INFINITY
					&& nMinDis[nJ][nI]+nMinDis[nI][nK]<nMinDis[nJ][nK])
				{
					nMinDis[nJ][nK] = nMinDis[nJ][nI]+nMinDis[nI][nK];
					nParent[nJ][nK] = nParent[nI][nK];
				}
			}
		}
	}
	// 输出任意一对顶点之间的最短路径及其长度
	for (nI=0; nI<graph.GetVertexNum(); nI++)
	{
		for (nJ=0; nJ<graph.GetVertexNum(); nJ++)
		{
			if (nI==nJ)
				continue;
			cout<<"从"<<nI<<"到"<<nJ<<"的最短路径为（逆序输出）："<<nJ;
			nK = nJ;
			while (nK != nI && nParent[nI][nK]!=-1)
			{
				cout<<"<-"<<nParent[nI][nK];
				nK = nParent[nI][nK];
			}
			cout<<"，其长度为："<<nMinDis[nI][nJ]<<endl;
		}
	}
}
