#include <iostream>
#include "LinkQueue.h"	// 3.4.2����ʵ�ֵ����Ӷ�����ģ��
#include "LinkStack.h"	// 3.3.2����ʵ�ֵ�����ջ��ģ��
#include <assert.h>
using namespace std;
// �����ģ��
template<class T>
class LinkedNode {
  template<class T>
  friend class LinkedBinTree;
 public:
  LinkedNode() {	//���캯��
    m_pLeftChild = m_pRightChild = NULL;
  }
  LinkedNode(const T &x) {	//���캯��
    m_pLeftChild = m_pRightChild = NULL;
    m_data = x;
  }
 private:
  T m_data;
  LinkedNode<T> *m_pLeftChild, *m_pRightChild;
};

// ���������������ʾ��ģ��
template<class T>
class LinkedBinTree {
 public:
  LinkedBinTree();	// �����ն�����
  ~LinkedBinTree();	// ɾ��������
  bool IsEmpty();					// �ж϶������Ƿ�Ϊ��
  LinkedNode<T>* CreateRoot(const T &x);	// ��ָ��Ԫ��ֵ���������
  void Clear();		// ��ն�����
  LinkedNode<T>* GetRoot();	// ��ȡ�����
  // ��һ�������Ϊָ���������Ӳ���
  LinkedNode<T>* InsertLeftChild(LinkedNode<T> *pNode, const T &x);
  // ��һ�������Ϊָ�������Һ��Ӳ���
  LinkedNode<T>* InsertRightChild(LinkedNode<T> *pNode, const T &x);
  // �޸�ָ������Ԫ��ֵ
  bool ModifyNodeValue(LinkedNode<T> *pNode, const T &x);
  // ��ȡָ������Ԫ��ֵ
  bool GetNodeValue(LinkedNode<T> *pNode, T &x);
  // ��ȡָ���������ӽ��
  LinkedNode<T>* GetLeftChild(LinkedNode<T> *pNode);
  // ��ȡָ�������Һ��ӽ��
  LinkedNode<T>* GetRightChild(LinkedNode<T> *pNode);
  void PreOrderTraverse(LinkedNode<T>* pNode);// ���ݹ鷽ʽ�������
  void InOrderTraverse(LinkedNode<T>* pNode);// ���ݹ鷽ʽ�������
  void PostOrderTraverse(LinkedNode<T>* pNode);// ���ݹ鷽ʽ�������
  void PreOrderTraverse();	// ���ǵݹ鷽ʽ�������
  void InOrderTraverse();		// ���ǵݹ鷽ʽ�������
  void PostOrderTraverse();	// ���ǵݹ鷽ʽ�������
  void LevelOrderTraverse();	// ���ǵݹ鷽ʽ������
  // ���ǵݹ鷽ʽ��ȡָ������˫�׽��
  LinkedNode<T>* GetParent(LinkedNode<T> *pNode);
  // ɾ����ָ�����Ϊ��������
  void DeleteSubTree(LinkedNode<T> *pNode);
  // ��DeleteSubTree�������ð��ǵݹ鷽ʽɾ����ָ�����Ϊ��������
  void DeleteSubTreeNode(LinkedNode<T> *pNode);
  // ���ǵݹ鷽ʽ���ݹؼ��ֲ��ҽ��
  LinkedNode<T>* SearchByKey(const T &x);
 private:
  LinkedNode<T> *m_pRoot;  //ָ�������ָ��
};
// ʵ�ִ����ն�����
template<class T>
LinkedBinTree<T>::LinkedBinTree() {
  m_pRoot = NULL;	// ��ָ�������ָ����Ϊ��
}

// ʵ����ָ��Ԫ��ֵ���������
template<class T>
LinkedNode<T>* LinkedBinTree<T>::CreateRoot(const T &x) {
  // �����������ԭ�����ڽ�㣬�������
  if (m_pRoot != NULL)	// ��ԭ�ȴ��ڸ���㣬��ֱ�ӽ�������ֵ��Ϊx
    m_pRoot->m_data = x;
  else	// ���򣬴���һ���½����Ϊ�����
    m_pRoot = new LinkedNode<T>(x);
  return m_pRoot;
}

// ��һ�������Ϊָ���������Ӳ���
template<class T>
LinkedNode<T>* LinkedBinTree<T>::InsertLeftChild(LinkedNode<T> *pNode, const T &x) {
  LinkedNode<T> *pNewNode;
  // �Դ������������Ч���ж�
  if (pNode == NULL)
    return NULL;
  // ����һ���½��
  pNewNode = new LinkedNode<T>(x);
  if (pNewNode == NULL)	// �������ڴ�ʧ��
    return NULL;
  // ���½����ΪpNode�����ӣ���������е�����ָ��ָ���½�㣩
  pNode->m_pLeftChild = pNewNode;
  return pNewNode;
}

// ��һ�������Ϊָ�������Һ��Ӳ���
template<class T>
LinkedNode<T>* LinkedBinTree<T>::InsertRightChild(LinkedNode<T> *pNode, const T &x) {
  LinkedNode<T> *pNewNode;
  if (pNode == NULL)		// �Դ������������Ч���ж�
    return NULL;
  // ����һ���½��
  pNewNode = new LinkedNode<T>(x);
  if (pNewNode == NULL)	// �������ڴ�ʧ��
    return NULL;
  // ���½����ΪpNode���Һ��ӣ���������е��Һ���ָ��ָ���½�㣩
  pNode->m_pRightChild = pNewNode;
  return pNewNode;
}
// ���ݹ鷽ʽ�������
template<class T>
void LinkedBinTree<T>::PreOrderTraverse(LinkedNode<T>* pNode) {
  if (pNode == NULL)
    return;
  // �ȷ���pNode
  cout << pNode->m_data << " ";
  // �������������ʽ����pNode��������
  PreOrderTraverse(pNode->m_pLeftChild);
  // ��������������ʽ����pNode��������
  PreOrderTraverse(pNode->m_pRightChild);
}
// ���ǵݹ鷽ʽ�������
template<class T>
void LinkedBinTree<T>::PreOrderTraverse() {
  LinkStack<LinkedNode<T>*> s;
  LinkedNode<T> *pNode = NULL;
  if (m_pRoot == NULL)
    return;
  // ���������ջ
  s.Push(m_pRoot);
  // ջ��Ϊ��ʱѭ��
  while (!s.IsEmpty()) {
    // ջ��Ԫ�س�ջ��������
    s.Pop(pNode);
    cout << pNode->m_data << " ";
    // �������������������������������ջ
    if (pNode->m_pRightChild)
      s.Push(pNode->m_pRightChild);
    // �������������������������������ջ
    if (pNode->m_pLeftChild)
      s.Push(pNode->m_pLeftChild);
  }
}
// ���ݹ鷽ʽ�������
template<class T>
void LinkedBinTree<T>::InOrderTraverse(LinkedNode<T>* pNode) {
  if (pNode == NULL)
    return;
  // �������������ʽ����pNode��������
  InOrderTraverse(pNode->m_pLeftChild);
  // �ٷ���pNode
  cout << pNode->m_data << " ";
  // ��������������ʽ����pNode��������
  InOrderTraverse(pNode->m_pRightChild);
}
// ���ǵݹ鷽ʽ�������
template<class T>
void LinkedBinTree<T>::InOrderTraverse() {
  LinkStack<LinkedNode<T>*> s;
  LinkedNode<T> *pNode = m_pRoot;
  // pNode��Ϊ��ʱѭ��
  while (pNode) {
    // ��pNode��Ϊ��ʱ��������ջ������pNodeָ��������
    while (pNode) {
      s.Push(pNode);
      pNode = pNode->m_pLeftChild;
    }
    //ջ��Ϊ�գ���ջ������ջ�������ʣ���pNodeָ��ȡ��ջ�������Һ���
    while (!s.IsEmpty()) {
      s.Pop(pNode);
      cout << pNode->m_data << " ";
      pNode = pNode->m_pRightChild;
      if (pNode)	// ��ջ����������������������������
        break;
    }
  }
}
// ���ݹ鷽ʽ�������
template<class T>
void LinkedBinTree<T>::PostOrderTraverse(LinkedNode<T>* pNode) {
  if (pNode == NULL)
    return;
  // ���Ժ��������ʽ����pNode��������
  PostOrderTraverse(pNode->m_pLeftChild);
  // ���Ժ��������ʽ����pNode��������
  PostOrderTraverse(pNode->m_pRightChild);
  // ������pNode
  cout << pNode->m_data << " ";
}
// ���ǵݹ鷽ʽ�������
template<class T>
void LinkedBinTree<T>::PostOrderTraverse() {
  LinkStack<LinkedNode<T>*> s;
  LinkedNode<T> *pNode = m_pRoot, *pPreVisitNode = NULL;
  // pNode��Ϊ��ʱѭ��
  while (pNode) {
    // ��pNode��Ϊ��ʱ��������ջ������pNodeָ��������
    while (pNode) {
      s.Push(pNode);
      pNode = pNode->m_pLeftChild;
    }
    while (!s.IsEmpty()) {
      // ��ջ��Ϊ��ʱ��ȡ��ջ��Ԫ��
      s.Top(pNode);
      // ��ջ��Ԫ�ص��Һ���Ϊ�ջ��ѱ����ʣ�����ʵ�ǰջ��Ԫ�أ�����ջ��
      // Ԫ�س�ջ
      if (pNode->m_pRightChild == NULL
          || pNode->m_pRightChild == pPreVisitNode) {
        cout << pNode->m_data << " ";
        s.Pop(pNode);
        pPreVisitNode = pNode;	// ����pNodeΪǰһ�����ʵĽ��
        // ����pNodeΪ�գ���ʾpNode���������������ѷ�����ϣ�������
        // һ��ջ��Ԫ��
        pNode = NULL;
      }
      // ����Ӧ�ȷ���ջ��Ԫ�ص��Һ���
      else {
        pNode = pNode->m_pRightChild;
        break;
      }
    }
  }
}
// ���ǵݹ鷽ʽ������
template<class T>
void LinkedBinTree<T>::LevelOrderTraverse() {
  LinkQueue<LinkedNode<T>*> q;
  LinkedNode<T> *pNode = NULL;
  if (m_pRoot == NULL)	return;
  // ����������
  q.Insert(m_pRoot);
  // �����в�Ϊ��ʱѭ��
  while (!q.IsEmpty()) {
    // ����ͷԪ�س��Ӳ�����
    q.Delete(pNode);
    cout << pNode->m_data << " ";
    // ��������������������������������
    if (pNode->m_pLeftChild)
      q.Insert(pNode->m_pLeftChild);
    // ��������������������������������
    if (pNode->m_pRightChild)
      q.Insert(pNode->m_pRightChild);
  }
}
// ���ǵݹ鷽ʽ��ȡָ������˫�׽��
template<class T>
LinkedNode<T>* LinkedBinTree<T>::GetParent(LinkedNode<T> *pNode) {
  LinkQueue<LinkedNode<T>*> q;
  LinkedNode<T> *pCurNode = NULL;
  // ��ָ�����pNodeΪ����㣬�򷵻ؿ�
  if (pNode == m_pRoot)
    return NULL;
  // ���������ǿ������򷵻ؿ�
  if (m_pRoot == NULL)
    return NULL;
  // ���ǵݹ��������ķ�ʽ����˫�׽��
  // ����������
  q.Insert(m_pRoot);
  // �����в�Ϊ��ʱѭ��
  while (!q.IsEmpty()) {
    // ����ͷԪ�س���
    q.Delete(pCurNode);
    // ���pNode�Ƕ�ͷԪ�صĺ��ӣ��򷵻ض�ͷԪ��
    if (pCurNode->m_pLeftChild == pNode
        || pCurNode->m_pRightChild == pNode)
      return pCurNode;
    // ��������������������������������
    if (pCurNode->m_pLeftChild)
      q.Insert(pCurNode->m_pLeftChild);
    // ��������������������������������
    if (pCurNode->m_pRightChild)
      q.Insert(pCurNode->m_pRightChild);
  }
  return NULL;
}
// ɾ����ָ�����Ϊ��������
template<class T>
void LinkedBinTree<T>::DeleteSubTree(LinkedNode<T> *pNode) {
  LinkedNode<T> *pParentNode = NULL;
  // ��ָ�����Ϊ�գ��򷵻�
  if (pNode == NULL)
    return;
  // �������ö�����ɾ������������Ϊ��
  if (m_pRoot == pNode)
    m_pRoot = NULL;
  // ������ָ��������˫�׽�㣬��˫�׽�������/�Һ����ÿ�
  else if ((pParentNode = GetParent(pNode)) != NULL) {
    if (pParentNode->m_pLeftChild == pNode)
      pParentNode->m_pLeftChild = NULL;
    else
      pParentNode->m_pRightChild = NULL;
  }
  // ����ָ����㲻�Ƕ������еĽ�㣬ֱ�ӷ���
  else
    return;
  // ����DeleteSubTreeNodeɾ����pNodeΪ��������
  DeleteSubTreeNode(pNode);
}

// ��DeleteSubTree�������ð��ǵݹ鷽ʽɾ����ָ�����Ϊ��������
template<class T>
void LinkedBinTree<T>::DeleteSubTreeNode(LinkedNode<T> *pNode) {
  LinkQueue<LinkedNode<T>*> q;
  LinkedNode<T> *pCurNode = NULL;
  if (pNode == NULL)
    return;
  // ���ǵݹ��α����ķ�ʽɾ������
  q.Insert(pNode);
  while (!q.IsEmpty()) {
    q.Delete(pCurNode);
    if (pCurNode->m_pLeftChild)
      q.Insert(pCurNode->m_pLeftChild);
    if (pCurNode->m_pRightChild)
      q.Insert(pCurNode->m_pRightChild);
    delete pCurNode;
  }
}
// ���ǵݹ鷽ʽ���ݹؼ��ֲ��ҽ��
template<class T>
LinkedNode<T>* LinkedBinTree<T>::SearchByKey(const T &x) {
  LinkQueue<LinkedNode<T>*> q;
  LinkedNode<T> *pMatchNode = NULL;
  if (m_pRoot == NULL)	return NULL;
  // ���ǵݹ��α����ķ�ʽ���ҽ��
  q.Insert(m_pRoot);
  while (!q.IsEmpty()) {
    q.Delete(pMatchNode);
    if (pMatchNode->m_data == x)
      return pMatchNode;
    if (pMatchNode->m_pLeftChild)
      q.Insert(pMatchNode->m_pLeftChild);
    if (pMatchNode->m_pRightChild)
      q.Insert(pMatchNode->m_pRightChild);
  }
  return NULL;
}
// ʵ��ɾ��������
template<class T>
LinkedBinTree<T>::~LinkedBinTree() {
  Clear();	// ��ն������еĽ��
}
// ʵ����ն�����
template<class T>
void LinkedBinTree<T>::Clear() {
  DeleteSubTree(m_pRoot);
}
// �ж϶������Ƿ�Ϊ��
template<class T>
bool LinkedBinTree<T>::IsEmpty() {
  if (m_pRoot == NULL)
    return true;
  return false;
}
// ��ȡ�����
template<class T>
LinkedNode<T>* LinkedBinTree<T>::GetRoot() {
  return m_pRoot;
}
// �޸�ָ������Ԫ��ֵ
template<class T>
bool LinkedBinTree<T>::ModifyNodeValue(LinkedNode<T> *pNode, const T &x) {
  if (pNode == NULL)
    return false;
  pNode->m_data = x;
  return true;
}
// ��ȡָ������Ԫ��ֵ
template<class T>
bool LinkedBinTree<T>::GetNodeValue(LinkedNode<T> *pNode, T &x) {
  if (pNode == NULL)
    return false;
  x = pNode->m_data;
  return true;
}
// ��ȡָ���������ӽ��
template<class T>
LinkedNode<T>* LinkedBinTree<T>::GetLeftChild(LinkedNode<T> *pNode) {
  if (pNode == NULL)
    return NULL;
  return pNode->m_pLeftChild;
}
// ��ȡָ�������Һ��ӽ��
template<class T>
LinkedNode<T>* LinkedBinTree<T>::GetRightChild(LinkedNode<T> *pNode) {
  if (pNode == NULL)
    return NULL;
  return pNode->m_pRightChild;
}