/* Chap2-5.cpp：用顺序表解决约瑟夫问题*/
#include <iostream>
using namespace std;
#include "LinearList.h"
#include "Person.h"
#include <ctime>
#include <cstdlib>
const int MAXSIZE=20; //假设最多有20人
int main()
{	
	double random(double,double);
	LinearList<Person> NodeLList(MAXSIZE);
				//声明最多有MAXSIZE个以Person为数据元素的顺序表对象
	Person person;
	int n,m,index;
	cout<<"请输入人数：";
	cin>>n;
	//下面n个人中的每个人都产生一个随机密码
	srand(unsigned(time(0)));  
	for (int i=1;i<=n;i++)
	{
		person.SetPerson(i,int(random(0,n)));
		NodeLList.Insert(i,person);
	}
	cout<<"当前表的元素为：\n"<<NodeLList<<endl;
	//人员出圈
	NodeLList.GetData(1,person);				//从第1个人开始
	index=1;
	cout<<"出圈人的顺序为：\n";
	while (!NodeLList.IsEmpty())
	{
		m=person.GetPassWord();					 //得到密码
		index=(index-1+m)%n;					 //找到要出圈的人
		if (index==0) index=n;
		NodeLList.DeleteByIndex(index,person);
										//出圈并将出圈人的信息放入person
		n=n-1;									 //人数减1
		cout<<person.GetNo();					 //输出出圈人编号		
	}
	return 0;
} 
//产生随机数函数
double random(double start, double end)
{
    return start+(end-start)*rand()/(RAND_MAX + 1.0);
}
