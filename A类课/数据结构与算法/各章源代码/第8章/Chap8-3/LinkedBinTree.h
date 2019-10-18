#include <iostream>
#include "LinkQueue.h"	// 3.4.2节中实现的链接队列类模板
#include "LinkStack.h"	// 3.3.2节中实现的链接栈类模板
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
  ~LinkedBinTree();	// 删除二叉树
  bool IsEmpty();					// 判断二叉树是否为空
  LinkedNode<T>* CreateRoot(const T &x);	// 以指定元素值创建根结点
  void Clear();		// 清空二叉树
  LinkedNode<T>* GetRoot();	// 获取根结点
  // 将一个结点作为指定结点的左孩子插入
  LinkedNode<T>* InsertLeftChild(LinkedNode<T> *pNode, const T &x);
  // 将一个结点作为指定结点的右孩子插入
  LinkedNode<T>* InsertRightChild(LinkedNode<T> *pNode, const T &x);
  // 修改指定结点的元素值
  bool ModifyNodeValue(LinkedNode<T> *pNode, const T &x);
  // 获取指定结点的元素值
  bool GetNodeValue(LinkedNode<T> *pNode, T &x);
  // 获取指定结点的左孩子结点
  LinkedNode<T>* GetLeftChild(LinkedNode<T> *pNode);
  // 获取指定结点的右孩子结点
  LinkedNode<T>* GetRightChild(LinkedNode<T> *pNode);
  void PreOrderTraverse(LinkedNode<T>* pNode);// 按递归方式先序遍历
  void InOrderTraverse(LinkedNode<T>* pNode);// 按递归方式中序遍历
  void PostOrderTraverse(LinkedNode<T>* pNode);// 按递归方式后序遍历
  void PreOrderTraverse();	// 按非递归方式先序遍历
  void InOrderTraverse();		// 按非递归方式中序遍历
  void PostOrderTraverse();	// 按非递归方式后序遍历
  void LevelOrderTraverse();	// 按非递归方式逐层遍历
  // 按非递归方式获取指定结点的双亲结点
  LinkedNode<T>* GetParent(LinkedNode<T> *pNode);
  // 删除以指定结点为根的子树
  void DeleteSubTree(LinkedNode<T> *pNode);
  // 由DeleteSubTree函数调用按非递归方式删除以指定结点为根的子树
  void DeleteSubTreeNode(LinkedNode<T> *pNode);
  // 按非递归方式根据关键字查找结点
  LinkedNode<T>* SearchByKey(const T &x);
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
// 按递归方式先序遍历
template<class T>
void LinkedBinTree<T>::PreOrderTraverse(LinkedNode<T>* pNode) {
  if (pNode == NULL)
    return;
  // 先访问pNode
  cout << pNode->m_data << " ";
  // 再以先序遍历方式访问pNode的左子树
  PreOrderTraverse(pNode->m_pLeftChild);
  // 最后以先序遍历方式访问pNode的右子树
  PreOrderTraverse(pNode->m_pRightChild);
}
// 按非递归方式先序遍历
template<class T>
void LinkedBinTree<T>::PreOrderTraverse() {
  LinkStack<LinkedNode<T>*> s;
  LinkedNode<T> *pNode = NULL;
  if (m_pRoot == NULL)
    return;
  // 将根结点入栈
  s.Push(m_pRoot);
  // 栈不为空时循环
  while (!s.IsEmpty()) {
    // 栈顶元素出栈并被访问
    s.Pop(pNode);
    cout << pNode->m_data << " ";
    // 若结点存在右子树，则将右子树根结点入栈
    if (pNode->m_pRightChild)
      s.Push(pNode->m_pRightChild);
    // 若结点存在左子树，则将左子树根结点入栈
    if (pNode->m_pLeftChild)
      s.Push(pNode->m_pLeftChild);
  }
}
// 按递归方式中序遍历
template<class T>
void LinkedBinTree<T>::InOrderTraverse(LinkedNode<T>* pNode) {
  if (pNode == NULL)
    return;
  // 先以中序遍历方式访问pNode的左子树
  InOrderTraverse(pNode->m_pLeftChild);
  // 再访问pNode
  cout << pNode->m_data << " ";
  // 最后以中序遍历方式访问pNode的右子树
  InOrderTraverse(pNode->m_pRightChild);
}
// 按非递归方式中序遍历
template<class T>
void LinkedBinTree<T>::InOrderTraverse() {
  LinkStack<LinkedNode<T>*> s;
  LinkedNode<T> *pNode = m_pRoot;
  // pNode不为空时循环
  while (pNode) {
    // 当pNode不为空时，将其入栈，并令pNode指向其左孩子
    while (pNode) {
      s.Push(pNode);
      pNode = pNode->m_pLeftChild;
    }
    //栈不为空，则栈顶结点出栈并被访问，令pNode指向取出栈顶结点的右孩子
    while (!s.IsEmpty()) {
      s.Pop(pNode);
      cout << pNode->m_data << " ";
      pNode = pNode->m_pRightChild;
      if (pNode)	// 若栈顶结点有右子树，则访问其右子树
        break;
    }
  }
}
// 按递归方式后序遍历
template<class T>
void LinkedBinTree<T>::PostOrderTraverse(LinkedNode<T>* pNode) {
  if (pNode == NULL)
    return;
  // 先以后序遍历方式访问pNode的左子树
  PostOrderTraverse(pNode->m_pLeftChild);
  // 再以后序遍历方式访问pNode的右子树
  PostOrderTraverse(pNode->m_pRightChild);
  // 最后访问pNode
  cout << pNode->m_data << " ";
}
// 按非递归方式后序遍历
template<class T>
void LinkedBinTree<T>::PostOrderTraverse() {
  LinkStack<LinkedNode<T>*> s;
  LinkedNode<T> *pNode = m_pRoot, *pPreVisitNode = NULL;
  // pNode不为空时循环
  while (pNode) {
    // 当pNode不为空时，将其入栈，并令pNode指向其左孩子
    while (pNode) {
      s.Push(pNode);
      pNode = pNode->m_pLeftChild;
    }
    while (!s.IsEmpty()) {
      // 当栈不为空时，取出栈顶元素
      s.Top(pNode);
      // 若栈顶元素的右孩子为空或已被访问，则访问当前栈顶元素，并将栈顶
      // 元素出栈
      if (pNode->m_pRightChild == NULL
          || pNode->m_pRightChild == pPreVisitNode) {
        cout << pNode->m_data << " ";
        s.Pop(pNode);
        pPreVisitNode = pNode;	// 设置pNode为前一个访问的结点
        // 设置pNode为空，表示pNode及其左右子树均已访问完毕，访问下
        // 一个栈中元素
        pNode = NULL;
      }
      // 否则，应先访问栈顶元素的右孩子
      else {
        pNode = pNode->m_pRightChild;
        break;
      }
    }
  }
}
// 按非递归方式逐层遍历
template<class T>
void LinkedBinTree<T>::LevelOrderTraverse() {
  LinkQueue<LinkedNode<T>*> q;
  LinkedNode<T> *pNode = NULL;
  if (m_pRoot == NULL)	return;
  // 将根结点入队
  q.Insert(m_pRoot);
  // 当队列不为空时循环
  while (!q.IsEmpty()) {
    // 将队头元素出队并访问
    q.Delete(pNode);
    cout << pNode->m_data << " ";
    // 若结点存在左子树，则将左子树根结点入队
    if (pNode->m_pLeftChild)
      q.Insert(pNode->m_pLeftChild);
    // 若结点存在右子树，则将右子树根结点入队
    if (pNode->m_pRightChild)
      q.Insert(pNode->m_pRightChild);
  }
}
// 按非递归方式获取指定结点的双亲结点
template<class T>
LinkedNode<T>* LinkedBinTree<T>::GetParent(LinkedNode<T> *pNode) {
  LinkQueue<LinkedNode<T>*> q;
  LinkedNode<T> *pCurNode = NULL;
  // 若指定结点pNode为根结点，则返回空
  if (pNode == m_pRoot)
    return NULL;
  // 若二叉树是空树，则返回空
  if (m_pRoot == NULL)
    return NULL;
  // 按非递归逐层遍历的方式搜索双亲结点
  // 将根结点入队
  q.Insert(m_pRoot);
  // 当队列不为空时循环
  while (!q.IsEmpty()) {
    // 将队头元素出队
    q.Delete(pCurNode);
    // 如果pNode是队头元素的孩子，则返回队头元素
    if (pCurNode->m_pLeftChild == pNode
        || pCurNode->m_pRightChild == pNode)
      return pCurNode;
    // 若结点存在左子树，则将左子树根结点入队
    if (pCurNode->m_pLeftChild)
      q.Insert(pCurNode->m_pLeftChild);
    // 若结点存在右子树，则将右子树根结点入队
    if (pCurNode->m_pRightChild)
      q.Insert(pCurNode->m_pRightChild);
  }
  return NULL;
}
// 删除以指定结点为根的子树
template<class T>
void LinkedBinTree<T>::DeleteSubTree(LinkedNode<T> *pNode) {
  LinkedNode<T> *pParentNode = NULL;
  // 若指定结点为空，则返回
  if (pNode == NULL)
    return;
  // 若将整棵二叉树删除，则令根结点为空
  if (m_pRoot == pNode)
    m_pRoot = NULL;
  // 否则，若指定结点存在双亲结点，则将双亲结点的左孩子/右孩子置空
  else if ((pParentNode = GetParent(pNode)) != NULL) {
    if (pParentNode->m_pLeftChild == pNode)
      pParentNode->m_pLeftChild = NULL;
    else
      pParentNode->m_pRightChild = NULL;
  }
  // 否则，指定结点不是二叉树中的结点，直接返回
  else
    return;
  // 调用DeleteSubTreeNode删除以pNode为根的子树
  DeleteSubTreeNode(pNode);
}

// 由DeleteSubTree函数调用按非递归方式删除以指定结点为根的子树
template<class T>
void LinkedBinTree<T>::DeleteSubTreeNode(LinkedNode<T> *pNode) {
  LinkQueue<LinkedNode<T>*> q;
  LinkedNode<T> *pCurNode = NULL;
  if (pNode == NULL)
    return;
  // 按非递归层次遍历的方式删除子树
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
// 按非递归方式根据关键字查找结点
template<class T>
LinkedNode<T>* LinkedBinTree<T>::SearchByKey(const T &x) {
  LinkQueue<LinkedNode<T>*> q;
  LinkedNode<T> *pMatchNode = NULL;
  if (m_pRoot == NULL)	return NULL;
  // 按非递归层次遍历的方式查找结点
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
// 实现删除二叉树
template<class T>
LinkedBinTree<T>::~LinkedBinTree() {
  Clear();	// 清空二叉树中的结点
}
// 实现清空二叉树
template<class T>
void LinkedBinTree<T>::Clear() {
  DeleteSubTree(m_pRoot);
}
// 判断二叉树是否为空
template<class T>
bool LinkedBinTree<T>::IsEmpty() {
  if (m_pRoot == NULL)
    return true;
  return false;
}
// 获取根结点
template<class T>
LinkedNode<T>* LinkedBinTree<T>::GetRoot() {
  return m_pRoot;
}
// 修改指定结点的元素值
template<class T>
bool LinkedBinTree<T>::ModifyNodeValue(LinkedNode<T> *pNode, const T &x) {
  if (pNode == NULL)
    return false;
  pNode->m_data = x;
  return true;
}
// 获取指定结点的元素值
template<class T>
bool LinkedBinTree<T>::GetNodeValue(LinkedNode<T> *pNode, T &x) {
  if (pNode == NULL)
    return false;
  x = pNode->m_data;
  return true;
}
// 获取指定结点的左孩子结点
template<class T>
LinkedNode<T>* LinkedBinTree<T>::GetLeftChild(LinkedNode<T> *pNode) {
  if (pNode == NULL)
    return NULL;
  return pNode->m_pLeftChild;
}
// 获取指定结点的右孩子结点
template<class T>
LinkedNode<T>* LinkedBinTree<T>::GetRightChild(LinkedNode<T> *pNode) {
  if (pNode == NULL)
    return NULL;
  return pNode->m_pRightChild;
}