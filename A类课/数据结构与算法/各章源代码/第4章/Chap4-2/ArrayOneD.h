#ifndef ARRAYONED
#define ARRAYONED
#include <iostream>
#include <assert.h>
using namespace std;
template <class T>
class ArrayOneD {
public:
	ArrayOneD(int sz=0);								//构造函数，创建一维数组
	ArrayOneD(const ArrayOneD<T>& x );				//拷贝构造函数
	~ArrayOneD();									//析构函数，删除数组
	T& operator[](int index)const;						//重载下标运算符
	ArrayOneD<T>& operator=(const ArrayOneD<T>& v);	//重载赋值运算符
	int Length();										//取数组长度
	void ReSize(int sz);									//重新设置数组长度
	void OutPut(ostream& out)const;				// 将数组放到输出流out中输出
private:
	int size;					//数组元素个数
	T *element;				//数组存放空间
};
//实现构造函数
template <class T>
ArrayOneD<T>::ArrayOneD(int sz)
{
	assert(sz>=0);					//下标检查
	size=sz;
	element=new T[sz];
}
//实现拷贝构造函数
template <class T>
ArrayOneD<T>::ArrayOneD(const ArrayOneD<T>& x)
{
	size=x.size;	
	element = new T[size];
	for(int i=0;i<size;i++)
		element[i]=x.element[i];
}
//实现析构函数
template <class T>
ArrayOneD<T>::~ArrayOneD()
{
	delete []element;
}
//取索引是index的元素，实现赋值和取值
template <class T>
T& ArrayOneD<T>::operator[](int index)const
{
	assert(index>=0 && index<size); 		//下标检查
	return element[index];
}
//实现重载赋值运算符   
template <class T>
ArrayOneD<T>& ArrayOneD<T>::operator=(const ArrayOneD<T>& x)
{
	if (this!=&x) //如果不是自己给自己赋值
	{
		delete []element;
		size=x.size;
		element=new T[size];
		for (int i=0;i<size;i++)
			element[i]=x.element[i];
	}
	return *this;
}
//实现取数组长度 
template <class T>
int ArrayOneD<T>::Length()
{
		return size;
}
//实现重新设置数组长度
template <class T>
void ArrayOneD<T>::ReSize(int sz)
{
	delete []element;
	assert(sz>=0);
	size = sz;
	element = new T[size];
}
//实现一维数组的输出
template<class T>
void ArrayOneD<T>:: OutPut(ostream& out) const
{
	for(int i=0;i<size;i++)
		out<<element[i]<<' ';
	out<<endl;
}
//重载插入运算符<<
template<class T>
ostream& operator<<(ostream& out,const ArrayOneD<T>& x)
{
	x.OutPut(out);
	return out;
}
#endif