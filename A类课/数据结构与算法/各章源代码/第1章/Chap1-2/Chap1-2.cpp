//Chap1-2.cpp
#include <iostream>
using namespace std;
int fac(int);
int main()
{
	int n, c;
	cout<<"������n��ֵ��";
	cin>>n;
	c = fac(n);
	cout<<n<<"�Ľ׳�Ϊ"<<c<<endl;
	return 0;
}
int fac(int n)
{
	if (n == 1 || n == 0)
		return 1;
	else
		return n*fac(n-1);
}
