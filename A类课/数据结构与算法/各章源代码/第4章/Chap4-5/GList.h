#ifndef GLIST_H_
#define GLIST_H_ 
#include <string>
#include <iostream>
using namespace std;

//���������Ԫ�����Ͷ���Ϊ����3�ࣺ
//0:HEAD 1:CH 2:LIST
enum EleCate { HEAD=0, CH, LIST };		//ElementCategory Ԫ����������  
 
class GList;
class GLNode;
 
// ���Ԫ����class NodeElement
class NodeElement {
public:			//��Բ�ͬ���ϴ洢���ͽ��й���
	NodeElement();
	NodeElement( char chdata);
	NodeElement( GLNode* link);
	EleCate GetTypeID() const;						//�õ�Ԫ��������Ϣ
	void SetRef(int rf);							//�������ô���
	int GetRef() const;								//�õ����ô���
	void SetCharInfo(char chdata);					//�����ַ�Ԫ��
	char GetCharInfo() const;						//�õ��ַ�Ԫ��
	void SetList(GLNode* link);						//��������Ԫ��
	GLNode* GetList() const;						//�õ�����
	void SetElement( const NodeElement& node);		//���ݽ��Ԫ��ֵ
	NodeElement& operator=( const NodeElement& ne);//���Ԫ�ظ�ֵ
	bool operator==(const NodeElement& ne);		   //���Ƚ�
protected:
	void SetTypeID(EleCate ID);			//�趨Ԫ������
private:
	union EleValue
	{
		int ref;				//m_tag == HEAD,��ű������Ĵ���
		char chardata;			//m_tag ���� CH, ����ַ�
		GLNode* hlink;			//m_tag == LIST, ����²��ӱ��ͷ��ָ��
	};		
	EleCate m_tag;			//��Ǵ�ŵ�Ԫ������
	EleValue m_data;		//Ԫ��ֵ
};
 
 
//����� class GLNode
class GLNode {
 	friend class GList;
public:
	GLNode();
	GLNode( char chdata);
	GLNode( GLNode* link);
	const NodeElement& GetInfo() const;			//��øý�����Ϣ
	void SetInfo(const NodeElement& node);		//���ý�����ݣ�������Է�����ʽ����ת��	 
private:
	NodeElement m_NodeEle;	//����е�Ԫ��
	GLNode* m_next;			//ָ��ͬ����һ������ָ��
	
}; 
class GList {
public:
	GList();
	~GList();
		
	NodeElement& Head();					//���ع�����ͷԪ�ص����ã��ǽ�㣩
	GList Tail();							//���ظù�����β��
	NodeElement& First();					//���ع�����һ��Ԫ�ص�����	
	GList& Push( const NodeElement& x);		//��xֵ��Ϊ��һ������Ԫ��ֵ���뵽�������
	GList& SetHead( const NodeElement& x);	//����һ��Ԫ��ֵ����Ϊx
	GList& SetNext( const GLNode* node, const NodeElement& x);	//��node����һ������Ԫ��ֵ����Ϊx
	GList& SetTail( GList& list);			//��list��Ϊ�±�ı�β,list ��ɾ��
	GList& SetTail( const GList& list);		//��listԪ�ظ���Ϊ��β��list�������仯
	GList& Copy( const GList& list);		//����һ�������
	int Depth() const ;						//����һ����������
	bool operator==(const GList& list) const;//�ж��������Ƿ����
	GList& Delete(const NodeElement& x);	 //ɾ�����к�����ֵΪx��ԭ�ӽ��
	void CreateList();						 //���������½�һ�������
	friend ostream& operator<<(ostream& out, const GList& list);//����������
private:
	GLNode* copy(const GLNode* nd);		//ȫģʽ�ݹ鸴�ƹ���������Եݹ飬������ʶ���ƣ�
	int depth(const GLNode* list) const;//�ݹ������������											
	GLNode* scopy(const GLNode* nd);	//��һģʽ�����Ŀ���,�����޵ݹ���߹���ṹ								
	void remove(GLNode* nd);			//ɾ��nd�������еı���
	bool IsEqual(const GLNode* p, const GLNode* q) const;
	void delvalue(GLNode* list, const NodeElement& x);//ɾ�����к�����ֵΪx��ԭ�ӽ��ĵݹ麯��
	GLNode* createlist(istream& in);			//�����������д������ɹ����
	void output(ostream& out, const GLNode* node) const;//����������Ĺ����ݹ���ȡ����
	GLNode* m_phead;			//��ͷָ��
};
#endif
