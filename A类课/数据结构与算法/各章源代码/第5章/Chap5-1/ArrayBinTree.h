#include <iostream>
#include <assert.h>
using namespace std;
template<class T>
class ArrayBinTree
{
public:
	ArrayBinTree(int nDepth);		// 创建空二叉树
	~ArrayBinTree();				// 删除二叉树
	void CreateRoot(const T &x);	// 以指定元素值创建根结点
	void Clear();					// 清空二叉树
	// 将一个结点作为指定结点的左孩子插入
	bool InsertLeftChild(int nIndex, const T &x);
	// 将一个结点作为指定结点的右孩子插入
	bool InsertRightChild(int nIndex, const T &x);
	void DeleteSubTree(int nIndex);	// 删除以指定结点为根的子树
	void LevelOrderTraverse();		// 逐层遍历
private:
	bool *m_pbUsed;				// 一维动态数组，保存每个结点中是否有值
	int m_nMaxSize;				// 树的最大结点数
	T *m_pElement;  				// 一维动态数组，保存每个结点的值
};
//实现构造函数
template<class T>
ArrayBinTree <T>:: ArrayBinTree(int nDepth)
{
	int nI;
	assert(nDepth>0);	// 树的深度必须大于0
	// 根据树的深度计算最大结点数
	m_nMaxSize=1;
	for (nI=0; nI<nDepth; nI++)
		m_nMaxSize *= 2;
	// 根据最大结点数分配内存空间
	m_pElement=new T[m_nMaxSize];
	assert(m_pElement);
	m_pbUsed=new bool[m_nMaxSize];
	assert(m_pbUsed);
	// 初始时所有结点中均没有值，即为一棵空树
	for (nI=0; nI<m_nMaxSize; nI++)
		m_pbUsed[nI] = false;
}
//实现析构函数
template<class T>
ArrayBinTree<T>::~ArrayBinTree ()
{
	// 释放内存
	if (m_pElement)	delete []m_pElement;
	if (m_pbUsed)	delete []m_pbUsed;
}
// 实现以指定元素值创建根结点
template<class T>
void ArrayBinTree<T>::CreateRoot(const T &x)
{
	m_pElement[1] = x;
	m_pbUsed[1] = true;
}
// 实现清空二叉树
template<class T>
void ArrayBinTree<T>::Clear()
{
	int nI;
	// 将所有结点设置为没有值的状态
	for (nI=1; nI<m_nMaxSize; nI++)
		m_pbUsed[nI] = false;
}
// 实现将一个结点作为指定结点的左孩子插入
template<class T>
bool ArrayBinTree<T>::InsertLeftChild(int nIndex, const T &x)
{
	int nChildIndex = 2*nIndex;		// 计算左孩子结点在数组中的位置
	if (nChildIndex >= m_nMaxSize)	// 左孩子结点所在位置不得超过最大结点数
		return false;
	// 插入左孩子结点
	m_pElement[nChildIndex] = x;
	m_pbUsed[nChildIndex] = true;
	return true;
}
// 实现将一个结点作为指定结点的右孩子插入
template<class T>
bool ArrayBinTree<T>::InsertRightChild(int nIndex, const T &x)
{
	int nChildIndex = 2*nIndex+1;	// 计算右孩子结点在数组中的位置
	if (nChildIndex >= m_nMaxSize)	// 右孩子结点所在位置不得超过最大结点数
		return false;
	// 插入右孩子结点
	m_pElement[nChildIndex] = x;
	m_pbUsed[nChildIndex] = true;
	return true;
}
// 实现删除以指定结点为根的子树
template<class T>
void ArrayBinTree<T>::DeleteSubTree(int nIndex)
{
	int nLeftChildIndex=2*nIndex; 			// 获取左孩子结点在数组中的位置
	int nRightChildIndex=nLeftChildIndex+1;	// 获取右孩子结点在数组中的位置
	assert(nIndex>0 && nIndex<m_nMaxSize);	// 待删除子树根结点必须在有效位置上
	m_pbUsed[nIndex] = false;				// 将根结点置为没有值的状态
	if (nLeftChildIndex < m_nMaxSize)		// 递归删除左子树
		DeleteSubTree(nLeftChildIndex);
	if (nRightChildIndex < m_nMaxSize)		// 递归删除右子树
		DeleteSubTree(nRightChildIndex);
}
// 实现逐层遍历（即从根结点开始，按照自上而下、从左到右的顺序访问结点）
template<class T>
void ArrayBinTree<T>::LevelOrderTraverse()
{
	int nI, nNodeNum=0;
	//按照自上而下、从左到右的顺序输出各结点的值
	for (nI=1; nI<m_nMaxSize; nI++)
	{
		if (m_pbUsed[nI])
		{
			cout<<nI<<": "<<m_pElement[nI]<<endl;
			nNodeNum++;
		}
	}
	// 若二叉树中没有结点，则输出“空二叉树”
	if (nNodeNum==0)
		cout<<"空二叉树"<<endl;
}
