#include <iostream>
#include "SearchAlgorithms.h"
using namespace std;
// �����ϣ����
int CYF11(const int& n)
{
	return n%11;
}
int main()
{
	int nR[] = {0, 43, 56, 37, 28, 17, 39, 22};
	int nSize=sizeof(nR)/sizeof(nR[0])-1;
	int nK=39, nX=0;
	HashTable<int> hashtable(11, CYF11);
	hashtable.CreateHashTable(nR, nSize);	// ������ϣ��
	hashtable.Display();	// ��ʾ��ϣ���е�����Ԫ��
	// ���ݸ���ֵnK���й�ϣ���ң����ҽ��������nX��
	if (hashtable.SearchHashTable(nK, nX)) 	// ���ҳɹ�
		cout<<"���ҳɹ���"<<nX<<endl;
	else
		cout<<"����ʧ�ܣ�"<<endl;
	return 0;
}
