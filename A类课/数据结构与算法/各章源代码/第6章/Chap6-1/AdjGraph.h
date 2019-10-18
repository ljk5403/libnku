#include <iostream>
#include <assert.h>
using namespace std;
const int INFINITY=INT_MAX;
const int MAX_VERTEX_NUM=30;
template <class T>
class AdjGraph
{
public:
	AdjGraph(int nGraphType);// ����ͼ
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
	int m_nAdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];// �߼���
	int m_nVertexNum;				// ������Ŀ
	int m_nGraphType;					// ͼ�����ͣ�0������ͼ��1������ͼ��
};
// ����ͼ
template <class T>
AdjGraph<T>::AdjGraph(int nGraphType)
{
	int nI, nJ;
	m_nGraphType = nGraphType;
	m_nVertexNum = 0;
	// �����������֮����ϵ�Ȩ��Ϊ����󣬱�ʾ��ʼʱû�б�
	for (nI=0; nI<MAX_VERTEX_NUM; nI++)
		for (nJ=0; nJ<MAX_VERTEX_NUM; nJ++)
			m_nAdjMatrix[nI][nJ] = INFINITY;
}
// ��ȡ������Ŀ
template <class T>
int AdjGraph<T>::GetVertexNum()
{
	return m_nVertexNum;
}
// ��ȡ��ָ������nV������ĵ�һ����
template <class T>
int AdjGraph<T>::GetFirstEdge(int nV)
{
	int nJ;
	if (nV<0 || nV>=m_nVertexNum)
		return -1;
	// ���η������ж��㣬�ҵ���һ����nV������ı�
	for (nJ=0; nJ<m_nVertexNum; nJ++)
		if (IsEdge(nV, nJ))
			return nJ;
	return -1;
}
// ��ȡ��ָ����(nV1, nV2)��<nV1, nV2>����ͬ��������nV1����һ���ߵ�nV1���
// ����
template <class T>
int AdjGraph<T>::GetNextEdge(int nV1, int nV2)
{
	int nJ;
	if (!IsEdge(nV1, nV2))
		return -1;
	// ���η���nV2����Ķ��㣬�ҵ���һ����nV1�����ı�
	for (nJ=nV2+1; nJ<m_nVertexNum; nJ++)
		if (IsEdge(nV1, nJ))
			return nJ;
	return -1;
}
// ���һ������
template <class T>
bool AdjGraph<T>::AddOneVertex(const T &vertex)
{
	if (m_nVertexNum >= MAX_VERTEX_NUM)
		return false;
	m_vertex[m_nVertexNum] = vertex;
	m_nVertexNum++;
	return true;
}
// ���һ����
template <class T>
bool AdjGraph<T>::AddOneEdge(int nV1, int nV2, int nWeight)
{
	if (nV1<0 || nV1>=m_nVertexNum || nV2<0 || nV2>=m_nVertexNum
		|| IsEdge(nV1, nV2))	// �������������ڣ������������ԭ��û�б�
		return false;
	m_nAdjMatrix[nV1][nV2] = nWeight;
	if (m_nGraphType==0)	// ����ͼ
		m_nAdjMatrix[nV2][nV1] = nWeight;
	return true;
}
// ��ȡһ�������д洢������
template <class T>
bool AdjGraph<T>::GetVertexValue(int nV, T &vertex)
{
	if (nV<0 || nV>=m_nVertexNum)
		return false;
	vertex = m_vertex[nV];
	return true;
}
// �ж�һ�����Ƿ����
template <class T>
bool AdjGraph<T>::IsEdge(int nV1, int nV2)
{
	return m_nAdjMatrix[nV1][nV2]!=INFINITY;	// Ȩ��Ϊ����ֵ��������ߴ���
}
// ����һ���ߵ�Ȩ
template <class T>
bool AdjGraph<T>::SetEdgeWeight(int nV1, int nV2, int nWeight)
{
	if (!IsEdge(nV1, nV2))
		return false;
	m_nAdjMatrix[nV1][nV2] = nWeight;
	return true;
}
// ��ȡһ���ߵ�Ȩ
template <class T>
bool AdjGraph<T>::GetEdgeWeight(int nV1, int nV2, int &nWeight)
{
	if (!IsEdge(nV1, nV2))
		return false;
	nWeight = m_nAdjMatrix[nV1][nV2];
	return true;
}
