#ifndef CIRCULARLIST
#define CIRCULARLIST
//�洢�ڵ���
template<class T>
class LinkNode                //�ڵ���
{
	template<class T>
	friend class CircularList;
	public:
		LinkNode()//���캯��
		{
			next=NULL;
		}
	private:
		
		T data;
		LinkNode<T> *next;
	//friend CircularList<T>;
};
//����������
template<class T>
class CircularList
{
	public:
		template<class T>
		friend class LinkNode;
		CircularList();		//���캯��
		~CircularList();		//��������
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
		LinkNode<T> *head;//ָ������ĵ�һ��ͷ�ڵ��ָ��
};

//���캯����ʵ��
template <class T>
CircularList<T>::CircularList()
{	//�����յ�������
	head=new LinkNode<T>();//����ͷ�ڵ�
	head->next=head;
}
//����������ʵ��
template <class T>
CircularList<T>::~CircularList()
{	//�յ�������
	T x;
	int len=GetLength();
	for (int i=len;i>=1;i--)
		DeleteByIndex(i,x);						//�ͷ����нڵ�
}

//ʵ�ֲ���������Ԫ��
template<class T>
CircularList<T>& CircularList<T>::Insert(int n,const T& x)
{
	LinkNode<T> *p=head;					//pָ��ͷ�ڵ� 
	LinkNode<T> *newNode=new LinkNode<T>;	//������������½ڵ�
	newNode->data =x;
	int len=GetLength();
	if ( n<1 || n>len+1 )					//������Ԫ�ص�λ�ô���
		cout<<"Ԫ���±�Խ�磬���Ԫ��ʧ��";
	else
	{
		for( int i=1;i<n;i++)  
			p=p->next;					//��p�ƶ�����n-1���ڵ�
		newNode->next=p->next;			//��n�������½ڵ�
		p->next =newNode;
	}
	return *this;
}
//ʵ���ж��Ƿ�Ϊ�ձ�
template<class T>
bool CircularList<T>::IsEmpty() const
{
	return head->next==head;
}
//ʵ����ǰ��ĳ���
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
//ʵ�ְ�λ��ȡԪ��
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
//ʵ�ְ�λ���޸�Ԫ��
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
//ʵ�ְ��ؼ��ֲ���
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
//ʵ�ְ�λ��ɾ��
template<class T>
CircularList<T>& CircularList<T>::DeleteByIndex(int n, T& x)
{
	if (GetData(n,x))//�ж��Ƿ��д�Ԫ�أ��������ڣ��򽫸�Ԫ��ֵ����x�У�������true
	{
		LinkNode<T> *p=head;//pָ���1���ڵ�
		LinkNode<T> *q=head;//qָ���1���ڵ�
		                //ɾ���м�����Ľڵ�
		for (int i=1;i<n;i++)
				p=p->next;   //��pָ���ƶ�����n-1���ڵ�
		q=p->next;       //qָ���ɾ���ĵ�n���ڵ�
		p->next =q->next; //�߼�ɾ����n���ڵ�
		delete q;//����ɾ���ýڵ�
	}
	else						//û�е�n���ڵ㣬ɾ��ʧ��
		cout<<"Ԫ���±�Խ�磬ɾ��ʧ��\n";
	return *this;
}
//ʵ�ְ��ؼ���ɾ��
template<class T>
CircularList<T>& CircularList<T>::DeleteByKey(const T& x,T& y)
{
	int index=Find(x);//�õ�Ҫɾ��Ԫ�ص�λ��
	if (index!=0)
		return DeleteByIndex(index, y);
	else
	{
		cout<<"û�д�Ԫ�أ�ɾ��ʧ��\n";
		return *this;
	}
}
//ʵ�ֵ�����������
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
//���ز��������<<
template<class T>
ostream& operator<<(ostream& out, CircularList<T>& x)
{
	x.OutPut(out);
	return out;
}

//����ѭ������<<
template<class T>
void CircularList<T>::Traverse(int i)
{	
	LinkNode<T> *p=head;
	int j;
	for (j=0;j<i;j++)
		p=p->next;          //��ָ��ָ���i��Ԫ��
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