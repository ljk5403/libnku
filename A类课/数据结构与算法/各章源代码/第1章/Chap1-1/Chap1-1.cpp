//Chap1-1.cpp
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
	int result=1;
	for(int i=2;i<=n;i++)
		result=result*i;
	return result;
}