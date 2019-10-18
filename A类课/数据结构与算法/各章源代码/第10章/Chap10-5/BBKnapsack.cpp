#include<iostream>
#include<iterator>
#include "Heap.h"
using namespace std;

//节点通过bound边界值比较大小，创建大根堆。
template<class Type>
bool operator <(const Type a, const Type b) {
	if (a.bound < b.bound)
		return true;
	else
		return false;
}

struct node
{
	int level;             //搜索到的层数
	int profit;            //物品的价值
	int weight;           //物品的重量
	float bound;          //该节点的边界值
};

//计算每个节点的边界值
float bound(node u, int W, int n, const int w[], const int p[]) {
	int j, k;
	int total;
	float result;
	
	if (u.weight >= W)
		return 0;
	else {
		result = u.profit;
		j = u.level==-1?0:u.level-1;
		total = u.weight;
		while (j < n && total + w[j] <= W) {
			total = total + w[j]; // Grab as many items
			result = result + p[j]; // as possible.
			j++;
		}
		k = j;
		if (k < n) 
			result = result + (W - total) * p[k] / w[k];
		return result; 
	}
}

//分支限界策略求解最大价值
void Branch_and_Bound_Knapsack (int n, const int p[], const int w[],	int W,int& maxprofit)
{
	heap<node> H;
	H.S = new node[2*n+1];
	H.heapsize = 0;
	node u, v;
	v.level = -1; v.profit = 0; v.weight = 0;
	maxprofit = 0;
	v. bound = bound(v, W, n, w, p);
	insert(H, v);
	while (H.heapsize != 0){
		v=removeRoot(H);
		if (v.bound > maxprofit) {
			u.level = v.level+1;
			u.weight = v.weight + w[u.level];
			u.profit = v.profit + p[u.level]; 
			if (u.weight <= W && u.profit > maxprofit){
				maxprofit = u.profit;
			}
			u.bound = bound(u,W,n,w,p);
			if (u.bound > maxprofit){
				insert(H, u);
			}
			u.weight = v.weight;
			
			u.profit = v.profit;
			u.bound = bound(u, W, n, w, p);
			if (u.bound > maxprofit){
				insert(H,u);
			}
		}
	}
	delete [] H.S;
}

void main(){
	int n = 4;
	int W = 16;
	int p[] = {40,30,50,10};
	int w[] = {2,5,10,5};
	int max;
	Branch_and_Bound_Knapsack(n, p, w, W, max);
	cout << "获得的最大价值为" << max << endl;
}
