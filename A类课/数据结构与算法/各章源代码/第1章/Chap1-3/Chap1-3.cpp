//Chap1-3.cpp
#include <iostream>
using namespace std;
int main()
{
	int i, j, k, m, n;
	for(i=1; i<=9; i++)					//外循环，搜索百位
		for(j=0; j<=9; j++)				//中层循环，搜索十位
			for(k=0; k<=9; k++)			//内循环，搜索个位
			{
				m=i*i*i+j*j*j+k*k*k;
				n=100*i+10*j+k;
				if(m==n)
					cout<<m<<endl;		//输出找到的水仙花数
			}
	return 0;
}
