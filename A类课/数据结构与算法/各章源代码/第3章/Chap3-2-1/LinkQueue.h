#ifndef LINKQUEUE
#define LINKQUEUE
//存储结点类
template<class T>
class LinkNode    //结点类
{
	template<class T>
	friend class LinkQueue;//将链接队列类声明为友类
	public:
		LinkNode()//构造函数
		{
			next=NULL;
		}
	private:
		T data;				//结点元素
		LinkNode<T> *next;  //指向下一个结点的指针
};
//链接队列类
template<class T>
class LinkQueue
{
public:
			LinkQueue();					//创建空队列
			~LinkQueue();					//删除队列
			bool IsEmpty();	//判断队列是否为空，空返回true，非空返回false
			bool Insert(const T& x);		//入队，在队列尾部插入元素x
			bool GetElement(T& x);			//求队头元素的值放入x中
			bool Delete(T& x);
						//出队，从队头删除一个元素，并将该元素的值放入x中
			void OutPut(ostream& out)const;	//输出队列
private:
		int size;							//队列实际元素个数
		LinkNode<T>* front,*rear;			//队列的队头和队尾指针
};
//实现构造函数
template<class T>
LinkQueue<T>::LinkQueue()
{
	front=NULL;
	rear=NULL;
	size=0; 
}
//实现析构函数
template<class T>
LinkQueue<T>::~LinkQueue()
{
	T x;
	while(front!=NULL)  //队列非空则元素依次出队
		Delete(x);
}
//实现判断栈是否为空
template<class T>
bool LinkQueue<T>::IsEmpty()
{
	return size==0;
}
//实现入队
template<class T>
bool LinkQueue<T>::Insert(const T& x)
{
	LinkNode<T> *p=new LinkNode<T>;
    if (p==NULL)
		return false;
	else
	{
		p->data=x;			//为元素赋值
		//将新节点插入队尾
		if (front==NULL)		//插入前是空队列	
		{
			rear=p;
			front=p;
		}
		else
		{
			rear->next=p;		//插入新结点
			rear=p;				//指向新队尾
		}
		size++;
		return true;			
	}
}
//实现求队头元素
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
//实现出队
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
		delete p;		//删除队头节点
		size--;
		return true;
	}
}
//实现链接队列的输出
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
//重载插入运算符<<
template<class T>
ostream& operator<<(ostream& out,const LinkQueue<T>& x)
{
	x.OutPut(out);
	return out;
}
#endif