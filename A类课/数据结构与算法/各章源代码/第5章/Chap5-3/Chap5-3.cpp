/* Chap5_3.cpp：二叉树链式存储结构的应用问题*/
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

	cout<<"当前二叉树的元素为：\n";
	cout<<"先序遍历结果为：";
	btree.PreOrderTraverse();
	cout<<endl;
	cout<<"中序遍历结果为：";
	btree.InOrderTraverse();
	cout<<endl;
	cout<<"后序遍历结果为：";
	btree.PostOrderTraverse();
	cout<<endl;
	cout<<"逐层遍历结果为：";
	btree.LevelOrderTraverse();
	cout<<endl;
	// 将以结点F为根的子树删除
	pNode = btree.SearchByKey('F');
	btree.DeleteSubTree(pNode);
	cout<<"将以结点F为根的子树删除后";
	cout<<"当前二叉树的元素为：\n";
	cout<<"先序遍历结果为：";
	btree.PreOrderTraverse();
	cout<<endl;
	cout<<"中序遍历结果为：";
	btree.InOrderTraverse();
	cout<<endl;
	cout<<"后序遍历结果为：";
	btree.PostOrderTraverse();
	cout<<endl;
	cout<<"逐层遍历结果为：";
	btree.LevelOrderTraverse();
	cout<<endl;
	// 将结点G的值改为“F”
	pNode = btree.SearchByKey('G');
	btree.ModifyNodeValue(pNode, 'F');
	cout<<"将结点G的值改为“F”后";
	cout<<"当前二叉树的元素为：\n";
	cout<<"先序遍历结果为：";
	btree.PreOrderTraverse();
	cout<<endl;
	cout<<"中序遍历结果为：";
	btree.InOrderTraverse();
	cout<<endl;
	cout<<"后序遍历结果为：";
	btree.PostOrderTraverse();
	cout<<endl;
	cout<<"逐层遍历结果为：";
	btree.LevelOrderTraverse();
	cout<<endl;
	// 将二叉树清空
	btree.Clear();
	cout<<"将二叉树清空后";
	cout<<"当前二叉树的元素为：\n";
	cout<<"先序遍历结果为：";
	btree.PreOrderTraverse();
	cout<<endl;
	cout<<"中序遍历结果为：";
	btree.InOrderTraverse();
	cout<<endl;
	cout<<"后序遍历结果为：";
	btree.PostOrderTraverse();
	cout<<endl;
	cout<<"逐层遍历结果为：";
	btree.LevelOrderTraverse();
	cout<<endl;
	return 0;
}
