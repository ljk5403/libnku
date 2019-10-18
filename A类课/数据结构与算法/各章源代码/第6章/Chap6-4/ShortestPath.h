// ��Dijkstra�㷨������±�ΪnV�Ķ��㵽�������������·��
void ShortestPathDij(int nV, AdjLinkedGraph<char> &graph)
{
	bool bAdded[MAX_VERTEX_NUM];// ��¼�����Ƿ�����ӵ�����S��
	int nMinDis[MAX_VERTEX_NUM];// ��¼��ָ�����㵽ĳһ��������·������
	int nParent[MAX_VERTEX_NUM];
			// ��¼��nV��ĳһ����nX�����·���У�λ��nX֮ǰ�Ķ���
	int nI, nJ, nWeight, nAdded=0, nMinPos;
	memset(bAdded, 0, sizeof(bAdded)); // ���ж��㶼δ�ڼ���S��
	bAdded[nV] = true;	// ������nV�ӵ�����S��
	nAdded++;
	// ��nV�����ж�������·��������Ϊ������ҵ�ǰ��nV��nI�����·����
	//û��λ��nI֮ǰ�Ľ��
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
	//��S��Ԫ����ĿС��ͼ�ж�����Ŀ��һֱѭ��
	{
		// �ҵ���һ��δ��ӵ�����S�еĶ���nI
		for (nI=0; nI<graph.GetVertexNum(); nI++)
		{
			if (!bAdded[nI])
				break;
		}
		// ѡ����ǰ����V-S�������붥��nV֮��·��������̵Ķ��㣨��
		//  ������������ӵ�����S��
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
		// �Լ���V-S�еĶ���vi'���� ��
		// �������·����λ�ڶ���vi'֮ǰ�Ķ�������Ϊvj'
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
	// �����nV���������������·�����䳤��
	for (nI=0; nI<graph.GetVertexNum(); nI++)
	{
		if (nI==nV)
			continue;
		cout<<"��"<<nV<<"��"<<nI<<"�����·��Ϊ�������������"<<nI;
		nJ = nI;
		while (nParent[nJ]!=-1)
		{
			cout<<"<-"<<nParent[nJ];
			nJ = nParent[nJ];
		}
		cout<<"���䳤��Ϊ��"<<nMinDis[nI]<<endl;
	}
}
// ��Floyd�㷨����ͼ����һ�Զ���֮������·��
void ShortestPathFloyd(AdjLinkedGraph<char> &graph)
{
	int nParent[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	
	// ��¼�Ӷ���nI������nJ�����·����λ�ڶ���nJ֮ǰ�Ķ���
	int nMinDis[MAX_VERTEX_NUM][MAX_VERTEX_NUM];	
	// ��¼�Ӷ���nI������nJ�����·������
	int nI, nJ, nK;
	// ���ݸ����߳�ʼ��nParent�����ݱ��ϵ�Ȩ��ʼ��nMinDis
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
	// ����ͼ��ÿһ������vi'��i����ȡֵΪ0, 1, ��, n-1������
	// D(vj',vk')>D(vj',vi')+D(vi',vk')�������·��(vj', ��, vi', ��, vk')�ĳ��ȸ��̣���ʱ��
	// D(vj',vk')=D(vj',vi')+D(vi',vk')�����´Ӷ���vj'������vk'��·��
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
	// �������һ�Զ���֮������·�����䳤��
	for (nI=0; nI<graph.GetVertexNum(); nI++)
	{
		for (nJ=0; nJ<graph.GetVertexNum(); nJ++)
		{
			if (nI==nJ)
				continue;
			cout<<"��"<<nI<<"��"<<nJ<<"�����·��Ϊ�������������"<<nJ;
			nK = nJ;
			while (nK != nI && nParent[nI][nK]!=-1)
			{
				cout<<"<-"<<nParent[nI][nK];
				nK = nParent[nI][nK];
			}
			cout<<"���䳤��Ϊ��"<<nMinDis[nI][nJ]<<endl;
		}
	}
}
