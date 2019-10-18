#ifndef ARRAYONED
#define ARRAYONED
#include <iostream>
#include <assert.h>
using namespace std;
template <class T>
class ArrayOneD {
public:
	ArrayOneD(int sz=0);								//���캯��������һά����
	ArrayOneD(const ArrayOneD<T>& x );				//�������캯��
	~ArrayOneD();									//����������ɾ������
	T& operator[](int index)const;						//�����±������
	ArrayOneD<T>& operator=(const ArrayOneD<T>& v);	//���ظ�ֵ�����
	int Length();										//ȡ���鳤��
	void ReSize(int sz);									//�����������鳤��
	void OutPut(ostream& out)const;				// ������ŵ������out�����
private:
	int size;					//����Ԫ�ظ���
	T *element;				//�����ſռ�
};
//ʵ�ֹ��캯��
template <class T>
ArrayOneD<T>::ArrayOneD(int sz)
{
	assert(sz>=0);					//�±���
	size=sz;
	element=new T[sz];
}
//ʵ�ֿ������캯��
template <class T>
ArrayOneD<T>::ArrayOneD(const ArrayOneD<T>& x)
{
	size=x.size;	
	element = new T[size];
	for(int i=0;i<size;i++)
		element[i]=x.element[i];
}
//ʵ����������
template <class T>
ArrayOneD<T>::~ArrayOneD()
{
	delete []element;
}
//ȡ������index��Ԫ�أ�ʵ�ָ�ֵ��ȡֵ
template <class T>
T& ArrayOneD<T>::operator[](int index)const
{
	assert(index>=0 && index<size); 		//�±���
	return element[index];
}
//ʵ�����ظ�ֵ�����   
template <class T>
ArrayOneD<T>& ArrayOneD<T>::operator=(const ArrayOneD<T>& x)
{
	if (this!=&x) //��������Լ����Լ���ֵ
	{
		delete []element;
		size=x.size;
		element=new T[size];
		for (int i=0;i<size;i++)
			element[i]=x.element[i];
	}
	return *this;
}
//ʵ��ȡ���鳤�� 
template <class T>
int ArrayOneD<T>::Length()
{
		return size;
}
//ʵ�������������鳤��
template <class T>
void ArrayOneD<T>::ReSize(int sz)
{
	delete []element;
	assert(sz>=0);
	size = sz;
	element = new T[size];
}
//ʵ��һά��������
template<class T>
void ArrayOneD<T>:: OutPut(ostream& out) const
{
	for(int i=0;i<size;i++)
		out<<element[i]<<' ';
	out<<endl;
}
//���ز��������<<
template<class T>
ostream& operator<<(ostream& out,const ArrayOneD<T>& x)
{
	x.OutPut(out);
	return out;
}
#endif