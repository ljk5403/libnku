#ifndef LINKSTRING
#define LINKSTRING
/*�洢�����*/
class StrNode                
{
	friend class LinkString;			//�����Ӵ�����Ϊ����������
public:
	StrNode()//���캯��
	{
		next=NULL;
	}
private:
	
	char data;				//����ַ�
	StrNode *next;		//ָ����һ���ַ�
};
/*���Ӵ���*/
class LinkString
{
public:
	LinkString();							//���캯���������մ�
	LinkString(const char *str);			//���ַ�������str�������Ĺ��캯��
	LinkString(const LinkString& str);			//�������캯��
	~LinkString();							//��������
	bool IsEmpty() const;				
	int Length() const;	
	void Delete();							//�ÿմ�
	void StrCat(const LinkString& str);		//����t���ӵ������γ��´�
	bool SubStr(int pos,int len,LinkString &sub);
					//��ӵ�pos���ַ��𳤶�Ϊlen���Ӵ��ŵ�sub��
	bool operator==(const LinkString& str);	//�жϴ��Ƿ���str���
	int index(const LinkString& str);
		//���str�ǵ��Ӵ����������ڴ��е�һ�γ��ֵ�λ�ã������Ӵ��򷵻�0
	void OutPut(ostream& out) const;			//����ַ���	
private:
	StrNode *head;			//ָ�����Ӵ���һ��ͷ����ָ��
	int length;				//���ĳ���
};
//ʵ�ִ����մ��Ĺ��캯��
LinkString::LinkString()
{
	head=new StrNode();		//����ͷ���
	length=0;
}
//ʵ�ֹ��캯��
LinkString::LinkString(const char* str)
{
	StrNode *p,*q;
	int i=0;
	head=new StrNode();		//����ͷ���
	p=head;
	while(str[i])
	{
		q=new StrNode();		//qָ���½��
		q->data=str[i];			//��������ֵ
		p->next=q;			//�½������
		p=q;					//pָ�����һ���ڵ�
		i++;
	}
	length=i;					//�������ĳ���
}
//ʵ�ֿ������캯��
LinkString::LinkString(const LinkString& str)
{
	StrNode *p,*q,*w;
	int i;
	head=new StrNode(); 		//����ͷ���
	p=head;	
	w=str.head->next;			//ָ��str�ַ����ĵ�һ���ַ�
	for (i=0;i<str.length;i++)
	{
		q=new StrNode();		//qָ���½��
		q->data=w->data;		//��ֵ
		p->next=q;			//�½������
		p=q;					//pָ�����һ���ڵ�
		w=w->next;			
	}
	length=i;
}
//ʵ����������
LinkString::~LinkString()
{
	StrNode *p,*q;
	p=head->next;
	for(int i=0;i<length;i++)
	{
		q=p;				//ָ���ɾ���Ľ��
		p=p->next;		//ָ����һ���
		delete q;			//ɾ�����
	}
}
//ʵ���ж��Ƿ�Ϊ�մ�
bool LinkString::IsEmpty() const
{
	return length==0;
}
//ʵ���󴮵ĳ���
int LinkString::Length() const
{
	return length;
}
//ʵ���ÿմ�����
void LinkString::Delete()
{
	StrNode *p,*q;
	p=head->next;
	head->next=NULL;
	for(int i=0;i<length;i++)
	{
		q=p;				//ָ���ɾ���Ľ��	
		p=p->next;		//yָ����һ���
		delete q;			//ɾ�����
	}
	length=0;
}
//ʵ�ֽ���t���ӵ������γ��´�
void LinkString::StrCat(const LinkString& str)
{
	StrNode *p,*q,*w;
	p=head;	
	for(int i=0;i<length;i++)
		p=p->next;			//pָ�����һ�����
	w=str.head->next;			//ָ��str�ַ����ĵ�һ���ַ�
	for (int i=0;i<str.length;i++)
	{
		q=new StrNode();		//qָ���½��
		q->data=w->data;		//��ֵ
		p->next=q;			//�½������
		p=q;					//pָ�����һ���ڵ�
		w=w->next;
	}
	length=length+str.length;
	
}
//ʵ����ӵ�pos���ַ��𳤶�Ϊlen���Ӵ�
bool LinkString::SubStr(int pos,int len,LinkString &sub)
{
	StrNode *p,*q,*w;
	if (pos<1||pos>length||len<0||len>(length-pos+1)) //�����Ƿ�
		return false;
	w=head;
	for (int i=0;i<pos;i++)		//wָ�����ֵ�ĵ�һ�����
		w=w->next;				
	p=sub.head;
	if(!sub.IsEmpty())			//sub���ǿմ����óɿմ�
		sub.Delete();
	for (int i=0; i<len; i++)		//����ַ����Ƶõ��Ӵ�
	{
		q=new StrNode();		//qָ���½��
		q->data=w->data;		//��ֵ
		p->next=q;			//�½������
		p=q;					//pָ�����һ���ڵ�
		w=w->next;
	}
	sub.length=len;
	return true;
}
//ʵ���жϴ��Ƿ���str���
bool LinkString::operator==(const LinkString& str)
{
	StrNode *p,*q;
	if(length!=str.length)
		return false;
	p=head->next;
	q=str.head->next;
	for(int i=0;i<length;i++)
	{
		if (p->data!=q->data)
			return false;
		p=p->next;
		q=q->next;
	}
	return true;
}
//���str�ǵ�ǰ�����Ӵ����������ڴ��е�һ�γ��ֵ�λ�ã������Ӵ��򷵻�0
int LinkString::index(const LinkString& str)
{
	LinkString sub;						//����һ���մ�
	for (int i=1;i<=length-str.length+1;i++)		//ɨ����ܴ����Ӵ�������
	{
		if(!SubStr(i,str.length,sub))			//ȡ������str�ĳ���һ�µ��Ӵ�
			return 0;						//�����в�������str�ĳ���һ�µ��Ӵ�
		if(sub==str)return i;					//�ҵ��Ӵ��������Ӵ��������е�λ��
	}
	return 0;
}
//ʵ��˳�򴮵����
void LinkString:: OutPut(ostream& out) const
{
	StrNode *p;
	p=head->next;
	for(int i=0;i<length;i++)
	{
		out<<p->data;
		p=p->next;
	}
	cout<<endl;
}
//���ز��������<<
ostream& operator<<(ostream& out,const LinkString& x)
{
	x.OutPut(out);
	return out;
}
#endif