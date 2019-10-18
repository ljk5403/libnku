#include "LinkList.h"
#include "LinkQueue.h"
#include "LinkStack.h"
const int INFINITY = INT_MAX;
const int MAX_VERTEX_NUM = 30;
class LinkedVertex {
  template <class T>
  friend class AdjLinkedGraph;
 private:
  int m_nLinkedVertex;		// ��ָ���������ڽӵĶ���
  int m_nWeight;			// ���������γɵıߵ�Ȩ
};
template <class T>
class AdjLinkedGraph {
 public:
  AdjLinkedGraph(int nGraphType);	// ����ͼ
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
  bool SetEdgeWeight(int nV1, int nV2, int nWeight);	// ����һ���ߵ�Ȩ
  bool GetEdgeWeight(int nV1, int nV2, int&nWeight);	// ��ȡһ���ߵ�Ȩ
 private:
  T m_vertex[MAX_VERTEX_NUM];		// ���㼯��
  LinkList<LinkedVertex> m_LinkedVertex[MAX_VERTEX_NUM];
  // ���ض��������ڽӵĶ�����ɵ�����
  int m_nVertexNum;				// ������Ŀ
  int m_nGraphType;					// ͼ�����ͣ�0������ͼ��1������ͼ��
};
// ����ͼ
template <class T>
AdjLinkedGraph<T>::AdjLinkedGraph(int nGraphType) {
  m_nGraphType = nGraphType;
  m_nVertexNum = 0;
}
// ��ȡ������Ŀ
template <class T>
int AdjLinkedGraph<T>::GetVertexNum() {
  return m_nVertexNum;
}
// ��ȡ��ָ������nV������ĵ�һ����
template <class T>
int AdjLinkedGraph<T>::GetFirstEdge(int nV) {
  LinkedVertex vertex;
  if (nV < 0 || nV >= m_nVertexNum)	// ����������
    return -1;
  if (!m_LinkedVertex[nV].IsEmpty()) {	// ����nV���ڽ�����Ϊ��
    m_LinkedVertex[nV].GetData(1, vertex);// ���ڽ�������ȡ����һ������ֵ
    return vertex.m_nLinkedVertex;
  }
  return -1;
}
// ��ȡ��ָ��������ͬ��������nV1����һ���ߵ�nV1��Ķ���
template <class T>
int AdjLinkedGraph<T>::GetNextEdge(int nV1, int nV2) {
  int nJ;
  LinkedVertex vertex;
  if (nV1 < 0 || nV1 >= m_nVertexNum || nV2 < 0 || nV2 >= m_nVertexNum)
    // ����������
    return -1;
  // ���η��ʶ���nV1�ڽ������е�ÿһ����㣬�ҵ��ڽӶ���ΪnV2�Ľ�㣬��
  // ������д洢���ڽӶ���洢λ�÷���
  for (nJ = 0; nJ < m_LinkedVertex[nV1].GetLength() - 1; nJ++) {
    m_LinkedVertex[nV1].GetData(nJ + 1, vertex);
    if (vertex.m_nLinkedVertex == nV2) {
      m_LinkedVertex[nV1].GetData(nJ + 2, vertex);
      return vertex.m_nLinkedVertex;
    }
  }
  return -1;
}
// ���һ������
template <class T>
bool AdjLinkedGraph<T>::AddOneVertex(const T &vertex) {
  if (m_nVertexNum >= MAX_VERTEX_NUM)
    return false;
  m_vertex[m_nVertexNum] = vertex;
  m_nVertexNum++;
  return true;
}
// ���һ����
template <class T>
bool AdjLinkedGraph<T>::AddOneEdge(int nV1, int nV2, int nWeight) {
  LinkedVertex vertex;
  if (nV1 < 0 || nV1 >= m_nVertexNum || nV2 < 0 || nV2 >= m_nVertexNum
      || IsEdge(nV1, nV2))	// ���������ڣ��Ҷ����ԭ�Ȳ����ڱ�
    return false;
  vertex.m_nLinkedVertex = nV2;	// �������ڽӶ���Ĵ洢λ��
  vertex.m_nWeight = nWeight;	// ���ñߵ�Ȩ
  // ��vertex��Ϊ�½���ֵ���뵽����nV1�ڽ������β��
  m_LinkedVertex[nV1].Insert(m_LinkedVertex[nV1].GetLength() + 1, vertex);
  if (m_nGraphType == 0) {	// ����ͼ��������Ķ���nV2���ڽ�����
    vertex.m_nLinkedVertex = nV1; 	// �������ڽӶ���Ĵ洢λ��
    vertex.m_nWeight = nWeight; 	// ���ñߵ�Ȩ
    // ��vertex��Ϊ�½���ֵ���뵽����nV2�ڽ������β��
    m_LinkedVertex[nV2].Insert(m_LinkedVertex[nV2].GetLength() + 1, vertex);
  }
  return true;
}
// ��ȡһ�������д洢������
template <class T>
bool AdjLinkedGraph<T>::GetVertexValue(int nV, T &vertex) {
  if (nV < 0 || nV >= m_nVertexNum)	// ����������
    return false;
  vertex = m_vertex[nV];
  return true;
}
// �ж�һ�����Ƿ����
template <class T>
bool AdjLinkedGraph<T>::IsEdge(int nV1, int nV2) {
  int nJ;
  LinkedVertex vertex;
  if (nV1 < 0 || nV1 >= m_nVertexNum || nV2 < 0 || nV2 >= m_nVertexNum)
    // ����������
    return false;
  // ���η��ʶ���nV1�ڽ������е�ÿһ����㣬���ҵ��ڽӶ���ΪnV2�Ľ�㣬
  // �򷵻�true�����򷵻�false
  for (nJ = 0; nJ < m_LinkedVertex[nV1].GetLength(); nJ++) {
    m_LinkedVertex[nV1].GetData(nJ + 1, vertex);
    if (vertex.m_nLinkedVertex == nV2)
      return true;
  }
  return false;
}
// ����һ���ߵ�Ȩ
template <class T>
bool AdjLinkedGraph<T>::SetEdgeWeight(int nV1, int nV2, int nWeight) {
  int nJ;
  LinkedVertex vertex;
  if (nV1 < 0 || nV1 >= m_nVertexNum || nV2 < 0 || nV2 >= m_nVertexNum)
    // ����������
    return false;
  // ���η��ʶ���nV1�ڽ������е�ÿһ����㣬���ҵ��ڽӶ���ΪnV2�Ľ�㣬
  // ���޸ĸý�㱣���Ȩ
  for (nJ = 0; nJ < m_LinkedVertex[nV1].GetLength(); nJ++) {
    m_LinkedVertex[nV1].GetData(nJ + 1, vertex);
    if (vertex.m_nLinkedVertex == nV2) {
      vertex.m_nWeight = nWeight;
      m_LinkedVertex[nV1].ModifyData(nJ + 1, vertex);
      return true;
    }
  }
  return false;
}
// ��ȡһ���ߵ�Ȩ
template <class T>
bool AdjLinkedGraph<T>::GetEdgeWeight(int nV1, int nV2, int &nWeight) {
  int nJ;
  LinkedVertex vertex;
  if (nV1 < 0 || nV1 >= m_nVertexNum || nV2 < 0 || nV2 >= m_nVertexNum)
    // ����������
    return false;
  // ���η��ʶ���nV1�ڽ������е�ÿһ����㣬���ҵ��ڽӶ���ΪnV2�Ľ�㣬
  // ���ȡ�ý�㱣���Ȩ
  for (nJ = 0; nJ < m_LinkedVertex[nV1].GetLength(); nJ++) {
    m_LinkedVertex[nV1].GetData(nJ + 1, vertex);
    if (vertex.m_nLinkedVertex == nV2) {
      nWeight = vertex.m_nWeight;
      return true;
    }
  }
  return false;
}
// ���±�ΪnV�Ķ��㿪ʼ��ͼ��������ȱ���
template <class T>
bool AdjLinkedGraph<T>::BFSTraverse(int nV) {
  LinkQueue<int> queue;
  int nVisitVertex, nVertex, nBegVertex = nV;
  bool bVisited[MAX_VERTEX_NUM];	// ��¼һ�������Ƿ��ѷ���
  T vertex;
  // ���±�ΪnV�Ķ��㲻���ڣ������ʧ��
  if (nV < 0 || nV >= m_nVertexNum)
    return false;
  memset(bVisited, 0, sizeof(bVisited)); // �����������Ϊδ����״̬
  while (1) {
    queue.Insert(nBegVertex); // ����һ��Ҫ���ʵĶ������
    bVisited[nBegVertex] = true; // ���øö���Ϊ�ѷ���״̬
    while (!queue.IsEmpty()) {	// ���в�Ϊ����һֱѭ��
      // ����ͷԪ�س��Ӳ�����
      queue.Delete(nVisitVertex);
      GetVertexValue(nVisitVertex, vertex);
      cout << vertex << ' ';
      // ��ȡ���ͷԪ�����ڽ���δ���ʵĶ��㣬��Ӳ���������Ϊ�ѷ���״̬
      nVertex = GetFirstEdge(nVisitVertex);
      while (nVertex != -1) {
        if (bVisited[nVertex] == false) {
          queue.Insert(nVertex);
          bVisited[nVertex] = true;
        }
        nVertex = GetNextEdge(nVisitVertex, nVertex);
      }
    }
    // �ж��Ƿ�����û�з��ʵĶ��㣬������Ӹö��㿪ʼ����������ȱ�������
    // ��ͨͼ���ǿ��ͨͼ�����������������һ�����㿪ʼ�޷���������������
    // ���㣩
    for (nVisitVertex = nBegVertex + 1; nVisitVertex < m_nVertexNum + nV; nVisitVertex++) {
      if (bVisited[nVisitVertex % m_nVertexNum] == false) {
        nBegVertex = nVisitVertex % m_nVertexNum;
        break;
      }
    }
    // ���ж��㶼�ѷ��ʣ��˳�ѭ��
    if (nVisitVertex == m_nVertexNum + nV)
      break;
  }
  return true;
}
// �Եݹ鷽ʽ���±�ΪnV�Ķ��㿪ʼ��ͼ��������ȱ���
template <class T>
bool AdjLinkedGraph<T>::DFSTraverse(int nV, int) {
  int nBegVertex;
  bool bVisited[MAX_VERTEX_NUM];	// ��¼һ�������Ƿ��ѷ���
  // ���±�ΪnV�Ķ��㲻���ڣ������ʧ��
  if (nV < 0 || nV >= m_nVertexNum)
    return false;
  memset(bVisited, 0, sizeof(bVisited)); // �����������Ϊδ����״̬
  // ����ͼ�е�ÿһ�����㣬��Ϊδ����״̬����Ӹö��㿪ʼ����DFS�����԰�
  // ���ö������ͨ��ͼ����������ȱ���
  for (nBegVertex = nV; nBegVertex < m_nVertexNum + nV; nBegVertex++) {
    if (bVisited[nBegVertex % m_nVertexNum] == false)
      DFS(nBegVertex, bVisited);
  }
  return true;
}
// ��DFSTraverse�����Եݹ鷽ʽ���ͼ��������ȱ���
template <class T>
void AdjLinkedGraph<T>::DFS(int nV, bool bVisited[]) {
  T vertex;
  int nVertex;
  // �ȷ��ʵ�ǰ���㣬������״̬����Ϊ�ѷ���
  GetVertexValue(nV, vertex);
  cout << vertex << ' ';
  bVisited[nV] = true;
  // �����ȡ�뵱ǰ�������ڽӵĶ��㣬����ȡ���Ķ���δ���ʣ������DFS����
  // �԰����ö������ͨ��ͼ����������ȱ���
  nVertex = GetFirstEdge(nV);
  while (nVertex != -1) {
    if (bVisited[nVertex] == false)
      DFS(nVertex, bVisited);
    nVertex = GetNextEdge(nV, nVertex);
  }
}
// �Էǵݹ鷽ʽ���±�ΪnV�Ķ��㿪ʼ��ͼ��������ȱ���
template <class T>
bool AdjLinkedGraph<T>::DFSTraverse(int nV) {
  LinkStack<int> s;
  int nPeekVertex, nVertex, nBegVertex = nV, nLastPopVertex = -1;
  bool bVisited[MAX_VERTEX_NUM];	// ��¼һ�������Ƿ��ѷ���
  T vertex;
  // ���±�ΪnV�Ķ��㲻���ڣ������ʧ��
  if (nV < 0 || nV >= m_nVertexNum)
    return false;
  memset(bVisited, 0, sizeof(bVisited)); // �����������Ϊδ����״̬
  while (1) {
    // �ȷ��ʵ�ǰ���㣬���øö���Ϊ�ѷ��ʣ������ö����ջ
    GetVertexValue(nBegVertex, vertex);
    cout << vertex << ' ';
    bVisited[nBegVertex] = true;
    s.Push(nBegVertex);
    while (!s.IsEmpty()) {	// ջ��Ϊ����һֱѭ��
      s.Top(nPeekVertex);	// ��ȡջ��Ԫ��
      while (1) {
        // �ж���ջ��Ԫ�����ڽӵĶ���ԭ���Ƿ��ѷ��ʹ�����δ�������ȡ
        // ջ��Ԫ�ص�һ���ߣ����ѷ���������ϴη��ʵı߻�ȡ��һ����
        if (nLastPopVertex < 0)
          nVertex = GetFirstEdge(nPeekVertex);
        else
          nVertex = GetNextEdge(nPeekVertex, nLastPopVertex);
        // ����������һ���߻����δ���ʵ���һ���ߣ����˳�ѭ��
        if (nVertex == -1 || bVisited[nVertex] == false)
          break;
        // �������ѷ��ʵ���һ���ߣ�������һ����Ϊ��������Ѱ���ٺ����
        // һ����
        nLastPopVertex = nVertex;
      }
      // ����������һ���ߣ���ö����������ͼ���ѷ�����ϣ����ö����ջ
      if (nVertex == -1)
        s.Pop(nLastPopVertex);
      else
        // ������δ���ʵ���һ���ߣ��������ñ����������һ���㲢�����
        // ջ��Ȼ������������ȱ����ķ�ʽ���ʸö���ĸ���ͼ
      {
        GetVertexValue(nVertex, vertex);
        cout << vertex << ' ';
        bVisited[nVertex] = true;
        s.Push(nVertex);
      }
    }
    // �ж��Ƿ�����û�з��ʵĶ��㣬������Ӹö��㿪ʼ����������ȱ�������
    // ��ͨͼ���ǿ��ͨͼ�����������������һ�����㿪ʼ�޷���������������
    // ���㣩
    for (nVertex = nBegVertex + 1; nVertex < m_nVertexNum + nV; nVertex++) {
      if (bVisited[nVertex % m_nVertexNum] == false) {
        nBegVertex = nVertex % m_nVertexNum;
        break;
      }
    }
    // ���ж��㶼�ѷ��ʣ��˳�ѭ��
    if (nVertex == m_nVertexNum + nV)
      break;
  }
  return true;
}
