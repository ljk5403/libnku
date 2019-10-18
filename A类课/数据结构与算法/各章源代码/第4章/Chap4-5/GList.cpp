
// GList.cpp
#include "GList.h"
#include <cassert>
#include <stdexcept>
#include <iostream>
using namespace std;
 
//实现结点元素类构造函数
NodeElement::NodeElement() 		//缺省为头结点
{
	m_tag=HEAD;
	m_data.ref = 1;			//
}			
NodeElement::NodeElement( char chdata)
{
	m_tag=CH;
	m_data.chardata = chdata;
}
NodeElement::NodeElement( GLNode* link)
{
	m_tag=LIST;
	m_data.hlink = link;
} 
//实现结点元素类的接口
void NodeElement::SetTypeID(EleCate ID) 		//这是一个保护成员函数
{
	m_tag = ID;	
} 
EleCate NodeElement::GetTypeID() const
{
	return m_tag;	
} 
void NodeElement::SetRef(int rf)
{
	SetTypeID(HEAD);
	m_data.ref = rf;
} 
int NodeElement::GetRef() const
{
	assert( m_tag == HEAD);
	return m_data.ref;	
}
void NodeElement::SetCharInfo(char chdata)
{
	SetTypeID(CH);
	m_data.chardata = chdata;
}
char NodeElement::GetCharInfo() const
{
	assert( m_tag == CH);
	return m_data.chardata;	
}
void NodeElement::SetList(GLNode* link)
{
	SetTypeID(LIST);
	m_data.hlink = link;
}
GLNode* NodeElement::GetList() const
{
	assert( m_tag == LIST);
	return m_data.hlink;	
}
void  NodeElement::SetElement( const NodeElement& node)
{
	switch(node.m_tag)
	{
		case HEAD :
			this->SetRef(node.m_data.ref);
			break;
		case CH :
			this->SetCharInfo(node.m_data.chardata);
			break;
		case LIST :
			this->SetList(node.m_data.hlink);	
			break;	
	}
}
NodeElement& NodeElement::operator=( const NodeElement& ne)
{
	m_tag = ne.m_tag;
	m_data = ne.m_data;
	return *this;
}
bool  NodeElement::operator==(const NodeElement& ne)
{
	//针对不同的数据类型进行比较
	switch(ne.m_tag)
	{
		case HEAD :
			if(m_tag == HEAD && m_data.ref == ne.GetRef())
				return true;
			else 
				return false;
			break;
		case CH :
			if(m_tag == CH && m_data.chardata == ne.GetCharInfo())
				return true;
			else 
				return false;
			break;
		case LIST :
			if(m_tag == LIST && m_data.hlink == ne.GetList())
				return true;
			else 
				return false;	
			break;
		default:
			return false;
	}
}
//实现结点类
//实现构造函数
GLNode::GLNode()	//默认构造定义了一个表头结点
{ 
	m_next=NULL;
}		
GLNode::GLNode( char chdata) : m_NodeEle(chdata)
{ 
	m_next=NULL;
}
GLNode::GLNode( GLNode* link) : m_NodeEle(link)
{ 
	m_next=NULL;
}
//实现接口
const NodeElement& GLNode::GetInfo() const
{
	return this->m_NodeEle;
}
void GLNode::SetInfo(const NodeElement& node)
{
	m_NodeEle.SetElement(node);
}
//实现广义表类
//实现构造函数
GList::GList() 
{
	m_phead  = new GLNode;		//定义一个表头结点
	assert( m_phead );
}

//实现析构函数
GList::~GList() 
{
	remove(m_phead);
}
//实现接口
NodeElement& GList::Head()		//表头元素的引用，可以修改元素内部值
{
	return m_phead->m_NodeEle;	
}
//这里返回的是一个表尾的拷贝
//函数中调用了GList& GList::Copy(const GList& list)
//
GList GList::Tail()
{
	
	GList glist;
	if(m_phead->m_next) 
	{
		glist.m_phead->m_next = this->copy(m_phead->m_next->m_next);	//拷贝尾表中所有的结点
	}
	return glist;		
}
NodeElement& GList::First()		//表中第一个元素的引用，可以修改元素内部值
{
	if(!m_phead->m_next)
	{
		throw out_of_range("不存在第一个元素");
	}
	return m_phead->m_next->m_NodeEle;	
}
GList& GList::Push( const NodeElement& x)//将x值作为第一个结点的元素值插入到广义表中
{
	GLNode* pnode = new GLNode;
	assert(pnode);
	pnode->SetInfo(x);
	pnode->m_next = m_phead->m_next;
	m_phead->m_next = pnode;	
	return *this;
}
GList& GList::SetHead( const NodeElement& x)//将第一个元素值设置为x
{
	GLNode* pnode = m_phead->m_next;
	if(!pnode)			//无元素表,则生成第一个元素
	{
		pnode = new GLNode;
		assert(pnode);
		m_phead->m_next = pnode;	
		pnode->m_next = NULL;
	}
	pnode->SetInfo(x);	
	return *this;
}
GList& GList::SetNext( const GLNode* node, const NodeElement& x)//将node结点后一个结点的元素值设置为x
{
	if(node && node->m_next)
	{
		node->m_next->m_NodeEle.SetElement(x);		//设定结点元素值为x		
	}
	return *this;
}
GList& GList::SetTail( GList& list)//将list作为新表的表尾,list 被删除
{
	GLNode* tmp;
	tmp = m_phead->m_next->m_next;
	m_phead->m_next->m_next = list.m_phead->m_next;
	delete list.m_phead;	
	list.m_phead = NULL;	//使list失去对原来表的控制，阻止其进行正常的析构操作
	this->remove(tmp);		//删除原表的表尾	
	return *this;
}
GList& GList::SetTail(const GList& list)//将list元素复制为表尾，list不发生变化
{
	GLNode* tmp;
	tmp = m_phead->m_next->m_next;
	m_phead->m_next->m_next = copy(list.m_phead->m_next);//递归复制
	this->remove(tmp);		//删除原表的表尾	
	return *this;	
}
GList& GList::Copy(const GList& list)//复制一个广义表
{
	remove(m_phead->m_next);
	m_phead->m_next = copy(list.m_phead->m_next);	
	return *this;
}
GLNode* GList::copy(const GLNode* nd)	//全模式递归复制广义表（包括对递归，共享表的识别复制）	
{
	GLNode* pnode = NULL;
	if(nd)
	{
		pnode = new GLNode;
		if(nd->GetInfo().GetTypeID() == LIST)		//结点中存储的是子表
		{
			pnode->m_NodeEle.SetList( copy(nd->m_NodeEle.GetList()));
		}	
		else
		{
			pnode->m_NodeEle.SetElement(nd->m_NodeEle);	
		}
		pnode->m_next = copy(nd->m_next);
	}
	return pnode;
}
int GList::Depth() const	//递归表的深度	
{
	return depth(m_phead);	
}
int GList::depth(const GLNode* list )  const //递归计算表的深度	
{
	if(!list->m_next) return 1;	//空表深度为1
	GLNode *tmp = list->m_next;
	int m = 0;
	while(tmp)
	{
		if(tmp->m_NodeEle.GetTypeID() == LIST)
		{
			int n = depth(tmp->m_NodeEle.GetList());
			if(m<n) m = n;
		}
		tmp = tmp->m_next;	
	}
	return m+1;
}
bool GList::operator==(const GList& list) const	//判断两个表是否相等
{
	return IsEqual(m_phead, list.m_phead);	
}
bool GList::IsEqual(const GLNode* p, const GLNode* q) const//递归判断两个表是否相等函数
{
	if(!p->m_next && !q->m_next)
	{
		//p,q都索引的是空表
		return true;	
	}
	bool btest = false;
	if(p->m_next != NULL && q->m_next !=NULL 	
		&& p->m_next->m_NodeEle.GetTypeID() 
		== q->m_next->m_NodeEle.GetTypeID())
	{
		if(p->m_next->m_NodeEle.GetTypeID() == CH)
		{
			if(p->m_next->m_NodeEle.GetCharInfo() == q->m_next->m_NodeEle.GetCharInfo())
			{
				btest = true;
			}	
			else btest = false;	
		}
		//扫描到的是一个表头索引，进入子表进行索引
		else btest = IsEqual(p->m_next->m_NodeEle.GetList(), q->m_next->m_NodeEle.GetList());
		//结点中的元素是相等的，比较下面一个结点
		if(btest)  
			return IsEqual(p->m_next, q->m_next);
	}
	return false;
}
//广义表删除操作，同于析构函数调用
void GList::remove(GLNode* nd)	//必须是头指针
{
	if(nd)	
	{
		assert(nd->m_NodeEle.GetTypeID() == HEAD);
		nd->m_NodeEle.SetRef(nd->m_NodeEle.GetRef()-1);	//共享数量减一
		if(!nd->m_NodeEle.GetRef())
		{
			//表头已经不再作为任何子表
			GLNode* ptmp = nd;
			while(ptmp != 0)
			{
				nd = nd->m_next;
				if( nd && nd->m_NodeEle.GetTypeID() == LIST )
				{
					//该结点为子表索引,则递归删除子表
					remove(nd->m_NodeEle.GetList());	
				}
				delete ptmp;
				ptmp = nd;				
			}			
		}
	}
}
GList& GList::Delete(const NodeElement& x)//删除广义表中的所有的指定的元素
{
	delvalue(m_phead, x);
	return *this;
}
void GList::delvalue( GLNode* list, const NodeElement& x)//删除元素的递归函数
{
	//x必须是原子结点表示的类型
	assert(x.GetTypeID() == CH);	
	if(list->m_next != 0)
	{
		GLNode* ptmp = list->m_next;
		GLNode* q = list;
		while(ptmp)
		{
			if(ptmp->m_NodeEle == x)	//直接调用 NodeElement::operator==()
			{
				//如果是原子结点，则进行比较，相等则删除
				q->m_next = ptmp->m_next;
				delete ptmp;				
			}
			else if(ptmp->m_NodeEle.GetTypeID()==LIST)
			{
				//发现子表，对子表进行递归删除操作
				delvalue(ptmp->m_NodeEle.GetList(), x);
			}
			q = ptmp;
			ptmp = ptmp->m_next;						
		}
	}	
}
//由输入流新建一个表格
	//输入格式约定：
	//21,5,(2,3,(42,p,x,61,n,(x,f,s,6),25,x)),p,x#
	//其中字符可以相连，数字为整型数，#为输入流终结控制符，
	//要省略最外层表的括号
void GList::CreateList()//
{
	cout << " 请按下面的格式输入一个广义表： \n a,b,(c,d,(e,f,g,h,(i,j,k),l,m)),n# " << endl;
	//必须先删除原表
	remove(m_phead->m_next);
	m_phead->m_next = createlist(cin);	//参数是输入流	
}
GLNode* GList::createlist(istream& in)//对输入流进行处理，生成广仪表
{
	char ch;
	while(in.get(ch), ch !='#')
	{
		if(ch != ',')
		{
			if(ch == '(')	//ch为左括号，动作：生成一个原子结点，生成一个表头索引，递归扫描流
			{
				GLNode* nd = new GLNode;
				GLNode* lhead = new GLNode;
				nd->m_NodeEle.SetList(lhead);	//
				lhead->m_NodeEle.SetRef(1);
				lhead->m_next = createlist(in);	//递归生成子表
				nd->m_next = createlist(in);	//在生成子表完成后继续递归生成主干表
				return nd;
			}
			else if(ch == ')')
			{
				//ch为右括号，表递归结束，
				return 0; 
			}
			else //ch表示字符
			{
					GLNode* nd = new GLNode;
					nd->m_NodeEle.SetCharInfo(ch);
					nd->m_next = createlist(in);	//递归流
					return nd;				
			}
		}
	} 
	return 0;	//终结指针	
}
void GList::output(std::ostream& out,const GLNode* node) const //用于输出流的广义表递归提取函数
{
	if(!node)
	{
		return ;
	}
	switch(node->m_NodeEle.GetTypeID())
	{
		case HEAD:	//当前结点为头结点
		output(out,node->m_next);
		break;
		case CH:
		out << node->m_NodeEle.GetCharInfo();
		if(node->m_next)
		{
			out << ",";
		}
		output(out, node->m_next);		
		break;
		case LIST:
		out << "(";
		output(out, node->m_NodeEle.GetList());
		out <<")";
		if(node->m_next)
		{
			out << ",";
		}
		output(out, node->m_next);
		break;
	}
}
ostream& operator<<(std::ostream& out, const GList& list)//输出流输出表
{
	out << "这个广义表是: \n";
	list.output(out,list.m_phead);
	return out;
}