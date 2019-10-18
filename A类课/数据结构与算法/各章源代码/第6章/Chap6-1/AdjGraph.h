#include <iostream>
#include <assert.h>
using namespace std;
const int INFINITY=INT_MAX;
const int MAX_VERTEX_NUM=30;
template <class T>
class AdjGraph
{
public:
	AdjGraph(int nGraphType);// 创建图
	bool DFSTraverse(int nV, int);	
					// 以递归方式从下标为nV的顶点开始对图作深度优先遍历
	void DFS(int nV, bool bVisited[]);	
					// 由DFSTraverse调用以递归方式完成图的深度优先遍历
	bool DFSTraverse(int nV);		
					// 以非递归方式从下标为nV的顶点开始对图作深度优先遍历
	bool BFSTraverse(int nV);	// 从下标为nV的顶点开始对图作广度优先遍历
	int GetVertexNum();		// 获取顶点数目
	int GetFirstEdge(int nV);	// 获取与指定顶点nV相关联的第一条边
	int GetNextEdge(int nV1, int nV2);	
		// 获取与指定边(nV1, nV2)或<nV1, nV2>有相同关联顶点nV1的下一条边
	bool AddOneVertex(const T &vertex);	// 添加一个顶点
	bool AddOneEdge(int nV1, int nV2, int nWeight);	// 添加一条边
	bool GetVertexValue(int nV , T &vertex);	// 获取一个顶点中存储的数据
	bool IsEdge(int nV1, int nV2);	// 判断一条边是否存在
	bool SetEdgeWeight(int nV1,int nV2,int nWeight);	// 设置一条边的权
	bool GetEdgeWeight(int nV1,int nV2,int&nWeight);	// 获取一条边的权
private:
	T m_vertex[MAX_VERTEX_NUM];	// 顶点集合
	int m_nAdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];// 边集合
	int m_nVertexNum;				// 顶点数目
	int m_nGraphType;					// 图的类型（0：无向图，1：有向图）
};
// 创建图
template <class T>
AdjGraph<T>::AdjGraph(int nGraphType)
{
	int nI, nJ;
	m_nGraphType = nGraphType;
	m_nVertexNum = 0;
	// 将任两个结点之间边上的权置为无穷大，表示初始时没有边
	for (nI=0; nI<MAX_VERTEX_NUM; nI++)
		for (nJ=0; nJ<MAX_VERTEX_NUM; nJ++)
			m_nAdjMatrix[nI][nJ] = INFINITY;
}
// 获取顶点数目
template <class T>
int AdjGraph<T>::GetVertexNum()
{
	return m_nVertexNum;
}
// 获取与指定顶点nV相关联的第一条边
template <class T>
int AdjGraph<T>::GetFirstEdge(int nV)
{
	int nJ;
	if (nV<0 || nV>=m_nVertexNum)
		return -1;
	// 依次访问所有顶点，找到第一条与nV相关联的边
	for (nJ=0; nJ<m_nVertexNum; nJ++)
		if (IsEdge(nV, nJ))
			return nJ;
	return -1;
}
// 获取与指定边(nV1, nV2)或<nV1, nV2>有相同关联顶点nV1的下一条边的nV1外的
// 顶点
template <class T>
int AdjGraph<T>::GetNextEdge(int nV1, int nV2)
{
	int nJ;
	if (!IsEdge(nV1, nV2))
		return -1;
	// 依次访问nV2后面的顶点，找到下一条与nV1关联的边
	for (nJ=nV2+1; nJ<m_nVertexNum; nJ++)
		if (IsEdge(nV1, nJ))
			return nJ;
	return -1;
}
// 添加一个顶点
template <class T>
bool AdjGraph<T>::AddOneVertex(const T &vertex)
{
	if (m_nVertexNum >= MAX_VERTEX_NUM)
		return false;
	m_vertex[m_nVertexNum] = vertex;
	m_nVertexNum++;
	return true;
}
// 添加一条边
template <class T>
bool AdjGraph<T>::AddOneEdge(int nV1, int nV2, int nWeight)
{
	if (nV1<0 || nV1>=m_nVertexNum || nV2<0 || nV2>=m_nVertexNum
		|| IsEdge(nV1, nV2))	// 两个顶点必须存在，且两个顶点间原先没有边
		return false;
	m_nAdjMatrix[nV1][nV2] = nWeight;
	if (m_nGraphType==0)	// 无向图
		m_nAdjMatrix[nV2][nV1] = nWeight;
	return true;
}
// 获取一个顶点中存储的数据
template <class T>
bool AdjGraph<T>::GetVertexValue(int nV, T &vertex)
{
	if (nV<0 || nV>=m_nVertexNum)
		return false;
	vertex = m_vertex[nV];
	return true;
}
// 判断一条边是否存在
template <class T>
bool AdjGraph<T>::IsEdge(int nV1, int nV2)
{
	return m_nAdjMatrix[nV1][nV2]!=INFINITY;	// 权重为有限值，则表明边存在
}
// 设置一条边的权
template <class T>
bool AdjGraph<T>::SetEdgeWeight(int nV1, int nV2, int nWeight)
{
	if (!IsEdge(nV1, nV2))
		return false;
	m_nAdjMatrix[nV1][nV2] = nWeight;
	return true;
}
// 获取一条边的权
template <class T>
bool AdjGraph<T>::GetEdgeWeight(int nV1, int nV2, int &nWeight)
{
	if (!IsEdge(nV1, nV2))
		return false;
	nWeight = m_nAdjMatrix[nV1][nV2];
	return true;
}
