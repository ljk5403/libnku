#include "LinearList.h"
const int INFINITY=INT_MAX;
const int MAX_VERTEX_NUM=30;
const int MAX_EDGE_NUM=100;
template <class T>
class PackAdjGraph
{
public:
	PackAdjGraph(int nGraphType);	// 创建图
	// AdjGraph类模板中声明的其他成员函数
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
	LinearList<int> m_S;	// 通过记录与顶点相关联的顶点来保存边集合
	LinearList<int> m_W;	// m_S中存储的各条边的权
	LinearList<int> m_H;	// 记录与特定顶点相关联的边在m_S中的起始存储位置
	int m_nVertexNum;	// 顶点数目
	int m_nEdgeNum;		// 边的数目
	int m_nGraphType;		// 图的类型（：无向图，：有向图）
};
// 创建图
template <class T>
PackAdjGraph<T>::PackAdjGraph(int nGraphType)
:m_S(MAX_EDGE_NUM), m_W(MAX_EDGE_NUM), m_H(MAX_VERTEX_NUM)
{
	m_nGraphType = nGraphType;
	m_nVertexNum = 0;
	m_nEdgeNum = 0;
}
// 获取顶点数目
template <class T>
int PackAdjGraph<T>::GetVertexNum()
{
	return m_nVertexNum;
}
// 获取与指定顶点nV相关联的第一条边
template <class T>
int PackAdjGraph<T>::GetFirstEdge(int nV)
{
	int nBegPos, nFirstEdge;
	if (nV<0 || nV>=m_nVertexNum)
		return -1;
	m_H.GetData(nV+1, nBegPos);
	if (nBegPos >= m_nEdgeNum)
		return -1;
	m_S.GetData(nBegPos+1, nFirstEdge);
	return nFirstEdge;
}
// 获取与指定边有相同关联顶点nV1的下一条边nV1外的的顶点
template <class T>
int PackAdjGraph<T>::GetNextEdge(int nV1, int nV2)
{
	int nJ, nBegPos, nEndPos, nV;
	if (!IsEdge(nV1, nV2))
		return -1;
	m_H.GetData(nV1+1, nBegPos);
	if (nV1 < m_nVertexNum-1)
		m_H.GetData(nV1+2, nEndPos);
	else
		nEndPos = m_nEdgeNum;
	for (nJ=nBegPos; nJ<nEndPos-1; nJ++)
	{
		m_S.GetData(nJ+1, nV);
		if (nV2 == nV)
		{
			m_S.GetData(nJ+2, nV);
			return nV;
		}
	}
	return -1;
}
// 添加一个顶点
template <class T>
bool PackAdjGraph<T>::AddOneVertex(const T &vertex)
{
	if (m_nVertexNum >= MAX_VERTEX_NUM)
		return false;
	m_vertex[m_nVertexNum] = vertex;
	m_H.Insert(m_nVertexNum+1, 0);
	m_nVertexNum++;
	return true;
}
// 添加一条边
template <class T>
bool PackAdjGraph<T>::AddOneEdge(int nV1, int nV2, int nWeight)
{
	int nEndPos, nStartPos, nI;
	if (nV1<0 || nV1>=m_nVertexNum || nV2<0 || nV2>=m_nVertexNum
		|| IsEdge(nV1, nV2) || m_nEdgeNum>=MAX_EDGE_NUM)
		return false;
	if (nV1 < m_nVertexNum-1)
		m_H.GetData(nV1+2, nEndPos);
	else
		nEndPos = m_nEdgeNum;
	m_S.Insert(nEndPos+1, nV2);
	m_W.Insert(nEndPos+1, nWeight);
	for (nI=nV1+1; nI<m_nVertexNum; nI++)
	{
		m_H.GetData(nI+1, nStartPos);
		m_H.ModifyData(nI+1, nStartPos+1);
	}
	m_nEdgeNum++;
	if (m_nGraphType==0)	// 无向图
	{
		if (nV2 < m_nVertexNum-1)
			m_H.GetData(nV2+2, nEndPos);
		else
			nEndPos = m_nEdgeNum;
		m_S.Insert(nEndPos+1, nV1);
		m_W.Insert(nEndPos+1, nWeight);
		for (nI=nV2+1; nI<m_nVertexNum; nI++)
		{
			m_H.GetData(nI+1, nStartPos);
			m_H.ModifyData(nI+1, nStartPos+1);
		}
		m_nEdgeNum++;
	}
	return true;
}
// 获取一个顶点中存储的数据
template <class T>
bool PackAdjGraph<T>::GetVertexValue(int nV, T &vertex)
{
	if (nV<0 || nV>=m_nVertexNum)
		return false;
	vertex = m_vertex[nV];
	return true;
}
// 判断一条边是否存在
template <class T>
bool PackAdjGraph<T>::IsEdge(int nV1, int nV2)
{
	int nBegPos, nEndPos, nI, nV;
	m_H.GetData(nV1+1, nBegPos);
	if (nV1 < m_nVertexNum-1)
		m_H.GetData(nV1+2, nEndPos);
	else
		nEndPos = m_nEdgeNum;
	for (nI=nBegPos; nI<nEndPos; nI++)
	{
		m_S.GetData(nI+1, nV);
		if (nV == nV2)
			return true;
	}
	return false;
}
// 设置一条边的权
template <class T>
bool PackAdjGraph<T>::SetEdgeWeight(int nV1, int nV2, int nWeight)
{
	int nBegPos, nEndPos, nI, nV;
	m_H.GetData(nV1+1, nBegPos);
	if (nV1 < m_nVertexNum-1)
		m_H.GetData(nV1+2, nEndPos);
	else
		nEndPos = m_nEdgeNum;
	for (nI=nBegPos; nI<nEndPos; nI++)
	{
		m_S.GetData(nI+1, nV);
		if (nV == nV2)
		{
			m_W.ModifyData(nI+1, nWeight);
			return true;
		}
	}
	return false;
}
// 获取一条边的权
template <class T>
bool PackAdjGraph<T>::GetEdgeWeight(int nV1, int nV2, int &nWeight)
{
	int nBegPos, nEndPos, nI, nV;
	m_H.GetData(nV1+1, nBegPos);
	if (nV1 < m_nVertexNum-1)
		m_H.GetData(nV1+2, nEndPos);
	else
		nEndPos = m_nEdgeNum;
	for (nI=nBegPos; nI<nEndPos; nI++)
	{
		m_S.GetData(nI+1, nV);
		if (nV == nV2)
		{
			m_W.GetData(nI+1, nWeight);
			return true;
		}
	}
	return false;
}
