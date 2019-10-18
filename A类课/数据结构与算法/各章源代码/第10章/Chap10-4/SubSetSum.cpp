#include<iostream>
using namespace std;

#define N 4
int m = 6;
int x[N+1];
int w[N+1] = {0, 1, 2, 3, 4};

void SubSetSum(float s, int k, float r){
	x[k]=1;
	if (s+w[k] == m){
		for (int j=1; j<=k; j++){
			cout << x[j] << ' ' ;
		}
		cout << endl;
	}else if (s+w[k] +w[k+1] <= m){
		SubSetSum(s+w[k], k+1, r-w[k]);
	}
	
	if ( (s+r-w[k] >=m) && (s+w[k+1] <=m) ){
		x[k] = 0;
		SubSetSum(s, k+1, r-w[k]);
	}
}

int main()
{
    SubSetSum(0, 1, 10);
}
