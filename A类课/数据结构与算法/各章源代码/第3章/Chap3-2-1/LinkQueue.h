#ifndef LINKQUEUE
#define LINKQUEUE
//�洢�����
template<class T>
class LinkNode    //�����
{
	template<class T>
	friend class LinkQueue;//�����Ӷ���������Ϊ����
	public:
		LinkNode()//���캯��
		{
			next=NULL;
		}
	private:
		T data;				//���Ԫ��
		LinkNode<T> *next;  //ָ����һ������ָ��
};
//���Ӷ�����
template<class T>
class LinkQueue
{
public:
			LinkQueue();					//�����ն���
			~LinkQueue();					//ɾ������
			bool IsEmpty();	//�ж϶����Ƿ�Ϊ�գ��շ���true���ǿշ���false
			bool Insert(const T& x);		//��ӣ��ڶ���β������Ԫ��x
			bool GetElement(T& x);			//���ͷԪ�ص�ֵ����x��
			bool Delete(T& x);
						//���ӣ��Ӷ�ͷɾ��һ��Ԫ�أ�������Ԫ�ص�ֵ����x��
			void OutPut(ostream& out)const;	//�������
private:
		int size;							//����ʵ��Ԫ�ظ���
		LinkNode<T>* front,*rear;			//���еĶ�ͷ�Ͷ�βָ��
};
//ʵ�ֹ��캯��
template<class T>
LinkQueue<T>::LinkQueue()
{
	front=NULL;
	rear=NULL;
	size=0; 
}
//ʵ����������
template<class T>
LinkQueue<T>::~LinkQueue()
{
	T x;
	while(front!=NULL)  //���зǿ���Ԫ�����γ���
		Delete(x);
}
//ʵ���ж�ջ�Ƿ�Ϊ��
template<class T>
bool LinkQueue<T>::IsEmpty()
{
	return size==0;
}
//ʵ�����
template<class T>
bool LinkQueue<T>::Insert(const T& x)
{
	LinkNode<T> *p=new LinkNode<T>;
    if (p==NULL)
		return false;
	else
	{
		p->data=x;			//ΪԪ�ظ�ֵ
		//���½ڵ�����β
		if (front==NULL)		//����ǰ�ǿն���	
		{
			rear=p;
			front=p;
		}
		else
		{
			rear->next=p;		//�����½��
			rear=p;				//ָ���¶�β
		}
		size++;
		return true;			
	}
}
//ʵ�����ͷԪ��
template<class T>
bool LinkQueue<T>::GetElement(T& x)
{
	if (IsEmpty())
		return false;
	else
	{
		x=front->data;
		return true;
	}
}
//ʵ�ֳ���
template<class T>
bool LinkQueue<T>::Delete(T& x)
{
	LinkNode<T> *p;
	if (IsEmpty())
		return false;
	else
	{
		p=front;
		x=front->data;
		front=front->next;
		delete p;		//ɾ����ͷ�ڵ�
		size--;
		return true;
	}
}
//ʵ�����Ӷ��е����
template<class T>
void LinkQueue<T>:: OutPut(ostream& out) const
{	
	LinkNode<T> *p;
	p=front;
	for(int i=0;i<size;i++)
	{	
		out<<p->data<<endl;
		p=p->next;
	}
}
//���ز��������<<
template<class T>
ostream& operator<<(ostream& out,const LinkQueue<T>& x)
{
	x.OutPut(out);
	return out;
}
#endif