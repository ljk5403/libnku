#include "LinearList.h"
const int INFINITY=INT_MAX;
const int MAX_VERTEX_NUM=30;
const int MAX_EDGE_NUM=100;
template <class T>
class PackAdjGraph
{
public:
	PackAdjGraph(int nGraphType);	// ����ͼ
	// AdjGraph��ģ����������������Ա����
		bool DFSTraverse(int nV, int);	
					// �Եݹ鷽ʽ���±�ΪnV�Ķ��㿪ʼ��ͼ��������ȱ���
	void DFS(int nV, bool bVisited[]);	
					// ��DFSTraverse�����Եݹ鷽ʽ���ͼ��������ȱ���
	bool DFSTraverse(int nV);		
					// �Էǵݹ鷽ʽ���±�ΪnV�Ķ��㿪ʼ��ͼ��������ȱ���
	bool BFSTraverse(int nV);	// ���±�ΪnV�Ķ��㿪ʼ��ͼ��������ȱ���
	int GetVertexNum();		// ��ȡ������Ŀ
	int GetFirstEdge(int nV);	// ��ȡ��ָ������nV������ĵ�һ����
	int GetNextEdge(int nV1, int nV2);	
		// ��ȡ��ָ����(nV1, nV2)��<nV1, nV2>����ͬ��������nV1����һ����
	bool AddOneVertex(const T &vertex);	// ���һ������
	bool AddOneEdge(int nV1, int nV2, int nWeight);	// ���һ����
	bool GetVertexValue(int nV , T &vertex);	// ��ȡһ�������д洢������
	bool IsEdge(int nV1, int nV2);	// �ж�һ�����Ƿ����
	bool SetEdgeWeight(int nV1,int nV2,int nWeight);	// ����һ���ߵ�Ȩ
	bool GetEdgeWeight(int nV1,int nV2,int&nWeight);	// ��ȡһ���ߵ�Ȩ
private:
	T m_vertex[MAX_VERTEX_NUM];	// ���㼯��
	LinearList<int> m_S;	// ͨ����¼�붥��������Ķ���������߼���
	LinearList<int> m_W;	// m_S�д洢�ĸ����ߵ�Ȩ
	LinearList<int> m_H;	// ��¼���ض�����������ı���m_S�е���ʼ�洢λ��
	int m_nVertexNum;	// ������Ŀ
	int m_nEdgeNum;		// �ߵ���Ŀ
	int m_nGraphType;		// ͼ�����ͣ�������ͼ��������ͼ��
};
// ����ͼ
template <class T>
PackAdjGraph<T>::PackAdjGraph(int nGraphType)
:m_S(MAX_EDGE_NUM), m_W(MAX_EDGE_NUM), m_H(MAX_VERTEX_NUM)
{
	m_nGraphType = nGraphType;
	m_nVertexNum = 0;
	m_nEdgeNum = 0;
}
// ��ȡ������Ŀ
template <class T>
int PackAdjGraph<T>::GetVertexNum()
{
	return m_nVertexNum;
}
// ��ȡ��ָ������nV������ĵ�һ����
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
// ��ȡ��ָ��������ͬ��������nV1����һ����nV1��ĵĶ���
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
// ���һ������
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
// ���һ����
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
	if (m_nGraphType==0)	// ����ͼ
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
// ��ȡһ�������д洢������
template <class T>
bool PackAdjGraph<T>::GetVertexValue(int nV, T &vertex)
{
	if (nV<0 || nV>=m_nVertexNum)
		return false;
	vertex = m_vertex[nV];
	return true;
}
// �ж�һ�����Ƿ����
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
// ����һ���ߵ�Ȩ
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
// ��ȡһ���ߵ�Ȩ
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
