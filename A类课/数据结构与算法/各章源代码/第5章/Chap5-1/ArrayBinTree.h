#include <iostream>
#include <assert.h>
using namespace std;
template<class T>
class ArrayBinTree
{
public:
	ArrayBinTree(int nDepth);		// �����ն�����
	~ArrayBinTree();				// ɾ��������
	void CreateRoot(const T &x);	// ��ָ��Ԫ��ֵ���������
	void Clear();					// ��ն�����
	// ��һ�������Ϊָ���������Ӳ���
	bool InsertLeftChild(int nIndex, const T &x);
	// ��һ�������Ϊָ�������Һ��Ӳ���
	bool InsertRightChild(int nIndex, const T &x);
	void DeleteSubTree(int nIndex);	// ɾ����ָ�����Ϊ��������
	void LevelOrderTraverse();		// ������
private:
	bool *m_pbUsed;				// һά��̬���飬����ÿ��������Ƿ���ֵ
	int m_nMaxSize;				// �����������
	T *m_pElement;  				// һά��̬���飬����ÿ������ֵ
};
//ʵ�ֹ��캯��
template<class T>
ArrayBinTree <T>:: ArrayBinTree(int nDepth)
{
	int nI;
	assert(nDepth>0);	// ������ȱ������0
	// ����������ȼ����������
	m_nMaxSize=1;
	for (nI=0; nI<nDepth; nI++)
		m_nMaxSize *= 2;
	// ����������������ڴ�ռ�
	m_pElement=new T[m_nMaxSize];
	assert(m_pElement);
	m_pbUsed=new bool[m_nMaxSize];
	assert(m_pbUsed);
	// ��ʼʱ���н���о�û��ֵ����Ϊһ�ÿ���
	for (nI=0; nI<m_nMaxSize; nI++)
		m_pbUsed[nI] = false;
}
//ʵ����������
template<class T>
ArrayBinTree<T>::~ArrayBinTree ()
{
	// �ͷ��ڴ�
	if (m_pElement)	delete []m_pElement;
	if (m_pbUsed)	delete []m_pbUsed;
}
// ʵ����ָ��Ԫ��ֵ���������
template<class T>
void ArrayBinTree<T>::CreateRoot(const T &x)
{
	m_pElement[1] = x;
	m_pbUsed[1] = true;
}
// ʵ����ն�����
template<class T>
void ArrayBinTree<T>::Clear()
{
	int nI;
	// �����н������Ϊû��ֵ��״̬
	for (nI=1; nI<m_nMaxSize; nI++)
		m_pbUsed[nI] = false;
}
// ʵ�ֽ�һ�������Ϊָ���������Ӳ���
template<class T>
bool ArrayBinTree<T>::InsertLeftChild(int nIndex, const T &x)
{
	int nChildIndex = 2*nIndex;		// �������ӽ���������е�λ��
	if (nChildIndex >= m_nMaxSize)	// ���ӽ������λ�ò��ó����������
		return false;
	// �������ӽ��
	m_pElement[nChildIndex] = x;
	m_pbUsed[nChildIndex] = true;
	return true;
}
// ʵ�ֽ�һ�������Ϊָ�������Һ��Ӳ���
template<class T>
bool ArrayBinTree<T>::InsertRightChild(int nIndex, const T &x)
{
	int nChildIndex = 2*nIndex+1;	// �����Һ��ӽ���������е�λ��
	if (nChildIndex >= m_nMaxSize)	// �Һ��ӽ������λ�ò��ó����������
		return false;
	// �����Һ��ӽ��
	m_pElement[nChildIndex] = x;
	m_pbUsed[nChildIndex] = true;
	return true;
}
// ʵ��ɾ����ָ�����Ϊ��������
template<class T>
void ArrayBinTree<T>::DeleteSubTree(int nIndex)
{
	int nLeftChildIndex=2*nIndex; 			// ��ȡ���ӽ���������е�λ��
	int nRightChildIndex=nLeftChildIndex+1;	// ��ȡ�Һ��ӽ���������е�λ��
	assert(nIndex>0 && nIndex<m_nMaxSize);	// ��ɾ������������������Чλ����
	m_pbUsed[nIndex] = false;				// ���������Ϊû��ֵ��״̬
	if (nLeftChildIndex < m_nMaxSize)		// �ݹ�ɾ��������
		DeleteSubTree(nLeftChildIndex);
	if (nRightChildIndex < m_nMaxSize)		// �ݹ�ɾ��������
		DeleteSubTree(nRightChildIndex);
}
// ʵ�������������Ӹ���㿪ʼ���������϶��¡������ҵ�˳����ʽ�㣩
template<class T>
void ArrayBinTree<T>::LevelOrderTraverse()
{
	int nI, nNodeNum=0;
	//�������϶��¡������ҵ�˳�����������ֵ
	for (nI=1; nI<m_nMaxSize; nI++)
	{
		if (m_pbUsed[nI])
		{
			cout<<nI<<": "<<m_pElement[nI]<<endl;
			nNodeNum++;
		}
	}
	// ����������û�н�㣬��������ն�������
	if (nNodeNum==0)
		cout<<"�ն�����"<<endl;
}
