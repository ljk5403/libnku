//Chap1-5.cpp
#include<iostream>
#include"permutation.h"
using namespace std;
int main()
{	
	int n;
	cout<<"������n��";
	cin>>n;
	permutation p(n);
	p.compute(1);
	return 0;
}
