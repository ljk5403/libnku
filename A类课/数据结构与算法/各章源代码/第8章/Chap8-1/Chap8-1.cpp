#include "SearchAlgorithms.h"
#include <iostream>
using namespace std;
int main()
{
	int nR[] = {0, 43, 56, 37, 28, 17, 39, 22};
	int nSize=sizeof(nR)/sizeof(nR[0])-1;
	int nK = 39, nX=0;
	LinkedBinTree<int> btree;	// �������������
	LinkedNode<int> *pNode=NULL;	// ���ڱ�����ҽ��
	CreateBST(nR, nSize, btree);	// ��������nR�е�Ԫ�ش�������������
	btree.InOrderTraverse();	// �����������ʾ�����������е�����Ԫ��
	cout<<endl;
	// ���ݸ���ֵnK���ж������������ң�pNodeָ��ƥ��Ԫ�����ڵĽ��
	pNode = SearchBST(btree.GetRoot(), nK);
	if (pNode != NULL)	// ���ҳɹ�
	{
		btree.GetNodeValue(pNode, nX);	// ��ȡƥ��Ԫ�ص�ֵ
		cout<<nX<<endl;	// ���ƥ��Ԫ�ص�ֵ
	}
	else
		cout<<"����ʧ�ܣ�"<<endl;
	return 0;
}
