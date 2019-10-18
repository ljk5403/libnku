/* Chap5_1.cpp：二叉树顺序存储结构的应用问题*/
#include "ArrayBinTree.h"
int main()
{
	ArrayBinTree<char> btree(3);	//声明以char为数据元素的3层二叉树
	btree.CreateRoot('A');
	btree.InsertLeftChild(1, 'B');
	btree.InsertRightChild(1, 'C');
	btree.InsertLeftChild(3, 'D');
	cout<<"当前二叉树的元素为：\n";
	btree.LevelOrderTraverse();
	btree.DeleteSubTree(3);
	cout<<"当前二叉树的元素为：\n";
	btree.LevelOrderTraverse();
	btree.Clear();
	cout<<"当前二叉树的元素为：\n";
	btree.LevelOrderTraverse();
	return 0;
}
