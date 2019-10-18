#include<iostream>
#include<iterator>
using namespace std;
//动态规划计算m(n,c)
int *knapsack(int *w,int *v,int n,int c)
{
	int *m=new int[(n+1)*(c+1)],i,j;
	for(i=1;i<n+1;i++)
		m[i*(c+1)]=0;
	for(j=0;j<c+1;j++)
		m[j]=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=c;j++){
			m[i*(c+1)+j]=m[(i-1)*(c+1)+j];
			if(w[i-1]<=j)
				if(v[i-1]+m[(i-1)*(c+1)+j-w[i-1]]>m[(i-1)*(c+1)+j])
					m[i*(c+1)+j]=v[i-1]+m[(i-1)*(c+1)+j-w[i-1]];
		}
		return m;
}
//构造问题的解，x[i]=1表示选择物品i，x[i]=0表示不选择。
void printAnswer(int *m,int *w, int c, int n)
{
    int i,j=c;
    int *x=new int[n];
	for(i=n;i>1;i--)
	{
        if(m[i*(c+1)+j]==m[(i-1)*(c+1)+j])
            x[i-1]=0;
        else{
            x[i-1]=1;
            j-=w[i-1];
        }
	}
	x[0]=m[(c+1)+j]>0?1:0;
	for(i=0; i<n;i++)
	{
		cout << x[i] <<endl;
	}
}


int main()
{
	int w[]={2,3,4,5},v[]={3,4,5,7};
	int *m;
	m=knapsack(w,v,4,9);
	printAnswer(m,w,9,4);
	int t;
	cin >>t;
}