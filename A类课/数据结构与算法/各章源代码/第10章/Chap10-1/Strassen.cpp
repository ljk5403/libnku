#include<iostream>
#include<time.h>
#include<stdlib.h>
#include"Matrix.h"

using namespace std;

#define N 16
//基于分治策略的strassen算法
void strassen(int n,Matrix<int> A,Matrix<int> B,Matrix<int> &C)
{

    int i,j;
    if (n==2)
	{
		C=A*B;
	}
    else
    {
        int m=n/2;
        Matrix<int> A11(m,m),A12(m,m),A21(m,m),A22(m,m);
        Matrix<int> B11(m,m),B12(m,m),B21(m,m),B22(m,m);
        Matrix<int> C11(m,m),C12(m,m),C21(m,m),C22(m,m);
        Matrix<int> M1(m,m),M2(m,m),M3(m,m),M4(m,m),M5(m,m),M6(m,m),M7(m,m);
        Matrix<int> AA(m,m),BB(m,m),MM1(m,m),MM2(m,m);

		for(i=1; i<=m; i++)
		{
            for(j=1; j<=m; j++)
            {
                //将矩阵A和B平均分为四个小矩阵
                A11(i,j)=A(i,j);
                A12(i,j)=A(i,j+m);
                A21(i,j)=A(i+m,j);
                A22(i,j)=A(i+m,j+m);
                B11(i,j)=B(i,j);
                B12(i,j)=B(i,j+m);
                B21(i,j)=B(i+m,j);
                B22(i,j)=B(i+m,j+m);
            }
		}

		//以下计算M1,M2,M3,M4,M5,M6,M7(递归部分)
		AA = A11 + A22;
		BB = B11 + B22;
        strassen(m,AA,BB,M1);//M1=(A11+A22)(B11+B22)

		AA = A21+A22;
        strassen(m,AA,B11,M2);//M2=(A21+A22)B11

		BB = B12 - B22;
        strassen(m,A11,BB,M3);//M3=A11(B12-B22)

		BB = B21 - B11;
        strassen(m,A22,BB,M4);//M4=A22(B21-B11)

		AA = A11 + A12;
        strassen(m,AA,B22,M5);//M5=(A11+A12)B22

		AA = A21 - A11;
		BB = B11 + B12;
        strassen(m,AA,BB,M6);//M6=(A21-A11)(B11+B12)

		AA = A12 - A22;
		BB = B21 + B22;
        strassen(m,AA,BB,M7);//M7=(A12-A22)(B21+B22)

		MM1 = M1 + M4;
		MM2 = MM1 - M5;
		C11 = MM2 + M7;

		C12 = M3 + M5;
		C21 = M2 + M4;

		MM1 = M1 + M3;
		MM2 = MM1 - M2;
		C22 = MM2 + M6;

        for(i=1; i<=m; i++)
            for(j=1; j<=m; j++)
            {
                C(i,j)=C11(i,j);
                C(i,j+m)=C12(i,j);
                C(i+m,j)=C21(i,j);
                C(i+m,j+m)=C22(i,j);
            }
    }
}

int main()
{
    int i,j;
    Matrix<int> A(N,N),B(N,N),C(N,N);     //定义三个矩阵A,B,C
    for(i=1;i<=N;i++)                 //系统随机为A,B矩阵赋值
		for(j=1;j<=N;j++)
		{
			A(i,j)=(int)(10.0*rand()/(RAND_MAX+1.0));
			B(i,j)=(int)(10.0*rand()/(RAND_MAX+1.0));
		}

	cout<<"随机生成"<<N<<"阶矩阵A:"<<endl;
	cout << A << endl;
	cout<<"随机生成"<<N<<"阶矩阵B:"<<endl;
	cout << B << endl;

	strassen(N,A,B,C);               //调用strassen函数计算A,B的乘积
    cout<<"A,B的乘积矩阵C:"<<endl;   //输出计算结果
    cout<< C <<endl;
}
