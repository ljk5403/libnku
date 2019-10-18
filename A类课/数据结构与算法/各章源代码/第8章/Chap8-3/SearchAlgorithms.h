#ifndef	_SEARCHALGORITHMS_H
#define	_SEARCHALGORITHMS_H
// ˳�����
// ���ݸ���Ԫ��K��R����˳�����
template <class T >
int SeqSearch(T R[], int nSize, T K)
{
	int nI;
	R[0] = K;	// R[0]��Ϊ������
	for (nI=nSize; R[nI]!=K; nI--)	// �ӱ�β��ʼ��ǰ���в���
		;
	return nI; // ��ƥ��Ԫ���������е��±귵�أ�����ʧ���򷵻�0
}

// �۰����
// ���ݸ���Ԫ��K��R�����۰����
template <class T >
int BinSearch(T R[], int nSize, T K)
{
	int low=1, high=nSize, mid;
	while (low <= high)
	{
		mid = (low+high)/2;
		if (R[mid] == K)
			return mid;	// ���ҳɹ�������ƥ��Ԫ���±�
		else if (R[mid] > K)
			high = mid-1;	// ��ǰ�벿�ֽ����۰����
		else
			low = mid+1;	// �ں�벿�ֽ����۰����
	}
	return 0;	// ����ʧ��
}

// �ֿ����
// �������е�Ԫ����
template <class T>
class BlockIndex
{
public:
	int nBlockBegPos;		// �����ʼλ��
	T maxVal;			// �������Ԫ��ֵ
};
// ���ݸ���Ԫ��K��R���зֿ���ң�BIΪ������nBlockNumΪ����
template <class T>
int BlockSearch(T R[], int nSize, BlockIndex<T> BI[], int nBlockNum, T K)
{
	int low=1, high=nBlockNum, mid;
	int nI, nBlockBegPos, nBlockEndPos;
	// ��ͨ�����ֲ���ȷ����
	while (low <= high)
	{
		mid = (low+high)/2;
		if (BI[mid].maxVal >= K)
		{
			if (mid==1 || BI[mid-1].maxVal<K)
				break;			// ���ҳɹ�
			else
				high = mid-1;	// ��ǰ�벿�ֽ����۰����
		}
		else
			low = mid+1;	// �ں�벿�ֽ����۰����
	}
	if (low > high)
		return 0;	// ����ʧ��
	// �ڿ��ڽ���˳�����
	nBlockBegPos = BI[mid].nBlockBegPos;	// �����ʼλ��
	if (mid == nBlockNum)		// ��Ľ���λ��
		nBlockEndPos = nSize;
	else
		nBlockEndPos = BI[mid+1].nBlockBegPos-1;
	// �ӿ�ͷ��ʼ���β���в���
	for (nI=nBlockBegPos; nI<=nBlockEndPos; nI++)
	{
		if (R[nI] == K)
			return nI;
	}
	return 0;		// ����ʧ��
}

// ����������
#include "LinkedBinTree.h"
// ��Ԫ��K���뵽����������btree��
template <class T>
void InsertBST(LinkedBinTree<T> &btree, T K)
{
	LinkedNode<T> *pNode = NULL, *pChild = NULL;
	T x;
	// ������������Ϊ��������K��Ϊ�����
	if (btree.IsEmpty())
	{
		btree.CreateRoot(K);
		return;
	}
	pNode = btree.GetRoot();
	while (pNode)
	{
		btree.GetNodeValue(pNode, x);
		if (K == x)	// ��K�Ѿ��Ƕ����������еĽ�㣬�����ظ�����
			return;
		if (K < x)	//��KС�ڵ�ǰ����������ֵ����K���뵽�ø�������������
		{
			// ����������������������Ѱ����Ԫ������������Ӧ����λ��
			if ((pChild=btree.GetLeftChild(pNode))!=NULL)
				pNode = pChild;
			else	// ���򣬽���Ԫ����Ϊ����������
			{
				btree.InsertLeftChild(pNode, K);
				return;
			}
		}
		else	// ��K���ڵ�ǰ����������ֵ����K���뵽�ø�������������
		{
			// ����������������������Ѱ����Ԫ������������Ӧ����λ��
			if ((pChild=btree.GetRightChild(pNode))!=NULL)
				pNode = pChild;
			else	// ���򣬽���Ԫ����Ϊ�������Һ���
			{
				btree.InsertRightChild(pNode, K);
				return;
			}
		}
	}
}

// ���ݴ������ݼ���R���ɶ���������btree
template <class T>
void CreateBST(T R[], int nSize, LinkedBinTree<T> &btree)
{
	int nI;
	// ��R�е�Ԫ����һ���뵽����������btree��
	for (nI=1; nI<=nSize; nI++)
		InsertBST(btree, R[nI]);
}
// �Եݹ鷽ʽʵ�ָ��ݸ���Ԫ��K���ж����������Ĳ���
template <class T>
LinkedNode<T>* SearchBST(LinkedNode<T>* pRoot, T K)
{
	LinkedBinTree<T> btree;
	T x;
	if (pRoot == NULL)	// ������Ϊ�գ������ʧ��
		return NULL;
	btree.GetNodeValue(pRoot, x);
	if (K == x)	// ��K���ڸ�����ֵ������ҳɹ�
		return pRoot;
	else if (K < x)//��KС�ڸ�����ֵ�������������м������ж����������Ĳ���
		return SearchBST(btree.GetLeftChild(pRoot), K);
	else	// ������K���ڸ�����ֵ�������������м������ж����������Ĳ���
		return SearchBST(btree.GetRightChild(pRoot), K);
}
// �Էǵݹ鷽ʽʵ�ָ��ݸ���Ԫ��K���ж����������Ĳ���
// ������ʧ��ʱ��K��Ϊ�½����뵽������������
template <class T>
LinkedNode<T>* SearchInsertBST(LinkedBinTree<T> &btree, T K)
{
	LinkedNode<T> *pNode = NULL, *pChild = NULL;
	T x;
	// ������������Ϊ��������K��Ϊ����㣬�����ؿ�
	if (btree.IsEmpty())
	{
		btree.CreateRoot(K);
		return NULL;
	}
	pNode = btree.GetRoot();
	while (pNode)
	{
		btree.GetNodeValue(pNode, x);
		if (K == x)	// ��K���ڵ�ǰ����������ֵ������ҳɹ�
			return pNode;
		if (K < x)	// ��KС�ڵ�ǰ����������ֵ�����ڸø�����������м�������
		{
			// �������������������������������н��ж�������������
			if ((pChild=btree.GetLeftChild(pNode))!=NULL)
				pNode = pChild;
			else// ���򣬽���Ԫ����Ϊ��ǰ�������������Ӳ��뵽������������
			{
				btree.InsertLeftChild(pNode, K);
				return NULL;
			}
		}
		else	// ��K���ڵ�ǰ����������ֵ�����ڸø�����������м�������
		{
			// �������������������������������н��ж����������Ĳ���
			if ((pChild=btree.GetRightChild(pNode))!=NULL)
				pNode = pChild;
			else// ���򣬽���Ԫ����Ϊ��ǰ�����������Һ��Ӳ��뵽������������
			{
				btree.InsertRightChild(pNode, K);
				return NULL;
			}
		}
	}
	return NULL;
}

// ��ϣ����
#include "LinkList.h"
// ��ϣ����
template <class T>
class HashTable
{
private:
	LinkList<T> *m_pElement;	// ����ָ��洢����Ԫ�صĿռ�
	int m_nSize;	// ��ϣ��洢�ռ�ߴ�
	int (*m_pHashFunction)(const T &element);	// ��ϣ����ָ��
public:
// ���캯��
	HashTable(int nSize, int (*pHashFunction)(const T &element))	
	{
		m_nSize = nSize;
		m_pElement = new LinkList<T>[m_nSize];
		m_pHashFunction = pHashFunction;
	}
	~HashTable()	// ��������
	{
		delete []m_pElement;
	}
	// ��ʾ��ϣ���е�Ԫ��
	void Display()
	{
		int nI;
		for (nI=0; nI<m_nSize; nI++)
			cout<<nI<<":"<<endl<<m_pElement[nI];
	}
	// ���ϣ���в���һ����Ԫ��x
	void InsertHashTable(const T &x)
	{
		// ���������Ԫ�صĴ洢��ַ
		int nIdx = m_pHashFunction(x);
		// ����Ԫ�ز��뵽�������
		int nLen = m_pElement[nIdx].GetLength();
		m_pElement[nIdx].Insert(nLen+1, x);
	}
	// ��������R�е�Ԫ�ش�����ϣ��hashtable
	void CreateHashTable(T *R, int nSize)
	{
		int nI;
		for (nI=1; nI<=nSize; nI++)
			InsertHashTable(R[nI]);
	}
	// ���ݸ���ֵK���й�ϣ���ң������ҳɹ��򽫲��ҽ�������x��
	bool SearchHashTable(T &K, T &x)
	{
		// ���������Ԫ�صĴ洢��ַ
		int nIdx = m_pHashFunction(K);
		// �������н��в���
		int nPos = m_pElement[nIdx].Find(K);
		if (nPos == 0)	// ����ʧ��
			return false;
		m_pElement[nIdx].GetData(nPos, x);
		return true;
	}
};

// ���ݸ���ֵK��R����˳����ң�ͬ��һ���е�Ӧ��ʵ��һ����Ϊ���ܹ���һ����
// ��ʵ�ְ���ͬ�ؼ��ֲ��ң��˴����Ƚ�����Ԫ�ش�С�ĺ�����Ϊ��������
template <class T>
int SeqSearch(T R[], int nSize, T K, int (*CompareFun)(T&, T&))
{
	int nI;
	R[0] = K;	// R[0]��Ϊ������
	for (nI=nSize; CompareFun(R[nI],K)!=0; nI--)	// �ӱ�β��ʼ��ǰ���в���
		;
	return nI; // ��ƥ��Ԫ���������е��±귵�أ�����ʧ���򷵻�0
}
#endif	// end of _SEARCHALGORITHMS_H