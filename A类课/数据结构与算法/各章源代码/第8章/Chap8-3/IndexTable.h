// IndexTable.h
#ifndef _INDEXTABLE_H
#define _INDEXTABLE_H
template <class T1, class T2>
class IndexTable 	// ��������ģ�嶨��
{
public:
	void SetData(T1 pElem, T2 key) 	// ������������Ϣ
	{
		m_pElem = pElem;
		m_key = key;
	}
	bool operator!=(IndexTable &it) { return m_key!=it.m_key; } 	// ����!=�����
	bool operator==(IndexTable &it) { return m_key==it.m_key; } 	// ����==�����
	bool operator<(IndexTable &it) { return m_key<it.m_key; } 	// ����<�����
	T1& GetElem() { return m_pElem; } 	// ��ȡָ��Ԫ�ص�ָ��
	T2& GetKey() { return m_key; } 	// ��ȡԪ�صĹؼ���ֵ
private:
	T1 m_pElem;	// ָ��Ԫ�ص�ָ��
	T2 m_key;	// Ԫ�صĹؼ���ֵ
};
#endif	// end of _INDEXTABLE_H
