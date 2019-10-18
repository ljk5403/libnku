// IndexTable.h
#ifndef _INDEXTABLE_H
#define _INDEXTABLE_H
template <class T1, class T2>
class IndexTable 	// 索引表类模板定义
{
public:
	void SetData(T1 pElem, T2 key) 	// 设置索引表信息
	{
		m_pElem = pElem;
		m_key = key;
	}
	bool operator!=(IndexTable &it) { return m_key!=it.m_key; } 	// 重载!=运算符
	bool operator==(IndexTable &it) { return m_key==it.m_key; } 	// 重载==运算符
	bool operator<(IndexTable &it) { return m_key<it.m_key; } 	// 重载<运算符
	T1& GetElem() { return m_pElem; } 	// 获取指向元素的指针
	T2& GetKey() { return m_key; } 	// 获取元素的关键字值
private:
	T1 m_pElem;	// 指向元素的指针
	T2 m_key;	// 元素的关键字值
};
#endif	// end of _INDEXTABLE_H
