template <class T>
int Partition(T R[], int nLow, int nHigh, int nBase)
{
	int nI=nLow, nJ=nHigh;
	// 将基准元素存入R[0]中
	R[0] = R[nBase];
	if (nBase != nLow)
		R[nBase] = R[nLow];
	while (nI!=nJ)
	{
		// 从后向前扫描
		while (nI!=nJ && R[nJ]>=R[0])
			nJ--;
		if (nI!=nJ)
		{
			R[nI] = R[nJ];
			nI++;
		}
		// 从前向后扫描
		while (nI!=nJ && R[nI]<=R[0])
			nI++;
		if (nI!=nJ)
		{
			R[nJ] = R[nI];
			nJ--;
		}
	}
	// 将基准元素放入正确位置
	R[nI] = R[0];
	return nI;
}

template <class T>
void QuickSort(T R[], int nLow, int nHigh)
{
	int nBase;	// 每次划分后基准元素所在的位置
	if (nLow < nHigh)	// 待划分的集合长度大于
	{
		// 以R[nLow]为基准对集合{R[nLow], R[nLow+1], ..., R[nHigh]}进行划分
		nBase = Partition(R, nLow, nHigh, nLow);
		// 对划分后的两个子集合分别进行快速排序
		QuickSort(R, nLow, nBase-1);
		QuickSort(R, nBase+1, nHigh);
	}
}
