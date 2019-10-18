#ifndef LINKSTRING
#define LINKSTRING
/*存储结点类*/
class StrNode                
{
	friend class LinkString;			//将链接串声明为结点类的友类
public:
	StrNode()//构造函数
	{
		next=NULL;
	}
private:
	
	char data;				//存放字符
	StrNode *next;		//指向下一个字符
};
/*链接串类*/
class LinkString
{
public:
	LinkString();							//构造函数，创建空串
	LinkString(const char *str);			//由字符串常量str创建串的构造函数
	LinkString(const LinkString& str);			//拷贝构造函数
	~LinkString();							//析构函数
	bool IsEmpty() const;				
	int Length() const;	
	void Delete();							//置空串
	void StrCat(const LinkString& str);		//将串t连接到串后形成新串
	bool SubStr(int pos,int len,LinkString &sub);
					//求从第pos个字符起长度为len的子串放到sub中
	bool operator==(const LinkString& str);	//判断串是否与str相等
	int index(const LinkString& str);
		//如果str是的子串，返回它在串中第一次出现的位置，不是子串则返回0
	void OutPut(ostream& out) const;			//输出字符串	
private:
	StrNode *head;			//指向链接串第一个头结点的指针
	int length;				//串的长度
};
//实现创建空串的构造函数
LinkString::LinkString()
{
	head=new StrNode();		//创建头结点
	length=0;
}
//实现构造函数
LinkString::LinkString(const char* str)
{
	StrNode *p,*q;
	int i=0;
	head=new StrNode();		//创建头结点
	p=head;
	while(str[i])
	{
		q=new StrNode();		//q指向新结点
		q->data=str[i];			//向数据域赋值
		p->next=q;			//新结点入链
		p=q;					//p指向最后一个节点
		i++;
	}
	length=i;					//设置链的长度
}
//实现拷贝构造函数
LinkString::LinkString(const LinkString& str)
{
	StrNode *p,*q,*w;
	int i;
	head=new StrNode(); 		//创建头结点
	p=head;	
	w=str.head->next;			//指向str字符串的第一个字符
	for (i=0;i<str.length;i++)
	{
		q=new StrNode();		//q指向新结点
		q->data=w->data;		//赋值
		p->next=q;			//新结点入链
		p=q;					//p指向最后一个节点
		w=w->next;			
	}
	length=i;
}
//实现析构函数
LinkString::~LinkString()
{
	StrNode *p,*q;
	p=head->next;
	for(int i=0;i<length;i++)
	{
		q=p;				//指向待删除的结点
		p=p->next;		//指向下一结点
		delete q;			//删除结点
	}
}
//实现判断是否为空串
bool LinkString::IsEmpty() const
{
	return length==0;
}
//实现求串的长度
int LinkString::Length() const
{
	return length;
}
//实现置空串函数
void LinkString::Delete()
{
	StrNode *p,*q;
	p=head->next;
	head->next=NULL;
	for(int i=0;i<length;i++)
	{
		q=p;				//指向待删除的结点	
		p=p->next;		//y指向下一结点
		delete q;			//删除结点
	}
	length=0;
}
//实现将串t连接到串后形成新串
void LinkString::StrCat(const LinkString& str)
{
	StrNode *p,*q,*w;
	p=head;	
	for(int i=0;i<length;i++)
		p=p->next;			//p指向最后一个结点
	w=str.head->next;			//指向str字符串的第一个字符
	for (int i=0;i<str.length;i++)
	{
		q=new StrNode();		//q指向新结点
		q->data=w->data;		//赋值
		p->next=q;			//新结点入链
		p=q;					//p指向最后一个节点
		w=w->next;
	}
	length=length+str.length;
	
}
//实现求从第pos个字符起长度为len的子串
bool LinkString::SubStr(int pos,int len,LinkString &sub)
{
	StrNode *p,*q,*w;
	if (pos<1||pos>length||len<0||len>(length-pos+1)) //参数非法
		return false;
	w=head;
	for (int i=0;i<pos;i++)		//w指向待赋值的第一个结点
		w=w->next;				
	p=sub.head;
	if(!sub.IsEmpty())			//sub不是空串则置成空串
		sub.Delete();
	for (int i=0; i<len; i++)		//逐个字符复制得到子串
	{
		q=new StrNode();		//q指向新结点
		q->data=w->data;		//赋值
		p->next=q;			//新结点入链
		p=q;					//p指向最后一个节点
		w=w->next;
	}
	sub.length=len;
	return true;
}
//实现判断串是否与str相等
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
//如果str是当前串的子串，返回它在串中第一次出现的位置，不是子串则返回0
int LinkString::index(const LinkString& str)
{
	LinkString sub;						//创建一个空串
	for (int i=1;i<=length-str.length+1;i++)		//扫描可能存在子串的区域
	{
		if(!SubStr(i,str.length,sub))			//取长度与str的长度一致的子串
			return 0;						//主串中不存在与str的长度一致的子串
		if(sub==str)return i;					//找到子串，返回子串在主串中的位置
	}
	return 0;
}
//实现顺序串的输出
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
//重载插入运算符<<
ostream& operator<<(ostream& out,const LinkString& x)
{
	x.OutPut(out);
	return out;
}
#endif