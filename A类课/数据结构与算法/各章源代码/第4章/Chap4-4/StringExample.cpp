/*StringExample.cpp���ַ���Ӧ������*/
#include <iostream>
using namespace std;
#include "LinearString.h"
int main()
{
	LinearString S1S1;
	char str[10];
	cout<<"�������ַ���S1��"<<endl;
	cin>>str;
	LinearString *S1=new LinearString(str);
	cout<<"�������ַ���S2��"<<endl;
	cin>>str;
	LinearString *S2=new LinearString(str);
	S1S1.StrCat(*S1);
	S1S1.StrCat(*S1);
	if(S1S1.IndexKMP(*S2))
		cout<<*S1<<"��λ�����"<<*S2<<endl;
	else
		cout<<*S1<<"��λ�󲻰���"<<*S2<<endl;
	return 0;
}
