//permutation.h
#ifndef PERMUTATION
#define PERMUTATION
class permutation
{
public:
	permutation(int n);
	void compute(int count);		//��������n����Ȼ�������в����
	~permutation();
private:
	int m_n;				//��Ȼ��n��
	int *m_p;				//������н��
	int *m_used;			//���ʹ�ù��ı��
};
#endif