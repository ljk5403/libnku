#include <iostream>

using namespace std;

template<class Type>
void GreedySelector(int n, Type s[], Type f[], bool A[]) {
	A[1] = true; //表示活动进入相容集合，即活动被安排
	int j = 1; //进入相容集合的最后一个活动
	for (int i = 2; i <= n; i++) {
		if (s[i] >= f[j]) {
			A[i] = true;
			j = i;
		} else {
			A[i] = false;
		}
	}
}

int main()
{
	int start[] = {0,1,3,0,3,5,5,6,8,8,2,12};
	int end[] = {0,4,5,6,7,8,9,10,11,12,13,14};
	bool a[12];
	GreedySelector(11, start, end, a);
	for(int i=1; i<12; i++)
	{
		if(a[i]){
			cout << i << " ";
		}
	}
	cout << endl;
}