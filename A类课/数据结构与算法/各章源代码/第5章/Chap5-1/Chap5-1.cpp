/* Chap5_1.cpp��������˳��洢�ṹ��Ӧ������*/
#include "ArrayBinTree.h"
int main()
{
	ArrayBinTree<char> btree(3);	//������charΪ����Ԫ�ص�3�������
	btree.CreateRoot('A');
	btree.InsertLeftChild(1, 'B');
	btree.InsertRightChild(1, 'C');
	btree.InsertLeftChild(3, 'D');
	cout<<"��ǰ��������Ԫ��Ϊ��\n";
	btree.LevelOrderTraverse();
	btree.DeleteSubTree(3);
	cout<<"��ǰ��������Ԫ��Ϊ��\n";
	btree.LevelOrderTraverse();
	btree.Clear();
	cout<<"��ǰ��������Ԫ��Ϊ��\n";
	btree.LevelOrderTraverse();
	return 0;
}
