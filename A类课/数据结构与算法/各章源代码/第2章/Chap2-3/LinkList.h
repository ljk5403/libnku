#ifndef LINKLIST
#define LINKLIST
//存储结点类
template<class T>
class LinkNode    //结点类
{
	template<class T>
	friend class LinkList; //将链式表类声明为友类
	public:
		LinkNode()//构造函数
		{
			next=NULL;
		}
	private:
		T data;				//结点元素
		LinkNode<T> *next;  //指向下一个结点的指针
};
//单向链表类
template<class T>
class LinkList
{
	public:
		LinkList();		//构造函数
		~LinkList();		//析构函数
		LinkList<T>& Insert(int k,const T& x);
		bool IsEmpty() const;		
		int GetLength() const;		
		bool GetData(int k,T& x);
		bool ModifyData(int k,const T& x);
		int Find(const T& x);
		LinkList<T>& DeleteByIndex(int k, T& x);
		LinkList<T>& DeleteByKey(const T& x,T& y);
		void OutPut(ostream& out);
	private:
		LinkNode<T> *head;//指向链表的第一个头结点的指针
};
//构造函数的实现
template <class T>
LinkList<T>::LinkList()
{	//创建空单向链表
	head=new LinkNode<T>();//创建头结点
}
//析构函数的实现
template <class T>
LinkList<T>::~LinkList()
{	//空单向链表
	T x;
	int len=GetLength();
	for (int i=len;i>=1;i--)
		DeleteByIndex(i,x);					//释放所有结点
}
//实现插入新数据元素
template<class T>
LinkList<T>& LinkList<T>::Insert(int k,const T& x)
{
	LinkNode<T> *p=head;						//p指向头结点
	LinkNode<T> *newNode=new LinkNode<T>;	//创建待插入的新结点
	newNode->data =x;
	int len=GetLength();
	if ( k<1 || k>len+1 )							//插入新元素的位置错误
		cout<<"元素下标越界，添加元素失败";
	else
	{
		for( int i=1;i<k;i++)  
			p=p->next;						//将p移动到第n-1个结点
		newNode->next=p->next;				//在n处插入新结点
		p->next =newNode;
	}
	return *this;
}
//实现判断是否为空表
template<class T>
bool LinkList<T>::IsEmpty() const
{
	return head->next==NULL;
}
//实现求当前表的长度
template<class T>
int LinkList<T>::GetLength() const
{
	int length=0;
	LinkNode<T> *p=head->next;
	while(p)
	{
		length++;
		p=p->next;
	}
	return length;
}
//实现按位置取元素
template<class T>
bool  LinkList<T>::GetData(int k,T& x)
{
	LinkNode<T> *p=head->next;
	int index=1;
	if (k<0||k>GetLength()) 
		return false;
	while (p!=NULL && index<k)
	{
		index++;
		p=p->next;
	}
	if (p==NULL)
		return false;
	else
	{
		x=p->data; 
		return true;
	};
}
//实现按位置修改元素
template<class T>
bool LinkList<T>::ModifyData(int k,const T& x)
{
	LinkNode<T> *p=head->next;
	int index=1;
	if (k<0||k>GetLength()) 
		return false;
	while (p!=NULL && index<k)
	{
		index++;
		p=p->next;
	}
	if (p==NULL)
		return false;
	else
	{
		p->data=x; 
		return true;
	};
}
//实现按关键字查找
template<class T>
int LinkList<T>::Find(const T& x)
{
	LinkNode<T> * p=head->next;
	int index=1;
	while (p!=NULL && p->data !=x )
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
LinkList<T>& LinkList<T>::DeleteByIndex(int k, T& x)
{
	if (GetData(k,x))
			//判断是否有此元素，若果存在，则将该元素值放入x中，并返回true
	{
		LinkNode<T> *p=head;			//p指向头结点
		LinkNode<T> *q=NULL;		//q指向空地址
		//删除中间或最后的结点
		for (int i=1;i<k;i++)
				p=p->next;			//将p指针移动到第k-1个结点
		q=p->next;					//q指向待删除的第k个结点
		p->next =q->next;				//将第k个结点从链表中移出
		delete q;						//物理删除该结点
	}
	else								//没有第k个结点，删除失败
		cout<<"元素下标越界，删除失败\n";
	return *this;
}
//实现按关键字删除
template<class T>
LinkList<T>& LinkList<T>::DeleteByKey(const T& x,T& y)
{
	int index=Find(x);					//得到要删除元素的位置
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
void LinkList<T>:: OutPut(ostream& out) 
{
	LinkNode<T>* p=head->next;
	while(p!=NULL)
	{
		out<<p->data <<endl;
		p=p->next;
	}
}
//重载插入运算符<<
template<class T>
ostream& operator<<(ostream& out, LinkList<T>& x)
{
	x.OutPut(out);
	return out;
}
#endif
