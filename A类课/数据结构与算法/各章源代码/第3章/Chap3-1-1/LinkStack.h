#ifndef LINKSTACK
#define LINKSTACK
//�洢�����
template<class T>
class LinkNode    //�����
{
	template<class T>
	friend class LinkStack;			//������ջ������Ϊ����
	public:
		LinkNode()//���캯��
		{
			next=NULL;
		}
	private:
		T data;					//���Ԫ��
		LinkNode<T> *next;		//ָ����һ������ָ��
};
//��������ջ��
template<class T>
class LinkStack
{
	public:
		LinkStack ();				//���캯����������ջ
		~LinkStack();				//����������ɾ��ջ
		bool IsEmpty() const;
								//�ж�ջ�Ƿ�Ϊ�գ��շ���true���ǿշ���false
		bool Push(const T& x); 
						//��ջ������Ԫ��x������ɹ�����true�����ɹ�����false
		bool Top(T& x);
						//��ջ��Ԫ�ص�ֵ����x�У��ɹ�����true��ʧ�ܷ���false
		bool Pop(T& x);
						//��ջ��ɾ��һ��Ԫ�أ�������Ԫ�ص�ֵ����x��
		void OutPut(ostream& out) const;	// ��˳��ջ�ŵ������out�����
	private:
		LinkNode<T> *top;			//ָ����������ջ������ָ��
		int size;					//ջ��Ԫ�ظ���
};
//ʵ�ֹ��캯��
template<class T>
LinkStack<T>::LinkStack()
{
	top=NULL;
	size=0;
}
//ʵ����������
template<class T>
LinkStack<T>::~LinkStack()
{
	T x;
	while(top!=NULL)		//ջ�ǿ���Ԫ�����γ�ջ
		Pop(x);
}
//ʵ���ж�ջ�Ƿ�Ϊ��
template<class T>
bool LinkStack<T>::IsEmpty() const
{
	return top==NULL;
}
//ʵ�ֽ�ջ
template<class T>
bool LinkStack<T>::Push(const T& x)
{
	LinkNode<T> *p=new LinkNode<T>;
	if (p==NULL)
		return false;
	else
	{
		p->data=x;				//ΪԪ�ظ�ֵ
		p->next=top;			//���½ڵ����ջ��
		top=p;					//topָ��ջ��
		size++;
		return true;			
	}
}
//ʵ����ջ��Ԫ��
template<class T>
bool LinkStack<T>::Top(T& x)
{
	if (IsEmpty())
		return false;
	else
	{
		x=top->data;
		return true;
	}
}
//ʵ�ֳ�ջ
template<class T>
bool LinkStack<T>::Pop(T& x)
{
	LinkNode<T> *p;
	if (IsEmpty())
		return false;
	else
	{
		x=top->data;			//ɾ��Ԫ�ص�ֵ����x��
		p=top;					//�õ���ɾ���ڵ��ָ��
		top=top->next;			//topָ���µ�ջ��
		delete p;				//Ԫ�س�ջ
		size--;
		return 0;
	}
}
//ʵ������ջ�����
template<class T>
void LinkStack<T>::OutPut(ostream& out) const
{
	LinkNode<T> *p;
	p=top;
	for(int i=0;i<size;i++)
	{	
		out<<p->data;
		p=p->next;
	}
}
//���ز��������<<
template<class T>
ostream& operator<<(ostream& out,const LinkStack<T>& x)
{
	x.OutPut(out);
	return out;
}
#endif