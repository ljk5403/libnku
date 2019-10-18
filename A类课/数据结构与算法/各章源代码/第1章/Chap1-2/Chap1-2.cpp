//Chap1-2.cpp
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
	if (n == 1 || n == 0)
		return 1;
	else
		return n*fac(n-1);
}
