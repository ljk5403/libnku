
// GList.cpp
#include "GList.h"
#include <cassert>
#include <stdexcept>
#include <iostream>
using namespace std;
 
//ʵ�ֽ��Ԫ���๹�캯��
NodeElement::NodeElement() 		//ȱʡΪͷ���
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
//ʵ�ֽ��Ԫ����Ľӿ�
void NodeElement::SetTypeID(EleCate ID) 		//����һ��������Ա����
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
	//��Բ�ͬ���������ͽ��бȽ�
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
//ʵ�ֽ����
//ʵ�ֹ��캯��
GLNode::GLNode()	//Ĭ�Ϲ��춨����һ����ͷ���
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
//ʵ�ֽӿ�
const NodeElement& GLNode::GetInfo() const
{
	return this->m_NodeEle;
}
void GLNode::SetInfo(const NodeElement& node)
{
	m_NodeEle.SetElement(node);
}
//ʵ�ֹ������
//ʵ�ֹ��캯��
GList::GList() 
{
	m_phead  = new GLNode;		//����һ����ͷ���
	assert( m_phead );
}

//ʵ����������
GList::~GList() 
{
	remove(m_phead);
}
//ʵ�ֽӿ�
NodeElement& GList::Head()		//��ͷԪ�ص����ã������޸�Ԫ���ڲ�ֵ
{
	return m_phead->m_NodeEle;	
}
//���ﷵ�ص���һ����β�Ŀ���
//�����е�����GList& GList::Copy(const GList& list)
//
GList GList::Tail()
{
	
	GList glist;
	if(m_phead->m_next) 
	{
		glist.m_phead->m_next = this->copy(m_phead->m_next->m_next);	//����β�������еĽ��
	}
	return glist;		
}
NodeElement& GList::First()		//���е�һ��Ԫ�ص����ã������޸�Ԫ���ڲ�ֵ
{
	if(!m_phead->m_next)
	{
		throw out_of_range("�����ڵ�һ��Ԫ��");
	}
	return m_phead->m_next->m_NodeEle;	
}
GList& GList::Push( const NodeElement& x)//��xֵ��Ϊ��һ������Ԫ��ֵ���뵽�������
{
	GLNode* pnode = new GLNode;
	assert(pnode);
	pnode->SetInfo(x);
	pnode->m_next = m_phead->m_next;
	m_phead->m_next = pnode;	
	return *this;
}
GList& GList::SetHead( const NodeElement& x)//����һ��Ԫ��ֵ����Ϊx
{
	GLNode* pnode = m_phead->m_next;
	if(!pnode)			//��Ԫ�ر�,�����ɵ�һ��Ԫ��
	{
		pnode = new GLNode;
		assert(pnode);
		m_phead->m_next = pnode;	
		pnode->m_next = NULL;
	}
	pnode->SetInfo(x);	
	return *this;
}
GList& GList::SetNext( const GLNode* node, const NodeElement& x)//��node����һ������Ԫ��ֵ����Ϊx
{
	if(node && node->m_next)
	{
		node->m_next->m_NodeEle.SetElement(x);		//�趨���Ԫ��ֵΪx		
	}
	return *this;
}
GList& GList::SetTail( GList& list)//��list��Ϊ�±�ı�β,list ��ɾ��
{
	GLNode* tmp;
	tmp = m_phead->m_next->m_next;
	m_phead->m_next->m_next = list.m_phead->m_next;
	delete list.m_phead;	
	list.m_phead = NULL;	//ʹlistʧȥ��ԭ����Ŀ��ƣ���ֹ�������������������
	this->remove(tmp);		//ɾ��ԭ��ı�β	
	return *this;
}
GList& GList::SetTail(const GList& list)//��listԪ�ظ���Ϊ��β��list�������仯
{
	GLNode* tmp;
	tmp = m_phead->m_next->m_next;
	m_phead->m_next->m_next = copy(list.m_phead->m_next);//�ݹ鸴��
	this->remove(tmp);		//ɾ��ԭ��ı�β	
	return *this;	
}
GList& GList::Copy(const GList& list)//����һ�������
{
	remove(m_phead->m_next);
	m_phead->m_next = copy(list.m_phead->m_next);	
	return *this;
}
GLNode* GList::copy(const GLNode* nd)	//ȫģʽ�ݹ鸴�ƹ���������Եݹ飬������ʶ���ƣ�	
{
	GLNode* pnode = NULL;
	if(nd)
	{
		pnode = new GLNode;
		if(nd->GetInfo().GetTypeID() == LIST)		//����д洢�����ӱ�
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
int GList::Depth() const	//�ݹ������	
{
	return depth(m_phead);	
}
int GList::depth(const GLNode* list )  const //�ݹ���������	
{
	if(!list->m_next) return 1;	//�ձ����Ϊ1
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
bool GList::operator==(const GList& list) const	//�ж��������Ƿ����
{
	return IsEqual(m_phead, list.m_phead);	
}
bool GList::IsEqual(const GLNode* p, const GLNode* q) const//�ݹ��ж��������Ƿ���Ⱥ���
{
	if(!p->m_next && !q->m_next)
	{
		//p,q���������ǿձ�
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
		//ɨ�赽����һ����ͷ�����������ӱ��������
		else btest = IsEqual(p->m_next->m_NodeEle.GetList(), q->m_next->m_NodeEle.GetList());
		//����е�Ԫ������ȵģ��Ƚ�����һ�����
		if(btest)  
			return IsEqual(p->m_next, q->m_next);
	}
	return false;
}
//�����ɾ��������ͬ��������������
void GList::remove(GLNode* nd)	//������ͷָ��
{
	if(nd)	
	{
		assert(nd->m_NodeEle.GetTypeID() == HEAD);
		nd->m_NodeEle.SetRef(nd->m_NodeEle.GetRef()-1);	//����������һ
		if(!nd->m_NodeEle.GetRef())
		{
			//��ͷ�Ѿ�������Ϊ�κ��ӱ�
			GLNode* ptmp = nd;
			while(ptmp != 0)
			{
				nd = nd->m_next;
				if( nd && nd->m_NodeEle.GetTypeID() == LIST )
				{
					//�ý��Ϊ�ӱ�����,��ݹ�ɾ���ӱ�
					remove(nd->m_NodeEle.GetList());	
				}
				delete ptmp;
				ptmp = nd;				
			}			
		}
	}
}
GList& GList::Delete(const NodeElement& x)//ɾ��������е����е�ָ����Ԫ��
{
	delvalue(m_phead, x);
	return *this;
}
void GList::delvalue( GLNode* list, const NodeElement& x)//ɾ��Ԫ�صĵݹ麯��
{
	//x������ԭ�ӽ���ʾ������
	assert(x.GetTypeID() == CH);	
	if(list->m_next != 0)
	{
		GLNode* ptmp = list->m_next;
		GLNode* q = list;
		while(ptmp)
		{
			if(ptmp->m_NodeEle == x)	//ֱ�ӵ��� NodeElement::operator==()
			{
				//�����ԭ�ӽ�㣬����бȽϣ������ɾ��
				q->m_next = ptmp->m_next;
				delete ptmp;				
			}
			else if(ptmp->m_NodeEle.GetTypeID()==LIST)
			{
				//�����ӱ����ӱ���еݹ�ɾ������
				delvalue(ptmp->m_NodeEle.GetList(), x);
			}
			q = ptmp;
			ptmp = ptmp->m_next;						
		}
	}	
}
//���������½�һ�����
	//�����ʽԼ����
	//21,5,(2,3,(42,p,x,61,n,(x,f,s,6),25,x)),p,x#
	//�����ַ���������������Ϊ��������#Ϊ�������ս���Ʒ���
	//Ҫʡ�������������
void GList::CreateList()//
{
	cout << " �밴����ĸ�ʽ����һ������� \n a,b,(c,d,(e,f,g,h,(i,j,k),l,m)),n# " << endl;
	//������ɾ��ԭ��
	remove(m_phead->m_next);
	m_phead->m_next = createlist(cin);	//������������	
}
GLNode* GList::createlist(istream& in)//�����������д������ɹ��Ǳ�
{
	char ch;
	while(in.get(ch), ch !='#')
	{
		if(ch != ',')
		{
			if(ch == '(')	//chΪ�����ţ�����������һ��ԭ�ӽ�㣬����һ����ͷ�������ݹ�ɨ����
			{
				GLNode* nd = new GLNode;
				GLNode* lhead = new GLNode;
				nd->m_NodeEle.SetList(lhead);	//
				lhead->m_NodeEle.SetRef(1);
				lhead->m_next = createlist(in);	//�ݹ������ӱ�
				nd->m_next = createlist(in);	//�������ӱ���ɺ�����ݹ��������ɱ�
				return nd;
			}
			else if(ch == ')')
			{
				//chΪ�����ţ���ݹ������
				return 0; 
			}
			else //ch��ʾ�ַ�
			{
					GLNode* nd = new GLNode;
					nd->m_NodeEle.SetCharInfo(ch);
					nd->m_next = createlist(in);	//�ݹ���
					return nd;				
			}
		}
	} 
	return 0;	//�ս�ָ��	
}
void GList::output(std::ostream& out,const GLNode* node) const //����������Ĺ����ݹ���ȡ����
{
	if(!node)
	{
		return ;
	}
	switch(node->m_NodeEle.GetTypeID())
	{
		case HEAD:	//��ǰ���Ϊͷ���
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
ostream& operator<<(std::ostream& out, const GList& list)//����������
{
	out << "����������: \n";
	list.output(out,list.m_phead);
	return out;
}