#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

int str2int(string k)//���ַ���ת��������
{
    int back;
    stringstream ss;
    ss << k;
    ss >> back;
    return back;
}

long product(string x,string y)//���β��Լ���������˻�
{
    int s = x.size();
    string A,B,C,D;

    if( s > 1)
    {
        A = x.substr(0,s/2);
        B = x.substr(s/2,s-1);
        C = y.substr(0,s/2);
        D = y.substr(s/2,s-1);
    }

    int na = str2int(A);
    int nb = str2int(B);
    int nc = str2int(C);
    int nd = str2int(D);

    long result = 0;
    if( s == 2)
    {
        result = (na*10+nb) * (nc*10+nd);
    }
    else
    {   //�ݹ����product()����
        result = product(A,C)*pow(10.0,s)+((na-nb)*(nd-nc)+product(A,C)+product(B, D))* pow(10.0,s/2)+product(B,D);
    }
    return result;
}

int main()
{
	string A, B;
	cout<<"�������һ��������: ";
	cin>>A;
	cout<<"������ڶ���������: ";
	cin>>B;
	cout<<A+"*"+B+" = "<<product(A,B) <<endl;
	int t;
	cin >>t;
}