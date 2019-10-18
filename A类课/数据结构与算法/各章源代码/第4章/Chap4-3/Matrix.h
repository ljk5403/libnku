#ifndef MATRIX
#define MATRIX
template <class T>
class Matrix {
public:
	Matrix(int rsz=1,int csz=1);					//构造函数，创建矩阵
	Matrix(const Matrix<T>& M );					//拷贝构造函数
	~Matrix();										//析构函数，删除矩阵
	T& operator()(int i,int j)const;				//重载下标运算符
	Matrix<T>& operator=(const Matrix<T>& M);		//重载赋值运算符
	int Rows();										//取矩阵的行数
	int Columns();									//取矩阵的列数
	template<class T>
	friend Matrix<T> operator+(const Matrix<T>& A,const Matrix<T>& B);
													//矩阵相加，友元函数
	template<class T>
	friend Matrix<T> operator-(const Matrix<T>& A,const Matrix<T>& B);
													//矩阵相减，友元函数
	template<class T>
	friend Matrix<T> operator*(const Matrix<T>& A,const Matrix<T>& B);
													//矩阵相乘，友元函数
	template<class T>
	friend	Matrix<T> Transpose(const Matrix<T>& A);//矩阵转置，友元函数
	void OutPut(ostream& out)const;					// 将矩阵放到输出流out中输出
private:
	int rsize,csize;			//矩阵行数和列数
	T *element;					//矩阵的存放空间
};
//实现构造函数
template <class T>
Matrix<T>::Matrix(int rsz,int csz)
{
	rsize=rsz;
	csize=csz;
	element=new T[rsize*csize];
}
//实现拷贝构造函数
template <class T>
Matrix<T>::Matrix(const Matrix<T>& M)
{
	rsize=M.rsize;
	csize=M.csize;
	element = new T[rsize*csize];
	for(int i=0;i<rsize*csize;i++)
		element[i]=M.element[i];
}
//实现析构函数
template <class T>
Matrix<T>::~Matrix()
{
	delete []element;
}
//实现下标运算符，方便矩阵元素的赋值和取值
template <class T>
T& Matrix<T>::operator()(int i,int j)const
{
	return element[(i-1)*csize+j-1];
}
//实现重载赋值运算符   
template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& M)
{
	if (this!=&M) 					//如果不是自己给自己赋值
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
//实现取矩阵行数 
template <class T>
int Matrix<T>::Rows()
{
		return rsize;
}
//实现取矩阵列数 
template <class T>
int Matrix<T>::Columns()
{
		return csize;
}
//实现矩阵相加
template <class T>
Matrix<T> operator+(const Matrix<T>& A,const Matrix<T>& B)
{
	Matrix<T> C(A.rsize,A.csize);			//存放结果矩阵
	for(int i=1;i<=A.rsize;i++)
	for(int j=1;j<=A.csize;j++)
		C(i,j)=A(i,j)+B(i,j);
	return C;
}
//实现矩阵相减
template <class T>
Matrix<T> operator-(const Matrix<T>& A,const Matrix<T>& B)
{
	Matrix<T> C(A.rsize,A.csize);			//存放结果矩阵
	for(int i=1;i<=A.rsize;i++)
		for(int j=1;j<=A.csize;j++)
			C(i,j)=A(i,j)-B(i,j);
	return C;
}
//实现矩阵相乘
template <class T>
Matrix<T> operator*(const Matrix<T>& A,const Matrix<T>& B)
{
	Matrix<T> C(A.rsize,B.csize);			//存放结果矩阵
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
//实现矩阵转置
template <class T>
Matrix<T> Transpose(const Matrix<T>& A)
{
	Matrix<T> AT(A.csize,A.rsize);			//存放结果矩阵
	for(int i=1;i<=A.rsize;i++)
	for(int j=1;j<=A.csize;j++)
		AT(j,i)=A(i,j);
	return AT;
}
//实现一维数组的输出
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
//重载插入运算符<<
template<class T>
ostream& operator<<(ostream& out,const Matrix<T>& x)
{
	x.OutPut(out);
	return out;
}
#endif