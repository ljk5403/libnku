// Sort.h
#ifndef	_SORT_H
#define	_SORT_H
// 对R进行插入排序
// CompareFun为函数指针，可以根据传入函数不同按不同关键字比较元素大小
template <class T>
void InsertSort(T R[], int nSize, int (*CompareFun)(T&, T&))
{
	int i, j;
	for (i=1; i<nSize; i++)
	{
		// 若当前待排序元素的值大于或等于已排序序列中最后一个元素的值，则该元
		// 素不需改变位置
		if (CompareFun(R[i+1], R[i])>=0)	// 这里通过调用函数比较元素大小
			continue;
		R[0] = R[i+1];	// 将待排序元素放入监视哨中
		R[i+1] = R[i];
		// 这里通过调用函数比较元素大小
		for (j=i-1; CompareFun(R[0], R[j])<0; j--) 
			R[j+1] = R[j];
		R[j+1] = R[0];
	}
}
#endif	// end of _SORT_H
