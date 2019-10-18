#include "SearchAlgorithms.h"
#include <iostream>
using namespace std;
int main()
{
	int nR[] = {0, 43, 56, 37, 28, 17, 39, 22};
	int nSize=sizeof(nR)/sizeof(nR[0])-1;
	int nK = 39, nX=0;
	LinkedBinTree<int> btree;	// 定义二叉树对象
	LinkedNode<int> *pNode=NULL;	// 用于保存查找结果
	CreateBST(nR, nSize, btree);	// 根据数组nR中的元素创建二叉排序树
	btree.InOrderTraverse();	// 按中序遍历显示二叉排序树中的所有元素
	cout<<endl;
	// 根据给定值nK进行二叉排序树查找，pNode指向匹配元素所在的结点
	pNode = SearchBST(btree.GetRoot(), nK);
	if (pNode != NULL)	// 查找成功
	{
		btree.GetNodeValue(pNode, nX);	// 获取匹配元素的值
		cout<<nX<<endl;	// 输出匹配元素的值
	}
	else
		cout<<"查找失败！"<<endl;
	return 0;
}
