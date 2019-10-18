//permutation.h
#ifndef PERMUTATION
#define PERMUTATION
class permutation
{
public:
	permutation(int n);
	void compute(int count);		//计算所有n个自然数的排列并输出
	~permutation();
private:
	int m_n;				//自然数n；
	int *m_p;				//存放排列结果
	int *m_used;			//存放使用过的标记
};
#endif