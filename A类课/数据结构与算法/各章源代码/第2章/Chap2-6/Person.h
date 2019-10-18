/* Person.h：约瑟夫数据元素结点类*/
#ifndef PERSON
#define PERSON
class Person
{
	public:
		void SetPerson(int no,int password);		//给结点赋值；
		int GetNo(){return No;}						//取编号
		int	GetPassWord(){return PassWord;}			//取密码
		void OutPutPerson(ostream& out) const;		//输出结点数据
	private:
		int No;
		int PassWord;
};
//实现给结点赋值函数
void Person::SetPerson(int no,int password)
{
	No=no;
	PassWord=password;
}
//实现输出结点数据函数
void Person::OutPutPerson(ostream& out) const
{
	out<<"出圈人编号："<<No<<endl;
	out<<"出圈人密码："<<PassWord<<endl;
}
//重载插入运算符<<
ostream& operator<<(ostream& out,const Person& x)
{
	x.OutPutPerson(out);
	return out;
}
#endif
