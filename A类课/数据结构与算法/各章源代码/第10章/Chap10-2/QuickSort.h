template <class T>
int Partition(T R[], int nLow, int nHigh, int nBase)
{
	int nI=nLow, nJ=nHigh;
	// ����׼Ԫ�ش���R[0]��
	R[0] = R[nBase];
	if (nBase != nLow)
		R[nBase] = R[nLow];
	while (nI!=nJ)
	{
		// �Ӻ���ǰɨ��
		while (nI!=nJ && R[nJ]>=R[0])
			nJ--;
		if (nI!=nJ)
		{
			R[nI] = R[nJ];
			nI++;
		}
		// ��ǰ���ɨ��
		while (nI!=nJ && R[nI]<=R[0])
			nI++;
		if (nI!=nJ)
		{
			R[nJ] = R[nI];
			nJ--;
		}
	}
	// ����׼Ԫ�ط�����ȷλ��
	R[nI] = R[0];
	return nI;
}

template <class T>
void QuickSort(T R[], int nLow, int nHigh)
{
	int nBase;	// ÿ�λ��ֺ��׼Ԫ�����ڵ�λ��
	if (nLow < nHigh)	// �����ֵļ��ϳ��ȴ���
	{
		// ��R[nLow]Ϊ��׼�Լ���{R[nLow], R[nLow+1], ..., R[nHigh]}���л���
		nBase = Partition(R, nLow, nHigh, nLow);
		// �Ի��ֺ�������Ӽ��Ϸֱ���п�������
		QuickSort(R, nLow, nBase-1);
		QuickSort(R, nBase+1, nHigh);
	}
}
