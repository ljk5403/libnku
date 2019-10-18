// ��Prim�㷨���±�ΪnV�Ķ��㿪ʼ������С������
template <class T>
void GetMinWeightEdge(AdjLinkedGraph<T> &graph, AdjLinkedGraph<T> &tree, bool bAddToTree[], int &nV1, int &nV2);
template <class T>
bool MSTPrim(int nV, AdjLinkedGraph<T> &graph, AdjLinkedGraph<T> &tree)
{
	bool bAddToTree[MAX_VERTEX_NUM];	// ��¼�����Ƿ��ѱ��ӵ�����
	T vertex;
	int nVertex1, nVertex2, nVertexNum=0, nI, nWeight;
	// ��nV����ͼ�ж��㣬�����ʧ��
	if (nV<0 || nV>graph.GetVertexNum())
		return false;
	memset(bAddToTree, 0, sizeof(bAddToTree)); // ���ж��㶼��������
	// ����һ������ԭͼ�����ж��㵫û���καߵ���ͼ������Ϊ�˲������㽫ͼ��
	//���ж��㶼�ӵ����У����ж�һ�������Ƿ��Ѽӵ�����ʵ���Ǹ���bAddToTree
	//�е�Ԫ��ֵ��ȷ����
	for (nI=0; nI<graph.GetVertexNum(); nI++)
	{
		graph.GetVertexValue(nI, vertex);
		tree.AddOneVertex(vertex);
	}
	bAddToTree[nV] = true;	// ���±�ΪnV�Ķ���ӵ�����
	nVertexNum++;
	while (nVertexNum<graph.GetVertexNum())// �����ж���û�ӵ�������һֱѭ��
	{
		// ����GetMinWeightEdge�������Ѽӵ����ж��㵽δ�ӵ����ж���ı���
		//��ȡ������СȨ�ı�
		GetMinWeightEdge(graph, tree, bAddToTree, nVertex1, nVertex2); 
		// ����ȡ�����ߣ���˵��ԭͼ�Ƿ���ͨͼ���ǿ��ͨͼ����������С������
		if (nVertex1 == -1)
			return false;
		// ���ñ���ӵ����У�������ñ��������δ�ӵ����е��Ǹ�����ӵ�����
		graph.GetEdgeWeight(nVertex1, nVertex2, nWeight);
		tree.AddOneEdge(nVertex1, nVertex2, nWeight);
		bAddToTree[nVertex2] = true;
		nVertexNum++;
	}
	return true;
}
// ���Ѽӵ����ж��㵽δ�ӵ����ж���ı��л�ȡ������СȨ�ı�
template <class T>
void GetMinWeightEdge(AdjLinkedGraph<T> &graph, AdjLinkedGraph<T> &tree, bool bAddToTree[], int &nV1, int &nV2)
{
	int nI, nJ, nMinWeight=INFINITY, nWeight;
	nV1 = nV2 = -1;
	for (nI=0; nI<tree.GetVertexNum(); nI++)
	{
		// �����е�ÿ���������bAddToTree�ж����Ƿ��Ѽӵ����У�
		//����δ�ӵ����У��򲻽��д���
		if (!bAddToTree[nI])
			continue;
		// ��ȡ�����ж������ڽӵĶ��㣬���ö���δ�ӵ����У����ж����Ƿ��Ǵ�
		//�Ѽӵ����ж��㵽δ�ӵ����ж���ı��о�����СȨ�ı�
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
	// �˳�ѭ����(nV1,nV2)��<nV1,nV2>���Ǵ��Ѽӵ����ж��㵽δ�ӵ����ж���
	// �ı��о�����СȨ�ı�
}
int GetRoot(int nParent[], int nV);
template <class T>
void GetMinWeightEdge(AdjLinkedGraph<T> &graph, AdjLinkedGraph<T> &tree, bool bVisited[][MAX_VERTEX_NUM], int nParent[], int &nV1, int &nV2);
// ��Kruskal�㷨���±�ΪnV�Ķ��㿪ʼ������С������
template <class T>
bool MSTKruskal(int nV, AdjLinkedGraph<T> &graph, AdjLinkedGraph<T> &tree)
{
	bool bVisited[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
												// ��¼���Ƿ��Ѽӵ�����
	int nParent[MAX_VERTEX_NUM];	// ��¼����ĳһ����˫�׽�㣨�����ж�
	//������ͨ�ԣ�������������ͬ���ĸ�������������������ͬһ�����У�
	T vertex;
	int nVertex1, nVertex2, nEdgeNum=0, nI, nWeight;
	// ��nV����ͼ�ж��㣬�����ʧ��
	if (nV<0 || nV>graph.GetVertexNum())
		return false;
	// ��ʼ���ж��㶼�ڲ�ͬ��������Ϊ�����
	for (nI=0; nI<MAX_VERTEX_NUM; nI++)
		nParent[nI] = -1;
	memset(bVisited, 0, sizeof(bVisited));	// ��ʼ���б߶�δ��ӵ�����
	// �����ж�����ӵ�����
	for (nI=0; nI<graph.GetVertexNum(); nI++)
	{
		graph.GetVertexValue(nI, vertex);
		tree.AddOneVertex(vertex);
	}
	// �����б���С��ͼ�ж�����-1��һֱѭ��
	while (nEdgeNum<graph.GetVertexNum()-1)
	{
		// ��δ����ӵ����еı��л�ȡ������СȨ��
		//��(nVertex1,nVertex2)��<nVertex1,nVertex2>
		GetMinWeightEdge(graph, tree, bVisited, nParent, nVertex1, nVertex2);
		// δ��ȡ���ߣ������ԭͼ�Ƿ���ͨͼ���ǿ��ͨͼ����������С������
		if (nVertex1 == -1)
			return false;
		// ��������СȨ�ı���ӵ����У�������nVertex2��˫�׽��ΪnVertex1
		graph.GetEdgeWeight(nVertex1, nVertex2, nWeight);
		tree.AddOneEdge(nVertex1, nVertex2, nWeight);
		nParent[nVertex2] = nVertex1;
		bVisited[nVertex1][nVertex2] = true;
		nEdgeNum++;
	}
	return true;
}
// ��ȡָ�����ĸ����
int GetRoot(int nParent[], int nV)
{
	// ���ϻ�ȡ˫�׽�㣬ֱ����������㣨��û��˫�׽��Ľ�㣩
	while (nParent[nV]!=-1)
		nV = nParent[nV];
	return nV;
}
// ��δ����ӵ����еı��л�ȡ������СȨ�ı�
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
			// ����(nI,nJ)��<nI,nJ>δ����ӵ����У��Ҷ���nI�Ͷ���nJ����һ����
			// �У�����������ͬ����㣩�����жϸñ��Ƿ���δ����ӵ����еı���
			// ������СȨ�ı�
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
	// �˳�ѭ����(nV1,nV2)��<nV1,nV2>����δ����ӵ����ı��о�����СȨ�ı�
}
