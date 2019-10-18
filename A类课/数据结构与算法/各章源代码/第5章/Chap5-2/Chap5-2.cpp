/* Chap5_2.cpp：创建链式存储结构的二叉树*/
#include "LinkedBinTree.h"
int main()
{
	LinkedBinTree<char> btree;//声明以char为数据元素的二叉树
	LinkedNode<char> *pNode=NULL, *pNewNode=NULL;
	LinkQueue<LinkedNode<char>*> q;
	// 按层次创建二叉树
	// 创建根结点，并将根结点入队
	pNewNode = btree.CreateRoot('A');
	q.Insert(pNewNode);
	// 将队头元素A出队，创建A的孩子结点B和C，并将创建的孩子结点入队
	q.Delete(pNode);
	pNewNode = btree.InsertLeftChild(pNode, 'B');
	q.Insert(pNewNode);
	pNewNode = btree.InsertRightChild(pNode, 'C');
	q.Insert(pNewNode);
	// 将队头元素B出队，创建B的左孩子结点D，并将创建的孩子结点入队
	q.Delete(pNode);
	pNewNode = btree.InsertLeftChild(pNode, 'D');
	q.Insert(pNewNode);
	// 将队头元素C出队，创建C的孩子结点E和F，并将创建的孩子结点入队
	q.Delete(pNode);
	pNewNode = btree.InsertLeftChild(pNode, 'E');
	q.Insert(pNewNode);
	pNewNode = btree.InsertRightChild(pNode, 'F');
	q.Insert(pNewNode);
	// 将队头元素D出队，创建D的右孩子结点G，并将创建的孩子结点入队
	q.Delete(pNode);
	pNewNode = btree.InsertRightChild(pNode, 'G');
	q.Insert(pNewNode);
	// 将队头元素E出队，因E无孩子所以不创建孩子结点
	q.Delete(pNode);
	// 将队头元素F出队，创建F的孩子结点H和I，并将创建的孩子结点入队
	q.Delete(pNode);
	pNewNode = btree.InsertLeftChild(pNode, 'H');
	q.Insert(pNewNode);
	pNewNode = btree.InsertRightChild(pNode, 'I');
	q.Insert(pNewNode);
	// 依次将G、H和I出队，因它们无孩子所以不创建孩子结点
	q.Delete(pNode);
	q.Delete(pNode);
	q.Delete(pNode);
	return 0;
}
