#ifndef	_SORTALGORITHMS_H
#define	_SORTALGORITHMS_H
#include "LinkQueue.h"
#include "LinkStack.h"
// ֱ�Ӳ�������
template <class T>
void InsertSort(T R[], int nSize)
{
	int i, j;
	for (i=1; i<nSize; i++)
	{
		// ����ǰ������Ԫ�ص�ֵ���ڻ�������������������һ��Ԫ�ص�ֵ�����Ԫ
		// �ز���ı�λ��
		if (R[i+1]>=R[i])	
			continue;
		R[0] = R[i+1];	// ��������Ԫ�ط����������
		R[i+1] = R[i];
		for (j=i-1; R[0]<R[j]; j--)	// ���ü����ڿ���ʡȥ�±�ȡֵ��Χ�ļ������
			R[j+1] = R[j];
		R[j+1] = R[0];
	}
}

// ϣ������
// ��ShellSort���ã�������di���鲢�ڸ����ڽ���ֱ�Ӳ�������
template <class T>
void ShellInsert(T R[], int nSize, int di)
{
	int i, j;
	for (i=1; i<=nSize-di; i++)
	{
		// �������е�ǰ������Ԫ�ص�ֵ���ڻ�������������������һ��Ԫ�ص�ֵ��
		// ���Ԫ�ز���ı�λ��
		if (R[i+di]>=R[i])
			continue;
		R[0] = R[i+di];	// ��������Ԫ�ط����������
		for (j=i; j>0 && R[0]<R[j]; j-=di)
			R[j+di] = R[j];
		R[j+di] = R[0];
	}
}
// ����������d������R�е�Ԫ�ؽ���ϣ������
template <class T>
void ShellSort(T R[], int nSize, int d[], int k)
{
	int i;
	for (i=0; i<k; i++)
		ShellInsert(R, nSize, d[i]);
}

// ��ѡ������
template <class T>
void SelectSort(T R[], int nSize)
{
	int i, j, nMin;
	for (i=1; i<nSize; i++)
	{
		nMin = i;	// �ȼ�������������±�ΪnI��Ԫ��ֵ��С
		// ͨ��ѭ���ҳ����������о�����Сֵ��Ԫ��λ��
		for (j=i+1; j<=nSize; j++)
			if (R[j]<R[nMin])
				nMin = j;
		// �����������е�һ��Ԫ�ؾ�����Сֵ��������н���
		if (nMin==i)	
			continue;
		// �����������о�����Сֵ��Ԫ�����һ��Ԫ�ؽ���λ��
		R[0] = R[i];
		R[i] = R[nMin];
		R[nMin] = R[0];
	}
}

// ������
// ��HeapSort���ã���������nTop��nBottom֮���Ԫ�ص���Ϊ�����
// Ҫ���nR[nTop]�⣬nTop+1��nBottom֮���Ԫ�ؾ��������ѵ�����
template <class T>
void Sift(T R[], int nTop, int nBottom)
{
	int i;
	R[0] = R[nTop];	// ��¼��������Ԫ��
	i = 2*nTop;	// nR[i]��nR[nTop]������
	while (i <= nBottom)// �����Ӵ���ʱ��һֱѭ��
	{
		// ���Һ��Ӵ������Һ��ӹؼ��ֽϴ����Һ����������Ԫ�رȽ�
		if (i<nBottom && R[i]<R[i+1])
			i++;
		// ��������Ԫ�رȵ�ǰ���ӹؼ���С
		if (R[0] < R[i])
		{
			R[nTop] = R[i];// ����ǰ���ӵ�����˫�׵�λ����
			nTop = i;// ��������Ԫ�طŵ���ǰ����λ����
		}
		else
			break;//������Ԫ�رȵ�ǰ���ӹؼ��ִ�nTop��Ϊ������Ԫ��Ӧ��λ��
		i = 2*nTop;	// nR[i]��nR[nTop]������
	}
	R[nTop] = R[0];
}
// ��R���ж�����
template <class T>
void HeapSort(T R[], int nSize)
{
	int i;
	// ��R����Ϊ�����
	for (i=nSize/2; i>0; i--)
		Sift(R, i, nSize);
	for (i=nSize; i>1; i--)
	{
		// ���������Ԫ����������һ��Ԫ�ؽ���λ��
		R[0] = R[1];
		R[1] = R[i];
		R[i] = R[0];
		// ��R��ǰnI-1��Ԫ�ص���Ϊ�����
		Sift(R, 1, i-1);
	}
}

// ð������
// ��R����ð������
template <class T>
void BubbleSort(T R[], int nSize)
{
	int i, j;
	bool bSwap;
	for (i=nSize; i>0; i--)// ������������ֹλ��
	{
		bSwap = false;
		for (j=1; j<i; j++)
		{
			// ����������Ԫ�ش����෴���򽻻����ǵ�λ��
			if (R[j] > R[j+1])
			{
				R[0] = R[j];
				R[j] = R[j+1];
				R[j+1] = R[0];
				bSwap = true;
			}
		}
		// ��û�г�������Ԫ�ؽ������������ð���������
		if (!bSwap)
			break;
	}
}

// ��������
// �Լ���{R[low], R[low+1], ..., R[high]}���л���
template <class T>
int Partition(T R[], int low, int high, int nBase)
{
	int i=low, j=high;
	// ����׼Ԫ�ش���R[0]��
	R[0] = R[nBase];
	if (nBase != low)
		R[nBase] = R[low];
	while (i!=j)
	{
		// �Ӻ���ǰɨ��
		while (i!=j && R[j]>=R[0])
			j--;
		if (i!=j)
		{
			R[i] = R[j];
			i++;
		}
		// ��ǰ���ɨ��
		while (i!=j && R[i]<=R[0])
			i++;
		if (i!=j)
		{
			R[j] = R[i];
			j--;
		}
	}
	// ����׼Ԫ�ط�����ȷλ��
	R[i] = R[0];
	return i;
}
// ��R���п�������ĵݹ�ʵ��
template <class T>
void QuickSort(T R[], int low, int high)
{
	int nBase;	// ÿ�λ��ֺ��׼Ԫ�����ڵ�λ��
	if (low < high)	// �����ֵļ��ϳ��ȴ���
	{
		// ��R[low]Ϊ��׼�Լ���{R[low], R[low+1], ..., R[high]}���л���
		nBase = Partition(R, low, high, low);
		// �Ի��ֺ�������Ӽ��Ϸֱ���п�������
		QuickSort(R, low, nBase-1);
		QuickSort(R, nBase+1, high);
	}
}
// ��R���п�������ķǵݹ�ʵ��
class Range	// �洢ÿ�λ��ֺ��Ӽ��ϵ���ʼλ�ú���ֹλ��
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
	LinkStack<Range> s;	// ������Ҫ���л��ֵļ���
	int nBase;	// ÿ�λ��ֺ��׼Ԫ�����ڵ�λ��
	Range range(1, nSize), lastPopRange(nSize+1, nSize+1);
	s.Push(range);	// ��ʼ���������Ͻ��л���
	while (!s.IsEmpty())	// ջ��Ϊ�ձ�ʾ������Ҫ���л��ֵļ���
	{
		s.Top(range);	// ȡջ��Ԫ��
		// ����һ�γ�ջ���ǻ��ֺ�������Ӽ����еĺ�һ���Ӽ��ϣ�������ջ����
		if (range.m_high==lastPopRange.m_high)
		{
			s.Pop(lastPopRange);
			continue;
		}
		// ����һ�γ�ջ���ǻ��ֺ�������Ӽ����е�ǰһ���Ӽ��ϣ��򽫺�һ���Ӽ�
		// ����ջ
		else if (range.m_low==lastPopRange.m_low)
		{
			s.Push(Range(lastPopRange.m_high+2, range.m_high));
			continue;
		}
		if (range.m_low < range.m_high)	// �������ּ��ϳ��ȴ���1
		{
			// ��R[low]Ϊ��׼�Լ���{R[low], R[low+1], ..., R[high]}���л���
			nBase = Partition(R, range.m_low, range.m_high, range.m_low);
			// �����ֺ�������Ӽ����е�ǰһ���Ӽ�����ջ
			s.Push(Range(range.m_low, nBase-1));
		}
		else	// �������ջ
			s.Pop(lastPopRange);
	}
}

// �鲢����
// ��pSrc��ָ����������±�Ϊ[low,mid]�����������±�Ϊ[mid+1,high]������
// �й鲢���鲢���������pDst��ָ����������Ӧ��λ��
template <class T>
void Merge(T *pSrc, T *pDst, int low, int mid, int high)
{
	int i=low, j=mid+1, k=low;
	while (i<=mid && j<=high)
	{
		// �Ƚ��±�ΪnI��nJ������Ԫ�أ������н�Сֵ��Ԫ����ȡ������pDst��
		// ָ���������
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
	// ��һ���������Ѵ�����ϡ�����һ���������л���Ԫ��δ������ֱ�ӽ���ЩԪ
	// �ظ���pDst��ָ���������
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
// ��pSrc��ָ������������ڵ���������ΪnLength�������й鲢
// �鲢���������pDst��ָ���������
template <class T>
void MergePass(T *pSrc, T *pDst, int nSize, int nLength)
{
	int i, j;
	// �����ڵ���������ΪnLength�������й鲢
	for (i=0; (i+2)*nLength<=nSize; i+=2)
		Merge(pSrc, pDst, i*nLength+1, (i+1)*nLength, (i+2)*nLength);
	if ((i+1)*nLength<nSize) // ��һ�������г��Ȳ���nLength
		Merge(pSrc, pDst, i*nLength+1, (i+1)*nLength, nSize);
	else // ���ֻʣ��һ�������У���ֱ�ӿ������������е�Ԫ��
		for (j=i*nLength+1; j<=nSize; j++)
			pDst[j]=pSrc[j];
}
// ��R���й鲢����
template <class T>
void MergeSort(T R[], int nSize)
{
	int nLength;	// ���鲢�������г���
	T *MR = new T[nSize+1];	// ��Ź鲢��Ľ��
	T *pSrc=R, *pDst=MR, *pTemp;
	int i;
	if (MR==NULL)
		exit(1);
	for (nLength=1; nLength<nSize; nLength*=2)
	{
		// ��pSrcָ�����������ڵ���������ΪnLength�������й鲢��
		// �鲢���������pDst��ָ���������
		MergePass(pSrc, pDst, nSize, nLength);
		// ����pSrc��pDst��ָ�򣬼�������һ�ֹ鲢���������һ�������й鲢
		pTemp=pSrc;
		pSrc=pDst;
		pDst=pTemp;
	}
	if (pSrc!=R) // �����һ�ֹ鲢��Ľ��������MR��
	{
		for (i=1; i<=nSize; i++)
			R[i]=MR[i];
	}
	delete []MR;
}

// ��R����������
template <class T>
void BinSort(T R[], int nSize)
{
	int nMax=1, nMin=1, nRange, i, j;
	LinkQueue<T> *B = NULL;
	// ���������Ԫ�ص�ȡֵ��Χ
	for (i=2; i<=nSize; i++)
	{
		if (R[i] < R[nMin])
			nMin = i;
		else if (R[i] > R[nMax])
			nMax = i;
	}
	nRange = R[nMax]-R[nMin]+1;
	// ���ݴ�����Ԫ��ȡֵ��Χ��������
	B = new LinkQueue<T>[nRange];
	if (B==NULL)
		exit(1);
	// ����Ԫ��ֵͨ����Ӳ�������װ���Ӧ������
	for (i=1; i<=nSize; i++)
		B[R[i]-R[nMin]].Insert(R[i]);
	// ͨ�����Ӳ������δ�������ȡ��Ԫ�ز��Żص�R��
	i = 1;
	for (j=0; j<nRange; j++)
	{
		while (!B[j].IsEmpty())
		{
			B[j].Delete(R[i]);
			i++;
		}
	}
	// �ͷ�������ռ�ݵĿռ�
	delete []B;
}

// ����A��Ԫ��ֵ��R�����������ɻ����������
template <class T1, class T2>
void BinSort(T1 R[], int nSize, T2 A[])
{
	int nMax=1, nMin=1, nRange, i, j;
	LinkQueue<T1> *B = NULL;
	// ���������Ԫ�ص�ȡֵ��Χ
	for (i=2; i<=nSize; i++)
	{
		if (A[i] < A[nMin])
			nMin = i;
		else if (A[i] > A[nMax])
			nMax = i;
	}
	nRange = A[nMax]-A[nMin]+1;
	// ���ݴ�����Ԫ��ȡֵ��Χ��������
	B = new LinkQueue<T1>[nRange];
	if (B==NULL)
		exit(1);
	// ����Ԫ��ֵͨ����Ӳ�������װ���Ӧ������
	for (i=1; i<=nSize; i++)
		B[A[i]-A[nMin]].Insert(R[i]);
	// ͨ�����Ӳ������δ�������ȡ��Ԫ�ز��Żص�R��
	i = 1;
	for (j=0; j<nRange; j++)
	{
		while (!B[j].IsEmpty())
		{
			B[j].Delete(R[i]);
			i++;
		}
	}
	// �ͷ�������ռ�ݵĿռ�
	delete []B;
}

// ���ַ�������R���л�������
void RadixSort(char* R[], int nSize)
{
	int nMaxLen=0;	// ��¼��ַ����ĳ���
	int i, j;
	char *A=new char[nSize+1]; // ��¼ÿ��������������ַ�ֵ
	if (A==NULL)
		exit(1);
	// ������ַ����ĳ���
	for (i=1; i<=nSize; i++)
	{
		if (nMaxLen<(int)strlen(R[i]))
			nMaxLen=(int)strlen(R[i]);
	}
	// ���մӺ���ǰ��˳�����nMaxLen��������
	for (j=nMaxLen; j>=1; j--)
	{
		// ��������������ַ�ֵ����A��
		for (i=1; i<=nSize; i++)
		{
			if ((int)strlen(R[i])<j)
				A[i]='\0';
			else
				A[i]=R[i][j-1];
		}
		// ����һ��������
		BinSort(R, nSize, A);
	}
	delete []A;
}

// ����������R���л�������
// nN��nMΪ�������ֺ�С�����ֵ���󳤶�
template <class T>
void RadixSort(T R[], int nSize, int nN, int nM)
{
	int i;
	char cFormatN[50], cFormatM[50];
	char **S=new char*[nSize+1];
	char *cM=new char[nM+3]; // ��¼С�����ֶ�Ӧ���ַ���
	if (S==NULL || cM==NULL)
		exit(1);
	// ��������������תΪ�ַ����Է��㴦��
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
	// ��ת������ַ�������R���л�������
	RadixSort(S, nSize);
	// �������Ľ��ת��Ϊ���ִ洢����������R��
	for (i=1; i<=nSize; i++)
	{
		R[i] = (T)atof(S[i]);
		delete []S[i];
	}
	delete []S;
	delete []cM;
}
#endif	// end of _SORTALGORITHMS_H