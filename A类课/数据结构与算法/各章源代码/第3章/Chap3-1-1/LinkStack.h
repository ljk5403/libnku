#ifndef LINKSTACK
#define LINKSTACK
//存储结点类
template<class T>
class LinkNode    //结点类
{
	template<class T>
	friend class LinkStack;			//将链接栈类声明为友类
	public:
		LinkNode()//构造函数
		{
			next=NULL;
		}
	private:
		T data;					//结点元素
		LinkNode<T> *next;		//指向下一个结点的指针
};
//单向链接栈类
template<class T>
class LinkStack
{
	public:
		LinkStack ();				//构造函数，创建空栈
		~LinkStack();				//析构函数，删除栈
		bool IsEmpty() const;
								//判断栈是否为空，空返回true，非空返回false
		bool Push(const T& x); 
						//在栈顶插入元素x，插入成功返回true，不成功返回false
		bool Top(T& x);
						//求栈顶元素的值放入x中，成功返回true，失败返回false
		bool Pop(T& x);
						//从栈顶删除一个元素，并将该元素的值放入x中
		void OutPut(ostream& out) const;	// 将顺序栈放到输出流out中输出
	private:
		LinkNode<T> *top;			//指向链接链的栈顶结点的指针
		int size;					//栈中元素个数
};
//实现构造函数
template<class T>
LinkStack<T>::LinkStack()
{
	top=NULL;
	size=0;
}
//实现析构函数
template<class T>
LinkStack<T>::~LinkStack()
{
	T x;
	while(top!=NULL)		//栈非空则元素依次出栈
		Pop(x);
}
//实现判断栈是否为空
template<class T>
bool LinkStack<T>::IsEmpty() const
{
	return top==NULL;
}
//实现进栈
template<class T>
bool LinkStack<T>::Push(const T& x)
{
	LinkNode<T> *p=new LinkNode<T>;
	if (p==NULL)
		return false;
	else
	{
		p->data=x;				//为元素赋值
		p->next=top;			//将新节点插入栈顶
		top=p;					//top指向栈顶
		size++;
		return true;			
	}
}
//实现求栈顶元素
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
//实现出栈
template<class T>
bool LinkStack<T>::Pop(T& x)
{
	LinkNode<T> *p;
	if (IsEmpty())
		return false;
	else
	{
		x=top->data;			//删除元素的值放入x中
		p=top;					//得到待删除节点的指针
		top=top->next;			//top指向新的栈顶
		delete p;				//元素出栈
		size--;
		return 0;
	}
}
//实现链接栈的输出
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
//重载插入运算符<<
template<class T>
ostream& operator<<(ostream& out,const LinkStack<T>& x)
{
	x.OutPut(out);
	return out;
}
#endif