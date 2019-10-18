#ifndef ARRAYTWOD
#define ARRAYTWOD
#include <iostream>
#include <assert.h>
#include "ArrayOneD.h"
using namespace std;
template <class T>
class ArrayTwoD {
public:
	ArrayTwoD(int rsz=0,int csz=0);						//���캯����������ά����
	ArrayTwoD(const ArrayTwoD<T>& x );				//�������캯��
	~ArrayTwoD();									//����������ɾ������
	ArrayOneD<T>& operator[](int index)const;			//�±������
	ArrayTwoD<T>& operator=(const ArrayTwoD<T>& M);	//���ظ�ֵ�����
	int Rows();										//ȡ��������
	int Columns();										//ȡ��������
	void OutPut(ostream& out)const;				// ������ŵ������out�����
private:
	int rsize,csize;			//��������������
	ArrayOneD<T> *row;			//�����ſռ�
};
//ʵ�ֹ��캯��
template <class T>
ArrayTwoD<T>::ArrayTwoD(int rsz,int csz)
{
	assert(rsz>=0 && csz>=0);			//�±���
	rsize=rsz;
	csize=csz;
	row=new ArrayOneD<T>[rsize];		//����rsize��һά����
	for(int i=0;i<rsize;i++)
		row[i].ReSize(csize);
}
//ʵ�ֿ������캯��
template <class T>
ArrayTwoD<T>::ArrayTwoD(const ArrayTwoD<T>& M)
{
	rsize=M.rsize;
	csize=M.csize;
	row = new ArrayOneD<T>[rsize];	
	for(int i=0;i<rsize;i++)
		row[i]=M.row[i];
}
//ʵ����������
template <class T>
ArrayTwoD<T>::~ArrayTwoD()
{
	delete []row;
}
//ʵ���±������
template <class T>
ArrayOneD<T>& ArrayTwoD<T>::operator[](int index)const
{
	assert(index>=0 && index<rsize);		//�±���
	return row[index];
}
//ʵ�����ظ�ֵ�����   
template <class T>
ArrayTwoD<T>& ArrayTwoD<T>::operator=(const ArrayTwoD<T>& M)
{
	if (this!=&M) //��������Լ����Լ���ֵ
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
//ʵ��ȡ��������� 
template <class T>
int ArrayTwoD<T>::Rows()
{
		return rsize;
}
//ʵ��ȡ��������� 
template <class T>
int ArrayTwoD<T>::Columns()
{
		return csize;
}
//ʵ�ֶ�ά��������
template<class T>
void ArrayTwoD<T>:: OutPut(ostream& out) const
{
	for(int i=0;i<rsize;i++)
		out<<row[i];
	out<<endl;
}
//���ز��������<<
template<class T>
ostream& operator<<(ostream& out,const ArrayTwoD<T>& x)
{
	x.OutPut(out);
	return out;
}
#endif
