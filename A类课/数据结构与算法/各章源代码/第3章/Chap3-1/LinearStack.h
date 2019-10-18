#ifndef LINEARSTACK
#define LINEARSTACK
template<class T>
class LinearStack
{
	public:
		LinearStack(int LSMaxSize);		//���캯����������ջ
		~LinearStack();					//����������ɾ��ջ
		bool IsEmpty();
						//�ж�ջ�Ƿ�Ϊ�գ��շ���true���ǿշ���false
		bool IsFull();
						//�ж�ջ�Ƿ�Ϊ����������true����������false
		int  GetElementNumber(); //��ջ��Ԫ�صĸ���
		bool Push(const T& x); 
						//��ջ������Ԫ��x������ɹ�����true�����ɹ�����false
		bool Top(T& x);
						//��ջ��Ԫ�ص�ֵ����x�У��ɹ�����true��ʧ�ܷ���false
		bool Pop(T& x);
						//��ջ��ɾ��һ��Ԫ�أ�������Ԫ�ص�ֵ����x��
		void OutPut(ostream& out)const;
						// ��˳��ջ�ŵ������out�����
	private:
		int top;		//������ʾջ��
		int MaxSize;	//ջ�����Ԫ�ظ���
		T *element;		//һά��̬����
};
//ʵ�ֹ��캯��
template<class T>
LinearStack<T>::LinearStack(int LSMaxSize)
{
	MaxSize=LSMaxSize;
	element=new T[LSMaxSize];
	top=-1;                    
}
//ʵ����������
template<class T>
LinearStack<T>::~LinearStack()
{
	delete []element;
}
//ʵ���ж�ջ�Ƿ�Ϊ��
template<class T>
bool LinearStack<T>::IsEmpty()
{
	return top==-1;
}
//ʵ���ж�ջ�Ƿ�Ϊ��
template<class T>
bool LinearStack<T>::IsFull()
{
	return top==MaxSize;
}
//ʵ�ֽ�ջ
template<class T>
bool LinearStack<T>::Push(const T& x)
{
	if (IsFull())
		return false;
	else
	{
		top++;
		element[top]=x;
		return true;
	}
}
//ʵ����ջ��Ԫ��
template<class T>
bool LinearStack<T>::Top(T& x)
{
	if (IsEmpty())
		return false;
	else
	{
		x=element[top];
		return true;
	}
}
//ʵ�ֳ�ջ
template<class T>
bool LinearStack<T>::Pop(T& x)
{
	if (IsEmpty())
		return false;
	else
	{
		x=element[top];
		top--;
		return true;
	}
}
//ʵ��˳��ջ�����
template<class T>
void LinearStack<T>:: OutPut(ostream& out) const
{
	for(int i=0;i<top;i++)
		out<<element[i]<<endl;
}
//���ز��������<<
template<class T>
ostream& operator<<(ostream& out,const LinearStack<T>& x)
{
	x.OutPut(out);
	return out;
}
#endif
