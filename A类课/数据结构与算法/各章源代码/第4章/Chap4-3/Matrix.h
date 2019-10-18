#ifndef MATRIX
#define MATRIX
template <class T>
class Matrix {
public:
	Matrix(int rsz=1,int csz=1);					//���캯������������
	Matrix(const Matrix<T>& M );					//�������캯��
	~Matrix();										//����������ɾ������
	T& operator()(int i,int j)const;				//�����±������
	Matrix<T>& operator=(const Matrix<T>& M);		//���ظ�ֵ�����
	int Rows();										//ȡ���������
	int Columns();									//ȡ���������
	template<class T>
	friend Matrix<T> operator+(const Matrix<T>& A,const Matrix<T>& B);
													//������ӣ���Ԫ����
	template<class T>
	friend Matrix<T> operator-(const Matrix<T>& A,const Matrix<T>& B);
													//�����������Ԫ����
	template<class T>
	friend Matrix<T> operator*(const Matrix<T>& A,const Matrix<T>& B);
													//������ˣ���Ԫ����
	template<class T>
	friend	Matrix<T> Transpose(const Matrix<T>& A);//����ת�ã���Ԫ����
	void OutPut(ostream& out)const;					// ������ŵ������out�����
private:
	int rsize,csize;			//��������������
	T *element;					//����Ĵ�ſռ�
};
//ʵ�ֹ��캯��
template <class T>
Matrix<T>::Matrix(int rsz,int csz)
{
	rsize=rsz;
	csize=csz;
	element=new T[rsize*csize];
}
//ʵ�ֿ������캯��
template <class T>
Matrix<T>::Matrix(const Matrix<T>& M)
{
	rsize=M.rsize;
	csize=M.csize;
	element = new T[rsize*csize];
	for(int i=0;i<rsize*csize;i++)
		element[i]=M.element[i];
}
//ʵ����������
template <class T>
Matrix<T>::~Matrix()
{
	delete []element;
}
//ʵ���±���������������Ԫ�صĸ�ֵ��ȡֵ
template <class T>
T& Matrix<T>::operator()(int i,int j)const
{
	return element[(i-1)*csize+j-1];
}
//ʵ�����ظ�ֵ�����   
template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& M)
{
	if (this!=&M) 					//��������Լ����Լ���ֵ
	{
		delete []element;
		rsize=M.rsize;
		csize=M.csize;
		element=new T[rsize*csize];
		for (int i=0;i<rsize*csize;i++)
			element[i]=M.element[i];
	}
	return *this;
}
//ʵ��ȡ�������� 
template <class T>
int Matrix<T>::Rows()
{
		return rsize;
}
//ʵ��ȡ�������� 
template <class T>
int Matrix<T>::Columns()
{
		return csize;
}
//ʵ�־������
template <class T>
Matrix<T> operator+(const Matrix<T>& A,const Matrix<T>& B)
{
	Matrix<T> C(A.rsize,A.csize);			//��Ž������
	for(int i=1;i<=A.rsize;i++)
	for(int j=1;j<=A.csize;j++)
		C(i,j)=A(i,j)+B(i,j);
	return C;
}
//ʵ�־������
template <class T>
Matrix<T> operator-(const Matrix<T>& A,const Matrix<T>& B)
{
	Matrix<T> C(A.rsize,A.csize);			//��Ž������
	for(int i=1;i<=A.rsize;i++)
		for(int j=1;j<=A.csize;j++)
			C(i,j)=A(i,j)-B(i,j);
	return C;
}
//ʵ�־������
template <class T>
Matrix<T> operator*(const Matrix<T>& A,const Matrix<T>& B)
{
	Matrix<T> C(A.rsize,B.csize);			//��Ž������
	for(int i=1;i<=A.rsize;i++)
	for(int j=1;j<=B.csize;j++)
	{	
		T sum=0;
		for(int k=1;k<=A.csize;k++)
			sum=sum+A(i,k)*B(k,i);
		C(i,j)=sum;
	}
	return C;
}
//ʵ�־���ת��
template <class T>
Matrix<T> Transpose(const Matrix<T>& A)
{
	Matrix<T> AT(A.csize,A.rsize);			//��Ž������
	for(int i=1;i<=A.rsize;i++)
	for(int j=1;j<=A.csize;j++)
		AT(j,i)=A(i,j);
	return AT;
}
//ʵ��һά��������
template<class T>
void Matrix<T>:: OutPut(ostream& out) const
{
	for(int i=0;i<rsize;i++)
	{
		for(int j=0;j<csize;j++)
			out<<element[i*csize+j]<<' ';
		out<<endl;
	}
}
//���ز��������<<
template<class T>
ostream& operator<<(ostream& out,const Matrix<T>& x)
{
	x.OutPut(out);
	return out;
}
#endif