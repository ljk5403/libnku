/* Chap5_2.cpp��������ʽ�洢�ṹ�Ķ�����*/
#include "LinkedBinTree.h"
int main()
{
	LinkedBinTree<char> btree;//������charΪ����Ԫ�صĶ�����
	LinkedNode<char> *pNode=NULL, *pNewNode=NULL;
	LinkQueue<LinkedNode<char>*> q;
	// ����δ���������
	// ��������㣬������������
	pNewNode = btree.CreateRoot('A');
	q.Insert(pNewNode);
	// ����ͷԪ��A���ӣ�����A�ĺ��ӽ��B��C�����������ĺ��ӽ�����
	q.Delete(pNode);
	pNewNode = btree.InsertLeftChild(pNode, 'B');
	q.Insert(pNewNode);
	pNewNode = btree.InsertRightChild(pNode, 'C');
	q.Insert(pNewNode);
	// ����ͷԪ��B���ӣ�����B�����ӽ��D�����������ĺ��ӽ�����
	q.Delete(pNode);
	pNewNode = btree.InsertLeftChild(pNode, 'D');
	q.Insert(pNewNode);
	// ����ͷԪ��C���ӣ�����C�ĺ��ӽ��E��F�����������ĺ��ӽ�����
	q.Delete(pNode);
	pNewNode = btree.InsertLeftChild(pNode, 'E');
	q.Insert(pNewNode);
	pNewNode = btree.InsertRightChild(pNode, 'F');
	q.Insert(pNewNode);
	// ����ͷԪ��D���ӣ�����D���Һ��ӽ��G�����������ĺ��ӽ�����
	q.Delete(pNode);
	pNewNode = btree.InsertRightChild(pNode, 'G');
	q.Insert(pNewNode);
	// ����ͷԪ��E���ӣ���E�޺������Բ��������ӽ��
	q.Delete(pNode);
	// ����ͷԪ��F���ӣ�����F�ĺ��ӽ��H��I�����������ĺ��ӽ�����
	q.Delete(pNode);
	pNewNode = btree.InsertLeftChild(pNode, 'H');
	q.Insert(pNewNode);
	pNewNode = btree.InsertRightChild(pNode, 'I');
	q.Insert(pNewNode);
	// ���ν�G��H��I���ӣ��������޺������Բ��������ӽ��
	q.Delete(pNode);
	q.Delete(pNode);
	q.Delete(pNode);
	return 0;
}
