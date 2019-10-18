#include <iostream>
//#include "LinkQueue.h"	// 3.4.2节中实现的链接队列类模板
//#include "LinkStack.h"	// 3.3.2节中实现的链接栈类模板
#include <assert.h>
using namespace std;
// 结点类模板
template<class T>
class LinkedNode {
  template<class T>
  friend class LinkedBinTree;
 public:
  LinkedNode() {	//构造函数
    m_pLeftChild = m_pRightChild = NULL;
  }
  LinkedNode(const T &x) {	//构造函数
    m_pLeftChild = m_pRightChild = NULL;
    m_data = x;
  }
 private:
  T m_data;
  LinkedNode<T> *m_pLeftChild, *m_pRightChild;
};

// 二叉树二叉链表表示类模板
template<class T>
class LinkedBinTree {
 public:
  LinkedBinTree();	// 创建空二叉树
//	~LinkedBinTree();	// 删除二叉树
//	bool IsEmpty();					// 判断二叉树是否为空
  LinkedNode<T>* CreateRoot(const T &x);	// 以指定元素值创建根结点
//	void Clear();		// 清空二叉树
//	LinkedNode<T>* GetRoot();	// 获取根结点
  // 将一个结点作为指定结点的左孩子插入
  LinkedNode<T>* InsertLeftChild(LinkedNode<T> *pNode, const T &x);
  // 将一个结点作为指定结点的右孩子插入
  LinkedNode<T>* InsertRightChild(LinkedNode<T> *pNode, const T &x);
  // 修改指定结点的元素值
//	bool ModifyNodeValue(LinkedNode<T> *pNode, const T &x);
  // 获取指定结点的元素值
//	bool GetNodeValue(LinkedNode<T> *pNode, T &x);
  // 获取指定结点的左孩子结点
//	LinkedNode<T>* GetLeftChild(LinkedNode<T> *pNode);
  // 获取指定结点的右孩子结点
//	LinkedNode<T>* GetRightChild(LinkedNode<T> *pNode);
//	void PreOrderTraverse(LinkedNode<T>* pNode);// 按递归方式先序遍历
//	void InOrderTraverse(LinkedNode<T>* pNode);// 按递归方式中序遍历
//	void PostOrderTraverse(LinkedNode<T>* pNode);// 按递归方式后序遍历
//	void PreOrderTraverse();	// 按非递归方式先序遍历
//	void InOrderTraverse();		// 按非递归方式中序遍历
//	void PostOrderTraverse();	// 按非递归方式后序遍历
//	void LevelOrderTraverse();	// 按非递归方式逐层遍历
  // 按非递归方式获取指定结点的双亲结点
//	LinkedNode<T>* GetParent(LinkedNode<T> *pNode);
  // 删除以指定结点为根的子树
//	void DeleteSubTree(LinkedNode<T> *pNode);
  // 由DeleteSubTree函数调用按非递归方式删除以指定结点为根的子树
//	void DeleteSubTreeNode(LinkedNode<T> *pNode);
  // 按非递归方式根据关键字查找结点
//	LinkedNode<T>* SearchByKey(const T &x);
 private:
  LinkedNode<T> *m_pRoot;  //指向根结点的指针
};
// 实现创建空二叉树
template<class T>
LinkedBinTree<T>::LinkedBinTree() {
  m_pRoot = NULL;	// 将指向根结点的指针置为空
}

// 实现以指定元素值创建根结点
template<class T>
LinkedNode<T>* LinkedBinTree<T>::CreateRoot(const T &x) {
  // 如果二叉树中原来存在结点，则将其清空
  if (m_pRoot != NULL)	// 若原先存在根结点，则直接将根结点的值置为x
    m_pRoot->m_data = x;
  else	// 否则，创建一个新结点作为根结点
    m_pRoot = new LinkedNode<T>(x);
  return m_pRoot;
}

// 将一个结点作为指定结点的左孩子插入
template<class T>
LinkedNode<T>* LinkedBinTree<T>::InsertLeftChild(LinkedNode<T> *pNode, const T &x) {
  LinkedNode<T> *pNewNode;
  // 对传入参数进行有效性判断
  if (pNode == NULL)
    return NULL;
  // 创建一个新结点
  pNewNode = new LinkedNode<T>(x);
  if (pNewNode == NULL)	// 若分配内存失败
    return NULL;
  // 将新结点作为pNode的左孩子（即将结点中的左孩子指针指向新结点）
  pNode->m_pLeftChild = pNewNode;
  return pNewNode;
}

// 将一个结点作为指定结点的右孩子插入
template<class T>
LinkedNode<T>* LinkedBinTree<T>::InsertRightChild(LinkedNode<T> *pNode, const T &x) {
  LinkedNode<T> *pNewNode;
  if (pNode == NULL)		// 对传入参数进行有效性判断
    return NULL;
  // 创建一个新结点
  pNewNode = new LinkedNode<T>(x);
  if (pNewNode == NULL)	// 若分配内存失败
    return NULL;
  // 将新结点作为pNode的右孩子（即将结点中的右孩子指针指向新结点）
  pNode->m_pRightChild = pNewNode;
  return pNewNode;
}
