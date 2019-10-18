#include "LinkList.h"
#include "LinkQueue.h"
#include "LinkStack.h"
const int INFINITY=INT_MAX;
const int MAX_VERTEX_NUM=30;
class LinkedVertex
{
	template <class T>
	friend class AdjLinkedGraph;
private:
	int m_nLinkedVertex;		// 与指定顶点相邻接的顶点
	int m_nWeight;			// 两个顶点形成的边的权
};
template <class T>
class AdjLinkedGraph
{
public:
	AdjLinkedGraph(int nGraphType);	// 创建图
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
	T m_vertex[MAX_VERTEX_NUM];		// 顶点集合
	LinkList<LinkedVertex> m_LinkedVertex[MAX_VERTEX_NUM];	
									// 与特定顶点相邻接的顶点组成的链表
	int m_nVertexNum;				// 顶点数目
	int m_nGraphType;					// 图的类型（0：无向图，1：有向图）
};
// 创建图
template <class T>
AdjLinkedGraph<T>::AdjLinkedGraph(int nGraphType)
{
	m_nGraphType = nGraphType;
	m_nVertexNum = 0;
}
// 获取顶点数目
template <class T>
int AdjLinkedGraph<T>::GetVertexNum()
{
	return m_nVertexNum;
}
// 获取与指定顶点nV相关联的第一条边
template <class T>
int AdjLinkedGraph<T>::GetFirstEdge(int nV)
{
	LinkedVertex vertex;
	if (nV<0 || nV>=m_nVertexNum)	// 顶点必须存在
		return -1;
	if (!m_LinkedVertex[nV].IsEmpty())	// 顶点nV的邻接链表不为空
	{
		m_LinkedVertex[nV].GetData(1, vertex);// 从邻接链表中取出第一个结点的值
		return vertex.m_nLinkedVertex;
	}
	return -1;
}
// 获取与指定边有相同关联顶点nV1的下一条边的nV1外的顶点
template <class T>
int AdjLinkedGraph<T>::GetNextEdge(int nV1, int nV2)
{
	int nJ;
	LinkedVertex vertex;
	if (nV1<0 || nV1>=m_nVertexNum || nV2<0 || nV2>=m_nVertexNum)
													// 顶点必须存在
		return -1;
	// 依次访问顶点nV1邻接链表中的每一个结点，找到邻接顶点为nV2的结点，将
	// 其后结点中存储的邻接顶点存储位置返回
	for (nJ=0; nJ<m_LinkedVertex[nV1].GetLength()-1; nJ++)
	{
		m_LinkedVertex[nV1].GetData(nJ+1, vertex);
		if (vertex.m_nLinkedVertex==nV2)
		{
			m_LinkedVertex[nV1].GetData(nJ+2, vertex);
			return vertex.m_nLinkedVertex;
		}
	}
	return -1;
}
// 添加一个顶点
template <class T>
bool AdjLinkedGraph<T>::AddOneVertex(const T &vertex)
{
	if (m_nVertexNum >= MAX_VERTEX_NUM)
		return false;
	m_vertex[m_nVertexNum] = vertex;
	m_nVertexNum++;
	return true;
}
// 添加一条边
template <class T>
bool AdjLinkedGraph<T>::AddOneEdge(int nV1, int nV2, int nWeight)
{
	LinkedVertex vertex;
	if (nV1<0 || nV1>=m_nVertexNum || nV2<0 || nV2>=m_nVertexNum
		|| IsEdge(nV1, nV2))	// 顶点必须存在，且顶点间原先不存在边
		return false;
	vertex.m_nLinkedVertex = nV2;	// 设置相邻接顶点的存储位置
	vertex.m_nWeight = nWeight;	// 设置边的权
	// 将vertex作为新结点的值插入到顶点nV1邻接链表的尾部
	m_LinkedVertex[nV1].Insert(m_LinkedVertex[nV1].GetLength()+1, vertex);
	if (m_nGraphType==0)	// 无向图，则还需更改顶点nV2的邻接链表
	{
		vertex.m_nLinkedVertex = nV1; 	// 设置相邻接顶点的存储位置
		vertex.m_nWeight = nWeight; 	// 设置边的权
		// 将vertex作为新结点的值插入到顶点nV2邻接链表的尾部
		m_LinkedVertex[nV2].Insert(m_LinkedVertex[nV2].GetLength()+1, vertex);
	}
	return true;
}
// 获取一个顶点中存储的数据
template <class T>
bool AdjLinkedGraph<T>::GetVertexValue(int nV, T &vertex)
{
	if (nV<0 || nV>=m_nVertexNum)	// 顶点必须存在
		return false;
	vertex = m_vertex[nV];
	return true;
}
// 判断一条边是否存在
template <class T>
bool AdjLinkedGraph<T>::IsEdge(int nV1, int nV2)
{
	int nJ;
	LinkedVertex vertex;
	if (nV1<0 || nV1>=m_nVertexNum || nV2<0 || nV2>=m_nVertexNum)
													// 顶点必须存在
		return false;
	// 依次访问顶点nV1邻接链表中的每一个结点，若找到邻接顶点为nV2的结点，
	// 则返回true；否则返回false
	for (nJ=0; nJ<m_LinkedVertex[nV1].GetLength(); nJ++)
	{
		m_LinkedVertex[nV1].GetData(nJ+1, vertex);
		if (vertex.m_nLinkedVertex==nV2)
			return true;
	}
	return false;
}
// 设置一条边的权
template <class T>
bool AdjLinkedGraph<T>::SetEdgeWeight(int nV1, int nV2, int nWeight)
{
	int nJ;
	LinkedVertex vertex;
	if (nV1<0 || nV1>=m_nVertexNum || nV2<0 || nV2>=m_nVertexNum)
													// 顶点必须存在
		return false;
	// 依次访问顶点nV1邻接链表中的每一个结点，若找到邻接顶点为nV2的结点，
	// 则修改该结点保存的权
	for (nJ=0; nJ<m_LinkedVertex[nV1].GetLength(); nJ++)
	{
		m_LinkedVertex[nV1].GetData(nJ+1, vertex);
		if (vertex.m_nLinkedVertex==nV2)
		{
			vertex.m_nWeight = nWeight;
			m_LinkedVertex[nV1].ModifyData(nJ+1, vertex);
			return true;
		}
	}
	return false;
}
// 获取一条边的权
template <class T>
bool AdjLinkedGraph<T>::GetEdgeWeight(int nV1, int nV2, int &nWeight)
{
	int nJ;
	LinkedVertex vertex;
	if (nV1<0 || nV1>=m_nVertexNum || nV2<0 || nV2>=m_nVertexNum)
													// 顶点必须存在
		return false;
	// 依次访问顶点nV1邻接链表中的每一个结点，若找到邻接顶点为nV2的结点，
	// 则获取该结点保存的权
	for (nJ=0; nJ<m_LinkedVertex[nV1].GetLength(); nJ++)
	{
		m_LinkedVertex[nV1].GetData(nJ+1, vertex);
		if (vertex.m_nLinkedVertex==nV2)
		{
			nWeight = vertex.m_nWeight;
			return true;
		}
	}
	return false;
}
