#ifndef LINKLIST
#define LINKLIST
//�洢�����
template<class T>
class LinkNode    //�����
{
	template<class T>
	friend class LinkList; //����ʽ��������Ϊ����
	public:
		LinkNode()//���캯��
		{
			next=NULL;
		}
	private:
		T data;				//���Ԫ��
		LinkNode<T> *next;  //ָ����һ������ָ��
};
//����������
template<class T>
class LinkList
{
	public:
		LinkList();		//���캯��
		~LinkList();		//��������
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
		LinkNode<T> *head;//ָ������ĵ�һ��ͷ����ָ��
};
//���캯����ʵ��
template <class T>
LinkList<T>::LinkList()
{	//�����յ�������
	head=new LinkNode<T>();//����ͷ���
}
//����������ʵ��
template <class T>
LinkList<T>::~LinkList()
{	//�յ�������
	T x;
	int len=GetLength();
	for (int i=len;i>=1;i--)
		DeleteByIndex(i,x);					//�ͷ����н��
}
//ʵ�ֲ���������Ԫ��
template<class T>
LinkList<T>& LinkList<T>::Insert(int k,const T& x)
{
	LinkNode<T> *p=head;						//pָ��ͷ���
	LinkNode<T> *newNode=new LinkNode<T>;	//������������½��
	newNode->data =x;
	int len=GetLength();
	if ( k<1 || k>len+1 )							//������Ԫ�ص�λ�ô���
		cout<<"Ԫ���±�Խ�磬���Ԫ��ʧ��";
	else
	{
		for( int i=1;i<k;i++)  
			p=p->next;						//��p�ƶ�����n-1�����
		newNode->next=p->next;				//��n�������½��
		p->next =newNode;
	}
	return *this;
}
//ʵ���ж��Ƿ�Ϊ�ձ�
template<class T>
bool LinkList<T>::IsEmpty() const
{
	return head->next==NULL;
}
//ʵ����ǰ��ĳ���
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
//ʵ�ְ�λ��ȡԪ��
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
//ʵ�ְ�λ���޸�Ԫ��
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
//ʵ�ְ��ؼ��ֲ���
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
//ʵ�ְ�λ��ɾ��
template<class T>
LinkList<T>& LinkList<T>::DeleteByIndex(int k, T& x)
{
	if (GetData(k,x))
			//�ж��Ƿ��д�Ԫ�أ��������ڣ��򽫸�Ԫ��ֵ����x�У�������true
	{
		LinkNode<T> *p=head;			//pָ��ͷ���
		LinkNode<T> *q=NULL;		//qָ��յ�ַ
		//ɾ���м�����Ľ��
		for (int i=1;i<k;i++)
				p=p->next;			//��pָ���ƶ�����k-1�����
		q=p->next;					//qָ���ɾ���ĵ�k�����
		p->next =q->next;				//����k�������������Ƴ�
		delete q;						//����ɾ���ý��
	}
	else								//û�е�k����㣬ɾ��ʧ��
		cout<<"Ԫ���±�Խ�磬ɾ��ʧ��\n";
	return *this;
}
//ʵ�ְ��ؼ���ɾ��
template<class T>
LinkList<T>& LinkList<T>::DeleteByKey(const T& x,T& y)
{
	int index=Find(x);					//�õ�Ҫɾ��Ԫ�ص�λ��
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
void LinkList<T>:: OutPut(ostream& out) 
{
	LinkNode<T>* p=head->next;
	while(p!=NULL)
	{
		out<<p->data <<endl;
		p=p->next;
	}
}
//���ز��������<<
template<class T>
ostream& operator<<(ostream& out, LinkList<T>& x)
{
	x.OutPut(out);
	return out;
}
#endif
