#ifndef	_SORTALGORITHMS_H
#define	_SORTALGORITHMS_H
#include "LinkQueue.h"
#include "LinkStack.h"
// 直接插入排序
template <class T>
void InsertSort(T R[], int nSize)
{
	int i, j;
	for (i=1; i<nSize; i++)
	{
		// 若当前待排序元素的值大于或等于已排序序列中最后一个元素的值，则该元
		// 素不需改变位置
		if (R[i+1]>=R[i])	
			continue;
		R[0] = R[i+1];	// 将待排序元素放入监视哨中
		R[i+1] = R[i];
		for (j=i-1; R[0]<R[j]; j--)	// 利用监视哨可以省去下标取值范围的检查条件
			R[j+1] = R[j];
		R[j+1] = R[0];
	}
}

// 希尔排序
// 由ShellSort调用，按增量di分组并在各组内进行直接插入排序
template <class T>
void ShellInsert(T R[], int nSize, int di)
{
	int i, j;
	for (i=1; i<=nSize-di; i++)
	{
		// 若分组中当前待排序元素的值大于或等于已排序序列中最后一个元素的值，
		// 则该元素不需改变位置
		if (R[i+di]>=R[i])
			continue;
		R[0] = R[i+di];	// 将待排序元素放入监视哨中
		for (j=i; j>0 && R[0]<R[j]; j-=di)
			R[j+di] = R[j];
		R[j+di] = R[0];
	}
}
// 按增量序列d对数组R中的元素进行希尔排序
template <class T>
void ShellSort(T R[], int nSize, int d[], int k)
{
	int i;
	for (i=0; i<k; i++)
		ShellInsert(R, nSize, d[i]);
}

// 简单选择排序
template <class T>
void SelectSort(T R[], int nSize)
{
	int i, j, nMin;
	for (i=1; i<nSize; i++)
	{
		nMin = i;	// 先假设待排序区中下标为nI的元素值最小
		// 通过循环找出待排序区中具有最小值的元素位置
		for (j=i+1; j<=nSize; j++)
			if (R[j]<R[nMin])
				nMin = j;
		// 若待排序区中第一个元素具有最小值，则不需进行交换
		if (nMin==i)	
			continue;
		// 将待排序区中具有最小值的元素与第一个元素交换位置
		R[0] = R[i];
		R[i] = R[nMin];
		R[nMin] = R[0];
	}
}

// 堆排序
// 由HeapSort调用，将数组中nTop到nBottom之间的元素调整为大根堆
// 要求除nR[nTop]外，nTop+1到nBottom之间的元素均满足大根堆的条件
template <class T>
void Sift(T R[], int nTop, int nBottom)
{
	int i;
	R[0] = R[nTop];	// 记录待调整的元素
	i = 2*nTop;	// nR[i]是nR[nTop]的左孩子
	while (i <= nBottom)// 当左孩子存在时则一直循环
	{
		// 若右孩子存在且右孩子关键字较大，则将右孩子与待调整元素比较
		if (i<nBottom && R[i]<R[i+1])
			i++;
		// 若待调整元素比当前孩子关键字小
		if (R[0] < R[i])
		{
			R[nTop] = R[i];// 将当前孩子调整到双亲的位置上
			nTop = i;// 将待调整元素放到当前孩子位置上
		}
		else
			break;//待调整元素比当前孩子关键字大，nTop即为待调整元素应放位置
		i = 2*nTop;	// nR[i]是nR[nTop]的左孩子
	}
	R[nTop] = R[0];
}
// 对R进行堆排序
template <class T>
void HeapSort(T R[], int nSize)
{
	int i;
	// 将R调整为大根堆
	for (i=nSize/2; i>0; i--)
		Sift(R, i, nSize);
	for (i=nSize; i>1; i--)
	{
		// 将堆中最大元素与堆中最后一个元素交换位置
		R[0] = R[1];
		R[1] = R[i];
		R[i] = R[0];
		// 将R中前nI-1个元素调整为大根堆
		Sift(R, 1, i-1);
	}
}

// 冒泡排序
// 对R进行冒泡排序
template <class T>
void BubbleSort(T R[], int nSize)
{
	int i, j;
	bool bSwap;
	for (i=nSize; i>0; i--)// 待排序区的终止位置
	{
		bSwap = false;
		for (j=1; j<i; j++)
		{
			// 若相邻两个元素次序相反，则交换它们的位置
			if (R[j] > R[j+1])
			{
				R[0] = R[j];
				R[j] = R[j+1];
				R[j+1] = R[0];
				bSwap = true;
			}
		}
		// 若没有出现相邻元素交换的情况，则冒泡排序结束
		if (!bSwap)
			break;
	}
}

// 快速排序
// 对集合{R[low], R[low+1], ..., R[high]}进行划分
template <class T>
int Partition(T R[], int low, int high, int nBase)
{
	int i=low, j=high;
	// 将基准元素存入R[0]中
	R[0] = R[nBase];
	if (nBase != low)
		R[nBase] = R[low];
	while (i!=j)
	{
		// 从后向前扫描
		while (i!=j && R[j]>=R[0])
			j--;
		if (i!=j)
		{
			R[i] = R[j];
			i++;
		}
		// 从前向后扫描
		while (i!=j && R[i]<=R[0])
			i++;
		if (i!=j)
		{
			R[j] = R[i];
			j--;
		}
	}
	// 将基准元素放入正确位置
	R[i] = R[0];
	return i;
}
// 对R进行快速排序的递归实现
template <class T>
void QuickSort(T R[], int low, int high)
{
	int nBase;	// 每次划分后基准元素所在的位置
	if (low < high)	// 待划分的集合长度大于
	{
		// 以R[low]为基准对集合{R[low], R[low+1], ..., R[high]}进行划分
		nBase = Partition(R, low, high, low);
		// 对划分后的两个子集合分别进行快速排序
		QuickSort(R, low, nBase-1);
		QuickSort(R, nBase+1, high);
	}
}
// 对R进行快速排序的非递归实现
class Range	// 存储每次划分后子集合的起始位置和终止位置
{
public:
	template <class T>
	friend void QuickSort(T R[], int nSize);
	Range() { m_low = m_high = 0; }
	Range(int low, int high)
	{
		m_low = low;
		m_high = high;
	}
private:
	int m_low;
	int m_high;
};
template <class T>
void QuickSort(T R[], int nSize)
{
	LinkStack<Range> s;	// 保存需要进行划分的集合
	int nBase;	// 每次划分后基准元素所在的位置
	Range range(1, nSize), lastPopRange(nSize+1, nSize+1);
	s.Push(range);	// 初始对整个集合进行划分
	while (!s.IsEmpty())	// 栈不为空表示仍有需要进行划分的集合
	{
		s.Top(range);	// 取栈顶元素
		// 若上一次出栈的是划分后的两个子集合中的后一个子集合，则作出栈操作
		if (range.m_high==lastPopRange.m_high)
		{
			s.Pop(lastPopRange);
			continue;
		}
		// 若上一次出栈的是划分后的两个子集合中的前一个子集合，则将后一个子集
		// 合入栈
		else if (range.m_low==lastPopRange.m_low)
		{
			s.Push(Range(lastPopRange.m_high+2, range.m_high));
			continue;
		}
		if (range.m_low < range.m_high)	// 若待划分集合长度大于1
		{
			// 以R[low]为基准对集合{R[low], R[low+1], ..., R[high]}进行划分
			nBase = Partition(R, range.m_low, range.m_high, range.m_low);
			// 将划分后的两个子集合中的前一个子集合入栈
			s.Push(Range(range.m_low, nBase-1));
		}
		else	// 否则将其出栈
			s.Pop(lastPopRange);
	}
}

// 归并排序
// 将pSrc所指向的数组中下标为[low,mid]的子序列与下标为[mid+1,high]的子序
// 列归并，归并结果保存在pDst所指向数组中相应的位置
template <class T>
void Merge(T *pSrc, T *pDst, int low, int mid, int high)
{
	int i=low, j=mid+1, k=low;
	while (i<=mid && j<=high)
	{
		// 比较下标为nI和nJ的两个元素，将具有较小值的元素先取出赋到pDst所
		// 指向的数组中
		if (pSrc[i]<=pSrc[j])
		{
			pDst[k]=pSrc[i];
			i++;
		}
		else
		{
			pDst[k]=pSrc[j];
			j++;
		}
		k++;
	}
	// 若一个子序列已处理完毕、而另一个子序列中还有元素未处理，则直接将这些元
	// 素赋到pDst所指向的数组中
	while (i<=mid)
	{
		pDst[k]=pSrc[i];
		i++;
		k++;
	}
	while (j<=high)
	{
		pDst[k]=pSrc[j];
		j++;
		k++;
	}
}
// 将pSrc所指向的数组中相邻的两个长度为nLength的子序列归并
// 归并结果保存在pDst所指向的数组中
template <class T>
void MergePass(T *pSrc, T *pDst, int nSize, int nLength)
{
	int i, j;
	// 将相邻的两个长度为nLength的子序列归并
	for (i=0; (i+2)*nLength<=nSize; i+=2)
		Merge(pSrc, pDst, i*nLength+1, (i+1)*nLength, (i+2)*nLength);
	if ((i+1)*nLength<nSize) // 后一个子序列长度不足nLength
		Merge(pSrc, pDst, i*nLength+1, (i+1)*nLength, nSize);
	else // 最后只剩下一个子序列，则直接拷贝该子序列中的元素
		for (j=i*nLength+1; j<=nSize; j++)
			pDst[j]=pSrc[j];
}
// 对R进行归并排序
template <class T>
void MergeSort(T R[], int nSize)
{
	int nLength;	// 待归并的子序列长度
	T *MR = new T[nSize+1];	// 存放归并后的结果
	T *pSrc=R, *pDst=MR, *pTemp;
	int i;
	if (MR==NULL)
		exit(1);
	for (nLength=1; nLength<nSize; nLength*=2)
	{
		// 将pSrc指向数组中相邻的两个长度为nLength的子序列归并，
		// 归并结果保存在pDst所指向的数组中
		MergePass(pSrc, pDst, nSize, nLength);
		// 交换pSrc和pDst的指向，即基于上一轮归并结果进行下一轮子序列归并
		pTemp=pSrc;
		pSrc=pDst;
		pDst=pTemp;
	}
	if (pSrc!=R) // 若最后一轮归并后的结果保存在MR中
	{
		for (i=1; i<=nSize; i++)
			R[i]=MR[i];
	}
	delete []MR;
}

// 对R进行箱排序
template <class T>
void BinSort(T R[], int nSize)
{
	int nMax=1, nMin=1, nRange, i, j;
	LinkQueue<T> *B = NULL;
	// 计算待排序元素的取值范围
	for (i=2; i<=nSize; i++)
	{
		if (R[i] < R[nMin])
			nMin = i;
		else if (R[i] > R[nMax])
			nMax = i;
	}
	nRange = R[nMax]-R[nMin]+1;
	// 根据待排序元素取值范围设置箱子
	B = new LinkQueue<T>[nRange];
	if (B==NULL)
		exit(1);
	// 根据元素值通过入队操作将其装入对应的箱子
	for (i=1; i<=nSize; i++)
		B[R[i]-R[nMin]].Insert(R[i]);
	// 通过出队操作依次从箱子中取出元素并放回到R中
	i = 1;
	for (j=0; j<nRange; j++)
	{
		while (!B[j].IsEmpty())
		{
			B[j].Delete(R[i]);
			i++;
		}
	}
	// 释放箱子所占据的空间
	delete []B;
}

// 根据A中元素值对R进行箱排序，由基数排序调用
template <class T1, class T2>
void BinSort(T1 R[], int nSize, T2 A[])
{
	int nMax=1, nMin=1, nRange, i, j;
	LinkQueue<T1> *B = NULL;
	// 计算待排序元素的取值范围
	for (i=2; i<=nSize; i++)
	{
		if (A[i] < A[nMin])
			nMin = i;
		else if (A[i] > A[nMax])
			nMax = i;
	}
	nRange = A[nMax]-A[nMin]+1;
	// 根据待排序元素取值范围设置箱子
	B = new LinkQueue<T1>[nRange];
	if (B==NULL)
		exit(1);
	// 根据元素值通过入队操作将其装入对应的箱子
	for (i=1; i<=nSize; i++)
		B[A[i]-A[nMin]].Insert(R[i]);
	// 通过出队操作依次从箱子中取出元素并放回到R中
	i = 1;
	for (j=0; j<nRange; j++)
	{
		while (!B[j].IsEmpty())
		{
			B[j].Delete(R[i]);
			i++;
		}
	}
	// 释放箱子所占据的空间
	delete []B;
}

// 对字符串数组R进行基数排序
void RadixSort(char* R[], int nSize)
{
	int nMaxLen=0;	// 记录最长字符串的长度
	int i, j;
	char *A=new char[nSize+1]; // 记录每次用于箱排序的字符值
	if (A==NULL)
		exit(1);
	// 计算最长字符串的长度
	for (i=1; i<=nSize; i++)
	{
		if (nMaxLen<(int)strlen(R[i]))
			nMaxLen=(int)strlen(R[i]);
	}
	// 按照从后至前的顺序进行nMaxLen次箱排序
	for (j=nMaxLen; j>=1; j--)
	{
		// 将用于箱排序的字符值放在A中
		for (i=1; i<=nSize; i++)
		{
			if ((int)strlen(R[i])<j)
				A[i]='\0';
			else
				A[i]=R[i][j-1];
		}
		// 进行一轮箱排序
		BinSort(R, nSize, A);
	}
	delete []A;
}

// 对数字数组R进行基数排序
// nN和nM为整数部分和小数部分的最大长度
template <class T>
void RadixSort(T R[], int nSize, int nN, int nM)
{
	int i;
	char cFormatN[50], cFormatM[50];
	char **S=new char*[nSize+1];
	char *cM=new char[nM+3]; // 记录小数部分对应的字符串
	if (S==NULL || cM==NULL)
		exit(1);
	// 将待排序数字先转为字符串以方便处理
	sprintf(cFormatN, "%%0%dd", nN);
	sprintf(cFormatM, "%%.0%dlf", nM);
	for (i=1; i<=nSize; i++)
	{
		S[i]=new char[nN+nM+2];
		if (S[i]==NULL)
			exit(1);
		sprintf(S[i], cFormatN, (int)R[i]);
		if (nM!=0)
		{
			sprintf(cM, cFormatM, R[i]-(int)R[i]);
			strcat(S[i], &cM[1]);
		}
	}
	// 对转换后的字符串数组R进行基数排序
	RadixSort(S, nSize);
	// 将排序后的结果转换为数字存储到数字数组R中
	for (i=1; i<=nSize; i++)
	{
		R[i] = (T)atof(S[i]);
		delete []S[i];
	}
	delete []S;
	delete []cM;
}
#endif	// end of _SORTALGORITHMS_H