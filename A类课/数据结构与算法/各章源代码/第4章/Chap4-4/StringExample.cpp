/*StringExample.cpp：字符串应用问题*/
#include <iostream>
using namespace std;
#include "LinearString.h"
int main()
{
	LinearString S1S1;
	char str[10];
	cout<<"请输入字符串S1："<<endl;
	cin>>str;
	LinearString *S1=new LinearString(str);
	cout<<"请输入字符串S2："<<endl;
	cin>>str;
	LinearString *S2=new LinearString(str);
	S1S1.StrCat(*S1);
	S1S1.StrCat(*S1);
	if(S1S1.IndexKMP(*S2))
		cout<<*S1<<"移位后包含"<<*S2<<endl;
	else
		cout<<*S1<<"移位后不包含"<<*S2<<endl;
	return 0;
}
