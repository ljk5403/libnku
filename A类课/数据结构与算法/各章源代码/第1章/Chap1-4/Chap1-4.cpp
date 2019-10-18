//Chap1-4.cpp
#include<iostream>
#include<cmath>
using namespace std;
int main()
{  
	float xn, xn1, f, f1;
	cout<<"请输入x的初值：";
	cin>>xn1;
	do
	{ 
		xn=xn1;
		f=((2*xn-4)*xn+3)*xn-6;
		f1=(6*xn-8)*xn+3;
		xn1=xn-f/f1;
	} while(fabs(xn1-xn)>=1e-6);
	cout<<"方程的一个根为："<<xn1<<endl;
	return 0;
}
