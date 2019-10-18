#ifndef GLIST_H_
#define GLIST_H_ 
#include <string>
#include <iostream>
using namespace std;

//广义表结点中元素类型定义为下面3类：
//0:HEAD 1:CH 2:LIST
enum EleCate { HEAD=0, CH, LIST };		//ElementCategory 元素类型种类  
 
class GList;
class GLNode;
 
// 结点元素类class NodeElement
class NodeElement {
public:			//针对不同联合存储类型进行构造
	NodeElement();
	NodeElement( char chdata);
	NodeElement( GLNode* link);
	EleCate GetTypeID() const;						//得到元素类型信息
	void SetRef(int rf);							//设置引用次数
	int GetRef() const;								//得到引用次数
	void SetCharInfo(char chdata);					//设置字符元素
	char GetCharInfo() const;						//得到字符元素
	void SetList(GLNode* link);						//设置链表元素
	GLNode* GetList() const;						//得到链表
	void SetElement( const NodeElement& node);		//根据结点元素值
	NodeElement& operator=( const NodeElement& ne);//结点元素赋值
	bool operator==(const NodeElement& ne);		   //结点比较
protected:
	void SetTypeID(EleCate ID);			//设定元素类型
private:
	union EleValue
	{
		int ref;				//m_tag == HEAD,存放表被引动的次数
		char chardata;			//m_tag ＝＝ CH, 存放字符
		GLNode* hlink;			//m_tag == LIST, 存放下层子表的头的指针
	};		
	EleCate m_tag;			//标记存放的元素种类
	EleValue m_data;		//元素值
};
 
 
//结点类 class GLNode
class GLNode {
 	friend class GList;
public:
	GLNode();
	GLNode( char chdata);
	GLNode( GLNode* link);
	const NodeElement& GetInfo() const;			//获得该结点的信息
	void SetInfo(const NodeElement& node);		//设置结点内容，这里可以发生隐式类型转换	 
private:
	NodeElement m_NodeEle;	//结点中的元素
	GLNode* m_next;			//指向同层下一个结点的指针
	
}; 
class GList {
public:
	GList();
	~GList();
		
	NodeElement& Head();					//返回广义表表头元素的引用（非结点）
	GList Tail();							//返回该广义表的尾表
	NodeElement& First();					//返回广义表第一个元素的引用	
	GList& Push( const NodeElement& x);		//将x值作为第一个结点的元素值插入到广义表中
	GList& SetHead( const NodeElement& x);	//将第一个元素值设置为x
	GList& SetNext( const GLNode* node, const NodeElement& x);	//将node结点后一个结点的元素值设置为x
	GList& SetTail( GList& list);			//将list作为新表的表尾,list 被删除
	GList& SetTail( const GList& list);		//将list元素复制为表尾，list不发生变化
	GList& Copy( const GList& list);		//复制一个广义表
	int Depth() const ;						//计算一个广义表深度
	bool operator==(const GList& list) const;//判断两个表是否相等
	GList& Delete(const NodeElement& x);	 //删除表中含所有值为x的原子结点
	void CreateList();						 //由输入流新建一个广义表
	friend ostream& operator<<(ostream& out, const GList& list);//输出流输出表
private:
	GLNode* copy(const GLNode* nd);		//全模式递归复制广义表（包括对递归，共享表的识别复制）
	int depth(const GLNode* list) const;//递归计算广义表的深度											
	GLNode* scopy(const GLNode* nd);	//单一模式广义表的拷贝,表中无递归或者共享结构								
	void remove(GLNode* nd);			//删除nd结点后所有的表结点
	bool IsEqual(const GLNode* p, const GLNode* q) const;
	void delvalue(GLNode* list, const NodeElement& x);//删除表中含所有值为x的原子结点的递归函数
	GLNode* createlist(istream& in);			//对输入流进行处理，生成广义表
	void output(ostream& out, const GLNode* node) const;//用于输出流的广义表递归提取函数
	GLNode* m_phead;			//表头指针
};
#endif
