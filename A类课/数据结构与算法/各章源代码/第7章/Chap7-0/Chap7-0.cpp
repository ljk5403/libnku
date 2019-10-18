// Chap7_0.cpp
#include <iostream>
#include "SortAlgorithms.h"
using namespace std;
int main()
{
	double nR[] = {0, 43.56, 5.63, 3.36, 28.3, 17.55, 3.36, 22, 3.63};
	int nI, nSize=sizeof(nR)/sizeof(nR[0])-1;
	int nD[] = {5, 3, 1};
	QuickSort(nR, nSize);
	for (nI=1; nI<=nSize; nI++)
		cout<<nR[nI]<<' ';
	cout<<endl;
	return 0;
}