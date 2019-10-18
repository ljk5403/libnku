#include<iostream>
#include <limits>
#include "Heap.h"
using namespace std;

//节点通过bound边界值比较大小，创建小根堆。
template<class Type>
bool operator <(const Type a, const Type b) {
	if (a.bound > b.bound)
		return true;
	else
		return false;
}

#define N 4
struct node
{
	int x[N];           //分配给人员的任务
	int k;              //搜索到的层数
	float t;             //在当前的搜索层，已经分配任务所需的时间
	float bound;         //该节点的边界值
};

float job_assign(float CostMatrix[][N],int job[]) {
	int i, j, m;
	node *xnode, *pnode;
	xnode = new node;

	heap<node> H;
	H.S = new node[N*N+1];
	H.heapsize = 0;
	float min;
	//初始化为-1，表示所有人员都没有分配任务
	for (i = 0; i < N; i++) {
		xnode->x[i] = -1;
	}

	xnode->k = 0;
	xnode->t = 0;
	xnode->bound = 0;
	//通过分支限界，寻找最优解，并保存在节点的x数组中
	while (xnode->k != N) {
		for (i = 0; i < N; i++) {
			if (xnode->x[i] == -1) {
				pnode = new node;
				*pnode = *xnode;
				pnode->x[i] = pnode->k;
				pnode->t += CostMatrix[i][pnode->k];
				pnode->bound = pnode->t;
				pnode->k++;
				for (j = pnode->k; j < N; j++) {
					min = numeric_limits<float>::max();
					for (m = 0; m < N; m++) {
						if ((pnode->x[m] == -1) && (CostMatrix[m][j] < min)) {
							min = CostMatrix[m][j];
						}
					}
					pnode->bound += min;
				}
				insert(H, *pnode);
				delete pnode;
			}
		}
		node x = removeRoot(H);
		xnode = &x;
	}
	//最少时间保存在min
	min = xnode->bound;
	//把最优解保存在数组job中
	for (i = 0; i < N; i++) {
		job[i] = xnode->x[i];
	}
	delete [] H.S;
	return min;
}

int main(){
	float Cost[4][4]={{3,8,4,12},{9,12,13,5},{8,7,9,3},{12,7,6,8}};
	int job[4];
	cout << job_assign(Cost,job) <<endl;
	for(int i=0; i< N; i++){
		cout << job[i] << " ";
	}
	cout << endl;
}
