//TestGlist.cpp
#include <iostream>
using namespace std;
#include "GList.h"
int main()
{
	GList L;
	L.CreateList();
	cout<<L.Depth();
	cout<<L;
}