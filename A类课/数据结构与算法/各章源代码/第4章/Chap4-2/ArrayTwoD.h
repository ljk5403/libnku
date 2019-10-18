#ifndef ARRAYTWOD
#define ARRAYTWOD
#include <iostream>
#include <assert.h>
#include "ArrayOneD.h"
using namespace std;
template <class T>
class ArrayTwoD {
public:
	ArrayTwoD(int rsz=0,int csz=0);						//构造函数，创建二维数组
	ArrayTwoD(const ArrayTwoD<T>& x );				//拷贝构造函数
	~ArrayTwoD();									//析构函数，删除数组
	ArrayOneD<T>& operator[](int index)const;			//下标运算符
	ArrayTwoD<T>& operator=(const ArrayTwoD<T>& M);	//重载赋值运算符
	int Rows();										//取数组行数
	int Columns();										//取数组列数
	void OutPut(ostream& out)const;				// 将数组放到输出流out中输出
private:
	int rsize,csize;			//数组行数和列数
	ArrayOneD<T> *row;			//数组存放空间
};
//实现构造函数
template <class T>
ArrayTwoD<T>::ArrayTwoD(int rsz,int csz)
{
	assert(rsz>=0 && csz>=0);			//下标检查
	rsize=rsz;
	csize=csz;
	row=new ArrayOneD<T>[rsize];		//创建rsize个一维数组
	for(int i=0;i<rsize;i++)
		row[i].ReSize(csize);
}
//实现拷贝构造函数
template <class T>
ArrayTwoD<T>::ArrayTwoD(const ArrayTwoD<T>& M)
{
	rsize=M.rsize;
	csize=M.csize;
	row = new ArrayOneD<T>[rsize];	
	for(int i=0;i<rsize;i++)
		row[i]=M.row[i];
}
//实现析构函数
template <class T>
ArrayTwoD<T>::~ArrayTwoD()
{
	delete []row;
}
//实现下标运算符
template <class T>
ArrayOneD<T>& ArrayTwoD<T>::operator[](int index)const
{
	assert(index>=0 && index<rsize);		//下标检查
	return row[index];
}
//实现重载赋值运算符   
template <class T>
ArrayTwoD<T>& ArrayTwoD<T>::operator=(const ArrayTwoD<T>& M)
{
	if (this!=&M) //如果不是自己给自己赋值
	{
		delete []row;
		rsize=M.rsize;
		csize=M.csize;
		row=new ArrayOneD<T>[rsize];
		for (int i=0;i<rsize;i++)
			row[i]=M.row[i];
	}
	return *this;
}
//实现取数组的行数 
template <class T>
int ArrayTwoD<T>::Rows()
{
		return rsize;
}
//实现取数组的列数 
template <class T>
int ArrayTwoD<T>::Columns()
{
		return csize;
}
//实现二维数组的输出
template<class T>
void ArrayTwoD<T>:: OutPut(ostream& out) const
{
	for(int i=0;i<rsize;i++)
		out<<row[i];
	out<<endl;
}
//重载插入运算符<<
template<class T>
ostream& operator<<(ostream& out,const ArrayTwoD<T>& x)
{
	x.OutPut(out);
	return out;
}
#endif
