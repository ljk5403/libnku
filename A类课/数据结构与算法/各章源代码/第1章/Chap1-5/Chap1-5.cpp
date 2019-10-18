//Chap1-5.cpp
#include<iostream>
#include"permutation.h"
using namespace std;
int main()
{	
	int n;
	cout<<"ÇëÊäÈën£º";
	cin>>n;
	permutation p(n);
	p.compute(1);
	return 0;
}
