#ifndef LINEARLIST
#define LINEARLIST
template<class T>
class LinearList
{
	public:
		LinearList(int LLMaxSize);		//���캯���������ձ�
		~LinearList();					//����������ɾ����
		LinearList<T>& Insert(int k,const T& x); 
						//�ڵ�k��λ�ò���Ԫ��x�����ز��������Ա�
		bool IsEmpty() const;		
						//�жϱ��Ƿ�Ϊ�գ���շ���true����ǿշ���false
		int GetLength() const;			//���ر�������Ԫ�صĸ���
		bool GetData(int k,T& x);		
						//�����е�k��Ԫ�ر��浽x�У��������򷵻�false
		bool ModifyData(int k,const T& x);
						//�����е�k��Ԫ���޸�Ϊx���������򷵻�false
		int Find(const T& x);		//����x�ڱ��е�λ�ã����x���ڱ��з���0
		LinearList<T>& DeleteByIndex(const int k, T& x);
				//ɾ�����е�k��Ԫ�أ����������浽x�У�����ɾ��������Ա�
		LinearList<T>& DeleteByKey(const T& x,T& y);
				//ɾ�����йؼ���ΪxԪ�أ�����ɾ��������Ա�
		void OutPut(ostream& out) const;
				//�����Ա�ŵ������out�����
	private:
		int length;			//��ǰ����Ԫ�ظ���
		int MaxSize;			//���Ա������Ԫ�ظ���
		T *element;			//һά��̬����
};
template<class T>
LinearList<T>::LinearList(int LLMaxSize)
{
	MaxSize=LLMaxSize;
	element=new T[LLMaxSize];
	length=0;
}
//ʵ����������
template<class T>
LinearList<T>::~LinearList()
{
	delete []element;
}
//ʵ�ֲ���������Ԫ��
template<class T>
LinearList<T>& LinearList<T>::Insert(int k,const T& x)
{
	if (k<1||k>length+1) 
		cout<<"Ԫ���±�Խ�磬���Ԫ��ʧ��";
	else
		if (length==MaxSize)
			cout<<"�˱��������޷������Ԫ��";
		else
		{
			for(int i=length;i>k-1;i--)
				element[i]=element[i-1];		//�ƶ�Ԫ��
			element[k-1]=x;				//����Ԫ��
			length++;						//��+1
		}
	return *this;
}
//ʵ���ж��Ƿ�Ϊ�ձ�
template<class T>
bool LinearList<T>::IsEmpty() const
{
	return length==0;
}
//ʵ����ǰ��ĳ���
template<class T>
int LinearList<T>::GetLength() const
{
	return length;
}
//ʵ�ְ�λ��ȡԪ��
template<class T>
bool  LinearList<T>::GetData(int k,T& x)
{
	if (k<1 || k>length) 
		return false;
	else
	{
		x=element[k-1];
		return true;
	}
}
//ʵ�ְ�λ���޸�Ԫ��
template<class T>
bool  LinearList<T>::ModifyData(int k,const T& x)
{
	if (k<1 || k>length) 
		return false;
	else
	{
		element[k-1]=x;
		return true;
	}
}
//ʵ�ְ��ؼ��ֲ���
template<class T>
int LinearList<T>::Find(const T& x)
{
	for (int i=0; i<length; i++)
		if(element[i]==x)
			return i+1;
	return 0;
}
//ʵ�ְ�λ��ɾ��
template<class T>
LinearList<T>& LinearList<T>::DeleteByIndex(int k, T& x)
{
	if (GetData(k,x))
	{
		for (int i=k-1;i<length-1;i++)
			element[i]=element[i+1];		//�ƶ�Ԫ��
		length--;							//��-1
	}
	else 
		cout<<"Ԫ���±�Խ�磬ɾ��ʧ��";
	return *this;
}
//ʵ�ְ��ؼ���ɾ��
template<class T>
LinearList<T>& LinearList<T>::DeleteByKey(const T& x,T& y)
{
	int index=Find(x);//�õ�Ҫɾ��Ԫ�ص�λ��
	if (index!=0)
		return DeleteByIndex(index, y);
	else
	{
		cout<<"û�д�Ԫ�أ�ɾ��ʧ��";
		return *this;
	}
}
//ʵ��˳�������
template<class T>
void LinearList<T>:: OutPut(ostream& out) const
{
	for(int i=0;i<length;i++)
		out<<element[i]<<endl;
}
//���ز��������<<
template<class T>
ostream& operator<<(ostream& out,const LinearList<T>& x)
{
	x.OutPut(out);
	return out;
}
#endif
