// Sort.h
#ifndef	_SORT_H
#define	_SORT_H
// ��R���в�������
// CompareFunΪ����ָ�룬���Ը��ݴ��뺯����ͬ����ͬ�ؼ��ֱȽ�Ԫ�ش�С
template <class T>
void InsertSort(T R[], int nSize, int (*CompareFun)(T&, T&))
{
	int i, j;
	for (i=1; i<nSize; i++)
	{
		// ����ǰ������Ԫ�ص�ֵ���ڻ�������������������һ��Ԫ�ص�ֵ�����Ԫ
		// �ز���ı�λ��
		if (CompareFun(R[i+1], R[i])>=0)	// ����ͨ�����ú����Ƚ�Ԫ�ش�С
			continue;
		R[0] = R[i+1];	// ��������Ԫ�ط����������
		R[i+1] = R[i];
		// ����ͨ�����ú����Ƚ�Ԫ�ش�С
		for (j=i-1; CompareFun(R[0], R[j])<0; j--) 
			R[j+1] = R[j];
		R[j+1] = R[0];
	}
}
#endif	// end of _SORT_H
