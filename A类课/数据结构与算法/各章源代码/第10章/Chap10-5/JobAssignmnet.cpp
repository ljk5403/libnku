#include<iostream>
#include <limits>
#include "Heap.h"
using namespace std;

//�ڵ�ͨ��bound�߽�ֵ�Ƚϴ�С������С���ѡ�
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
	int x[N];           //�������Ա������
	int k;              //�������Ĳ���
	float t;             //�ڵ�ǰ�������㣬�Ѿ��������������ʱ��
	float bound;         //�ýڵ�ı߽�ֵ
};

float job_assign(float CostMatrix[][N],int job[]) {
	int i, j, m;
	node *xnode, *pnode;
	xnode = new node;

	heap<node> H;
	H.S = new node[N*N+1];
	H.heapsize = 0;
	float min;
	//��ʼ��Ϊ-1����ʾ������Ա��û�з�������
	for (i = 0; i < N; i++) {
		xnode->x[i] = -1;
	}

	xnode->k = 0;
	xnode->t = 0;
	xnode->bound = 0;
	//ͨ����֧�޽磬Ѱ�����Ž⣬�������ڽڵ��x������
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
	//����ʱ�䱣����min
	min = xnode->bound;
	//�����ŽⱣ��������job��
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
