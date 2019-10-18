#include<iostream>
using namespace std;

template<typename Type>
int* longestCommonSubsequence(Type x,Type y, int m, int n)
{
    int *L=new int[(m+1)*(n+1)],i,j;
    for(i=1; i<=m; i++)
    {
        L[i*(n+1)]=0;
    }
    for(j=0; j<=n; j++)
    {
        L[j]=0;
    }
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(*(x+i-1)==*(y+j-1))
            {
                L[i*(n+1)+j]=L[(i-1)*(n+1)+j-1]+1;
            }
            else if(L[(i-1)*(n+1)+j]>=L[i*(n+1)+j-1])
            {
                L[i*(n+1)+j]=L[(i-1)*(n+1)+j];
            }
            else
            {
                L[i*(n+1)+j]=L[i*(n+1)+j-1];
            }
        }
    }
    return L;
}

template<typename Type>
void printAnswer(int *c,int n,Type x,Type y,int i,int j)
{
    if(i==0||j==0)
        return;
    if( x[i-1]==y[j-1] )
    {
        printAnswer (c,n,x,y,i-1,j-1);
        cout<<x[i-1]<<" ";
    }
    else if(c[(i-1)*(n+1)+j]>=c[i*(n+1)+j-1])
        printAnswer (c,n,x,y,i-1,j);
    else
        printAnswer (c,n,x,y,i,j-1);
}

int main()
{
	char *x="ACCGGTCGAGTGCGCGGAAGCCGGCCGAA",
		*y="GTCGTTCGGAATGCCGTTGCTCTGTAAA";

	int *c=longestCommonSubsequence(x,y,29,28);
	printAnswer(c,28,x,y,29,28);
	cout<<endl;
}