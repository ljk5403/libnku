#include <iostream>
//#include "LinkQueue.h"	// 3.4.2����ʵ�ֵ����Ӷ�����ģ��
//#include "LinkStack.h"	// 3.3.2����ʵ�ֵ�����ջ��ģ��
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
//	~LinkedBinTree();	// ɾ��������
//	bool IsEmpty();					// �ж϶������Ƿ�Ϊ��
  LinkedNode<T>* CreateRoot(const T &x);	// ��ָ��Ԫ��ֵ���������
//	void Clear();		// ��ն�����
//	LinkedNode<T>* GetRoot();	// ��ȡ�����
  // ��һ�������Ϊָ���������Ӳ���
  LinkedNode<T>* InsertLeftChild(LinkedNode<T> *pNode, const T &x);
  // ��һ�������Ϊָ�������Һ��Ӳ���
  LinkedNode<T>* InsertRightChild(LinkedNode<T> *pNode, const T &x);
  // �޸�ָ������Ԫ��ֵ
//	bool ModifyNodeValue(LinkedNode<T> *pNode, const T &x);
  // ��ȡָ������Ԫ��ֵ
//	bool GetNodeValue(LinkedNode<T> *pNode, T &x);
  // ��ȡָ���������ӽ��
//	LinkedNode<T>* GetLeftChild(LinkedNode<T> *pNode);
  // ��ȡָ�������Һ��ӽ��
//	LinkedNode<T>* GetRightChild(LinkedNode<T> *pNode);
//	void PreOrderTraverse(LinkedNode<T>* pNode);// ���ݹ鷽ʽ�������
//	void InOrderTraverse(LinkedNode<T>* pNode);// ���ݹ鷽ʽ�������
//	void PostOrderTraverse(LinkedNode<T>* pNode);// ���ݹ鷽ʽ�������
//	void PreOrderTraverse();	// ���ǵݹ鷽ʽ�������
//	void InOrderTraverse();		// ���ǵݹ鷽ʽ�������
//	void PostOrderTraverse();	// ���ǵݹ鷽ʽ�������
//	void LevelOrderTraverse();	// ���ǵݹ鷽ʽ������
  // ���ǵݹ鷽ʽ��ȡָ������˫�׽��
//	LinkedNode<T>* GetParent(LinkedNode<T> *pNode);
  // ɾ����ָ�����Ϊ��������
//	void DeleteSubTree(LinkedNode<T> *pNode);
  // ��DeleteSubTree�������ð��ǵݹ鷽ʽɾ����ָ�����Ϊ��������
//	void DeleteSubTreeNode(LinkedNode<T> *pNode);
  // ���ǵݹ鷽ʽ���ݹؼ��ֲ��ҽ��
//	LinkedNode<T>* SearchByKey(const T &x);
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
