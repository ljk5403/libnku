#include<iostream>
#include"QuickSort.h"
using namespace std;

#define N 4
struct Job{
	int id;//任务编号
	int deadline;//截止时间
	int profile;//奖励
};

template<class Type>
bool operator <=(const Type a, const Type b) {
	if (a.profile <= b.profile)
		return false;
	else
		return true;
}

template<class Type>
bool operator >=(const Type a, const Type b) {
	if (a.profile >= b.profile)
		return false;
	else
		return true;
}

int main(){
	Job *jobs = new Job[N+1];
	int M[N][3]={ {1,2,30},{2,1,35},{3,2,25},{4,1,40} };
	for(int i=1; i<=N; i++){
		jobs[i].id = M[i-1][0];
		jobs[i].deadline = M[i-1][1];
		jobs[i].profile = M[i-1][2];
	}
	QuickSort<Job>(jobs, 1, N);//按照奖励降序排列
	cout << jobs[1].id << endl;
	int deadline = 1;
	for(int i=2; i<=N; i++){
		if ( jobs[i].deadline > deadline){
			cout << jobs[i].id << endl;
			deadline++;
		}
	}
	delete [] jobs;
	int t;
	cin >> t;
}
