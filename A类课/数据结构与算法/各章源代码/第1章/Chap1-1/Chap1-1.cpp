//Chap1-1.cpp
#include <iostream>
using namespace std;
int fac(int);
int main()
{
	int n, c;
	cout<<"请输入n的值：";
	cin>>n;
	c = fac(n);
	cout<<n<<"的阶乘为"<<c<<endl;
	return 0;
}
int fac(int n)
{
	int result=1;
	for(int i=2;i<=n;i++)
		result=result*i;
	return result;
}