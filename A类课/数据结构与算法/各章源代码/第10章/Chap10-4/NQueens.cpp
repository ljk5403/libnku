#include<iostream>
using namespace std;
#define N 4
int x[N+1];
bool Place(int k, int i){//第k行、第i列的位置是否可以放置皇后
	for (int j=1; j < k; j++){
		if (x[j] == i || abs(x[j]-i) == abs(j-k) ){
			return false;
		}
	}
	return true;
}

void NQueens(int k, int n){
	for (int i=1; i <= n; i++){
		if( Place(k, i) ){
			x[k] = i;
			if (k==n) {
				for (int j=1; j <= n; j++){
					cout << x[j] << ' ';
				}
				cout << endl;
			}else{
				NQueens(k+1, n);
			}
		}
	}
}
int main()
{
	NQueens(1,N);
}
