#ifndef	_SEARCHALGORITHMS_H
#define	_SEARCHALGORITHMS_H
// 顺序查找
// 根据给定元素K对R进行顺序查找
template <class T >
int SeqSearch(T R[], int nSize, T K)
{
	int nI;
	R[0] = K;	// R[0]作为监视哨
	for (nI=nSize; R[nI]!=K; nI--)	// 从表尾开始向前进行查找
		;
	return nI; // 将匹配元素在数组中的下标返回，查找失败则返回0
}

// 折半查找
// 根据给定元素K对R进行折半查找
template <class T >
int BinSearch(T R[], int nSize, T K)
{
	int low=1, high=nSize, mid;
	while (low <= high)
	{
		mid = (low+high)/2;
		if (R[mid] == K)
			return mid;	// 查找成功，返回匹配元素下标
		else if (R[mid] > K)
			high = mid-1;	// 在前半部分进行折半查找
		else
			low = mid+1;	// 在后半部分进行折半查找
	}
	return 0;	// 查找失败
}

// 分块查找
// 索引表中的元素类
template <class T>
class BlockIndex
{
public:
	int nBlockBegPos;		// 块的起始位置
	T maxVal;			// 块内最大元素值
};
// 根据给定元素K对R进行分块查找，BI为索引表，nBlockNum为块数
template <class T>
int BlockSearch(T R[], int nSize, BlockIndex<T> BI[], int nBlockNum, T K)
{
	int low=1, high=nBlockNum, mid;
	int nI, nBlockBegPos, nBlockEndPos;
	// 先通过二分查找确定块
	while (low <= high)
	{
		mid = (low+high)/2;
		if (BI[mid].maxVal >= K)
		{
			if (mid==1 || BI[mid-1].maxVal<K)
				break;			// 查找成功
			else
				high = mid-1;	// 在前半部分进行折半查找
		}
		else
			low = mid+1;	// 在后半部分进行折半查找
	}
	if (low > high)
		return 0;	// 查找失败
	// 在块内进行顺序查找
	nBlockBegPos = BI[mid].nBlockBegPos;	// 块的起始位置
	if (mid == nBlockNum)		// 块的结束位置
		nBlockEndPos = nSize;
	else
		nBlockEndPos = BI[mid+1].nBlockBegPos-1;
	// 从块头开始向块尾进行查找
	for (nI=nBlockBegPos; nI<=nBlockEndPos; nI++)
	{
		if (R[nI] == K)
			return nI;
	}
	return 0;		// 查找失败
}

// 二叉排序树
#include "LinkedBinTree.h"
// 将元素K插入到二叉排序树btree中
template <class T>
void InsertBST(LinkedBinTree<T> &btree, T K)
{
	LinkedNode<T> *pNode = NULL, *pChild = NULL;
	T x;
	// 若二叉排序树为空树，则将K作为根结点
	if (btree.IsEmpty())
	{
		btree.CreateRoot(K);
		return;
	}
	pNode = btree.GetRoot();
	while (pNode)
	{
		btree.GetNodeValue(pNode, x);
		if (K == x)	// 若K已经是二叉排序树中的结点，则不需重复插入
			return;
		if (K < x)	//若K小于当前子树根结点的值，则将K插入到该根结点的左子树中
		{
			// 若根结点有左子树，则继续寻找新元素在左子树中应处的位置
			if ((pChild=btree.GetLeftChild(pNode))!=NULL)
				pNode = pChild;
			else	// 否则，将新元素作为根结点的左孩子
			{
				btree.InsertLeftChild(pNode, K);
				return;
			}
		}
		else	// 若K大于当前子树根结点的值，则将K插入到该根结点的右子树中
		{
			// 若根结点有右子树，则继续寻找新元素在右子树中应处的位置
			if ((pChild=btree.GetRightChild(pNode))!=NULL)
				pNode = pChild;
			else	// 否则，将新元素作为根结点的右孩子
			{
				btree.InsertRightChild(pNode, K);
				return;
			}
		}
	}
}

// 根据传入数据集合R生成二叉排序树btree
template <class T>
void CreateBST(T R[], int nSize, LinkedBinTree<T> &btree)
{
	int nI;
	// 将R中的元素逐一插入到二叉排序树btree中
	for (nI=1; nI<=nSize; nI++)
		InsertBST(btree, R[nI]);
}
// 以递归方式实现根据给定元素K进行二叉排序树的查找
template <class T>
LinkedNode<T>* SearchBST(LinkedNode<T>* pRoot, T K)
{
	LinkedBinTree<T> btree;
	T x;
	if (pRoot == NULL)	// 若子树为空，则查找失败
		return NULL;
	btree.GetNodeValue(pRoot, x);
	if (K == x)	// 若K等于根结点的值，则查找成功
		return pRoot;
	else if (K < x)//若K小于根结点的值，则在左子树中继续进行二叉排序树的查找
		return SearchBST(btree.GetLeftChild(pRoot), K);
	else	// 否则，若K大于根结点的值，则在右子树中继续进行二叉排序树的查找
		return SearchBST(btree.GetRightChild(pRoot), K);
}
// 以非递归方式实现根据给定元素K进行二叉排序树的查找
// 当查找失败时将K作为新结点插入到二叉排序树中
template <class T>
LinkedNode<T>* SearchInsertBST(LinkedBinTree<T> &btree, T K)
{
	LinkedNode<T> *pNode = NULL, *pChild = NULL;
	T x;
	// 若二叉排序树为空树，则将K作为根结点，并返回空
	if (btree.IsEmpty())
	{
		btree.CreateRoot(K);
		return NULL;
	}
	pNode = btree.GetRoot();
	while (pNode)
	{
		btree.GetNodeValue(pNode, x);
		if (K == x)	// 若K等于当前子树根结点的值，则查找成功
			return pNode;
		if (K < x)	// 若K小于当前子树根结点的值，则在该根结点左子树中继续查找
		{
			// 若根结点有左子树，则继续在左子树中进行二叉排序树查找
			if ((pChild=btree.GetLeftChild(pNode))!=NULL)
				pNode = pChild;
			else// 否则，将新元素作为当前子树根结点的左孩子插入到二叉排序树中
			{
				btree.InsertLeftChild(pNode, K);
				return NULL;
			}
		}
		else	// 若K大于当前子树根结点的值，则在该根结点右子树中继续查找
		{
			// 若根结点有右子树，则继续在右子树中进行二叉排序树的查找
			if ((pChild=btree.GetRightChild(pNode))!=NULL)
				pNode = pChild;
			else// 否则，将新元素作为当前子树根结点的右孩子插入到二叉排序树中
			{
				btree.InsertRightChild(pNode, K);
				return NULL;
			}
		}
	}
	return NULL;
}

// 哈希查找
#include "LinkList.h"
// 哈希表类
template <class T>
class HashTable
{
private:
	LinkList<T> *m_pElement;	// 用于指向存储数据元素的空间
	int m_nSize;	// 哈希表存储空间尺寸
	int (*m_pHashFunction)(const T &element);	// 哈希函数指针
public:
// 构造函数
	HashTable(int nSize, int (*pHashFunction)(const T &element))	
	{
		m_nSize = nSize;
		m_pElement = new LinkList<T>[m_nSize];
		m_pHashFunction = pHashFunction;
	}
	~HashTable()	// 析构函数
	{
		delete []m_pElement;
	}
	// 显示哈希表中的元素
	void Display()
	{
		int nI;
		for (nI=0; nI<m_nSize; nI++)
			cout<<nI<<":"<<endl<<m_pElement[nI];
	}
	// 向哈希表中插入一个新元素x
	void InsertHashTable(const T &x)
	{
		// 计算待插入元素的存储地址
		int nIdx = m_pHashFunction(x);
		// 将新元素插入到链表最后
		int nLen = m_pElement[nIdx].GetLength();
		m_pElement[nIdx].Insert(nLen+1, x);
	}
	// 根据数组R中的元素创建哈希表hashtable
	void CreateHashTable(T *R, int nSize)
	{
		int nI;
		for (nI=1; nI<=nSize; nI++)
			InsertHashTable(R[nI]);
	}
	// 根据给定值K进行哈希查找，若查找成功则将查找结果存放在x中
	bool SearchHashTable(T &K, T &x)
	{
		// 计算待查找元素的存储地址
		int nIdx = m_pHashFunction(K);
		// 在链表中进行查找
		int nPos = m_pElement[nIdx].Find(K);
		if (nPos == 0)	// 查找失败
			return false;
		m_pElement[nIdx].GetData(nPos, x);
		return true;
	}
};

// 根据给定值K对R进行顺序查找，同上一章中的应用实例一样，为了能够用一个函
// 数实现按不同关键字查找，此处将比较两个元素大小的函数作为参数传入
template <class T>
int SeqSearch(T R[], int nSize, T K, int (*CompareFun)(T&, T&))
{
	int nI;
	R[0] = K;	// R[0]作为监视哨
	for (nI=nSize; CompareFun(R[nI],K)!=0; nI--)	// 从表尾开始向前进行查找
		;
	return nI; // 将匹配元素在数组中的下标返回，查找失败则返回0
}
#endif	// end of _SEARCHALGORITHMS_H