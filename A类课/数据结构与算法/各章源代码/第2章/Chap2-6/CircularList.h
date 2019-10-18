#ifndef CIRCULARLIST
#define CIRCULARLIST
//存储节点类
template<class T>
class LinkNode                //节点类
{
	template<class T>
	friend class CircularList;
	public:
		LinkNode()//构造函数
		{
			next=NULL;
		}
	private:
		
		T data;
		LinkNode<T> *next;
	//friend CircularList<T>;
};
//单向链表类
template<class T>
class CircularList
{
	public:
		template<class T>
		friend class LinkNode;
		CircularList();		//构造函数
		~CircularList();		//析构函数
		CircularList<T>& Insert(int n,const T& x);
		bool IsEmpty() const;		
		int GetLength() const;		
		bool GetData(int n,T& x);
		bool ModifyData(int n,const T& x);
		int Find(const T& x);
		CircularList<T>& DeleteByIndex(int n, T& x);
		CircularList<T>& DeleteByKey(const T& x,T& y);
		void Traverse(int index);
		void OutPut(ostream& out);
	private:
		LinkNode<T> *head;//指向链表的第一个头节点的指针
};

//构造函数的实现
template <class T>
CircularList<T>::CircularList()
{	//创建空单向链表
	head=new LinkNode<T>();//创建头节点
	head->next=head;
}
//析构函数的实现
template <class T>
CircularList<T>::~CircularList()
{	//空单向链表
	T x;
	int len=GetLength();
	for (int i=len;i>=1;i--)
		DeleteByIndex(i,x);						//释放所有节点
}

//实现插入新数据元素
template<class T>
CircularList<T>& CircularList<T>::Insert(int n,const T& x)
{
	LinkNode<T> *p=head;					//p指向头节点 
	LinkNode<T> *newNode=new LinkNode<T>;	//创建待插入的新节点
	newNode->data =x;
	int len=GetLength();
	if ( n<1 || n>len+1 )					//插入新元素的位置错误
		cout<<"元素下标越界，添加元素失败";
	else
	{
		for( int i=1;i<n;i++)  
			p=p->next;					//将p移动到第n-1个节点
		newNode->next=p->next;			//在n处插入新节点
		p->next =newNode;
	}
	return *this;
}
//实现判断是否为空表
template<class T>
bool CircularList<T>::IsEmpty() const
{
	return head->next==head;
}
//实现求当前表的长度
template<class T>
int CircularList<T>::GetLength() const
{
	int length=0;
	LinkNode<T> *p=head->next;
	while(p!=head)
	{
		length++;
		p=p->next;
	}
	return length;
}
//实现按位置取元素
template<class T>
bool  CircularList<T>::GetData(int n,T& x)
{
	LinkNode<T> *p=head->next;
	int index=1;
	if (n<0||n>GetLength()) 
		return false;
	while (p!=head && index<n)
	{
		index++;
		p=p->next;
	}
	if (p==head)
		return false;
	else
	{
		x=p->data; 
		return true;
	};
}
//实现按位置修改元素
template<class T>
bool  CircularList<T>::ModifyData(int n,const T& x)
{
	LinkNode<T> *p=head->next;
	int index=1;
	if (n<0||n>GetLength()) 
		return false;
	while (p!=head && index<n)
	{
		index++;
		p=p->next;
	}
	if (p==head)
		return false;
	else
	{
		p->data=x; 
		return true;
	};
}
//实现按关键字查找
template<class T>
int CircularList<T>::Find(const T& x)
{
	LinkNode<T> * p=head->next;
	int index=1;
	while (p!=head && p->data !=x )
	{
		p=p->next  ;
		index++;
	}
	if(p!=NULL)
		return index;
	else
		return 0;
}
//实现按位置删除
template<class T>
CircularList<T>& CircularList<T>::DeleteByIndex(int n, T& x)
{
	if (GetData(n,x))//判断是否有此元素，若果存在，则将该元素值放入x中，并返回true
	{
		LinkNode<T> *p=head;//p指向第1个节点
		LinkNode<T> *q=head;//q指向第1个节点
		                //删除中间或最后的节点
		for (int i=1;i<n;i++)
				p=p->next;   //将p指针移动到第n-1个节点
		q=p->next;       //q指向待删除的第n个节点
		p->next =q->next; //逻辑删除第n个节点
		delete q;//物理删除该节点
	}
	else						//没有第n个节点，删除失败
		cout<<"元素下标越界，删除失败\n";
	return *this;
}
//实现按关键字删除
template<class T>
CircularList<T>& CircularList<T>::DeleteByKey(const T& x,T& y)
{
	int index=Find(x);//得到要删除元素的位置
	if (index!=0)
		return DeleteByIndex(index, y);
	else
	{
		cout<<"没有此元素，删除失败\n";
		return *this;
	}
}
//实现单向链表的输出
template<class T>
void CircularList<T>:: OutPut(ostream& out) 
{
	LinkNode<T>* p=head->next;
	while(p!=head)
	{
		out<<p->data <<endl;
		p=p->next;
	}
}
//重载插入运算符<<
template<class T>
ostream& operator<<(ostream& out, CircularList<T>& x)
{
	x.OutPut(out);
	return out;
}

//遍历循环链表<<
template<class T>
void CircularList<T>::Traverse(int i)
{	
	LinkNode<T> *p=head;
	int j;
	for (j=0;j<i;j++)
		p=p->next;          //将指针指向第i个元素
	for (j=1;j<=GetLength();j++)
	{
		cout<<p->data;
		if (p->next!=head)
			p=p->next;
		else
			p=p->next->next;
	}
}
#endif