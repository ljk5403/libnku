#ifndef LINEARSTRING
#define LINEARSTRING
class LinearString
{
	public:
		LinearString(int LSMaxSize=100);		//���캯���������մ�
		LinearString(const char *str);			//���ַ�������str�������Ĺ��캯��
		LinearString(const LinearString& str);	//�������캯��
		~LinearString();						//��������
		bool IsEmpty() const;				
		int Length() const;		
		bool StrCat(const LinearString& str);			//����t���ӵ������γ��´�
		bool LinearString::SubStr(int pos,int len,LinearString &sub);//��ӵ�pos���ַ��𳤶�Ϊlen���Ӵ��ŵ�sub��
		bool operator==(const LinearString& str);		//�жϴ��Ƿ���str���
		int Index(const LinearString& str);				//���str�ǵ��Ӵ����������ڴ��е�һ�γ��ֵ�λ�ã������Ӵ��򷵻�0
		int IndexFL(const LinearString& str);			//��βƥ�䷨
		int IndexKMP(const LinearString& str);			//KMP��βƥ�䷨
		int At(LinearString& T);//ͳ���Ӵ����ֵĸ�����ʵϰ2��
		void OutPut(ostream& out) const;				//����ַ���
		friend void MakeNext(const LinearString &t,int *next);		//KMP���ĵõ�next����ĺ���
private:
		int length;
		int MaxSize;
		char *string;  //һά����
};
//ʵ�ִ����մ��Ĺ��캯��
LinearString::LinearString(int LSMaxSize)
{
	MaxSize=LSMaxSize;
	string=new char[LSMaxSize];
	length=0;                    
}
//ʵ�ֹ��캯��
LinearString::LinearString(const char* str)
{
	int len=0;
	while(str[len])len++;		//�����ַ�������str�ĳ���
	MaxSize=len;
	length=len;
	string=new char[len];
	for(int i=0;i<len;i++)
		string[i]=str[i];
}
//ʵ�ֿ������캯��
LinearString::LinearString(const LinearString& str)
{
	MaxSize=str.MaxSize;
	length=str.length;
	string=new char[MaxSize];
	for(int i=0;i<length;i++)
		string[i]=str.string[i];
}
//ʵ����������
LinearString::~LinearString()
{
	delete []string;
}
//ʵ���ж��Ƿ�Ϊ�մ�
bool LinearString::IsEmpty() const
{
	return length==0;
}
//ʵ���󴮵ĳ���
int LinearString::Length() const
{
	return length;
}
//ʵ�ֽ���t���ӵ������γ��´�
bool LinearString::StrCat(const LinearString& str)
{
	if (MaxSize<length+str.length)
		return false;
	for (int i=0;i<str.length;i++)
		string[length+i]=str.string[i];
	length=length+str.length;
	return true;
}
//ʵ����ӵ�pos���ַ��𳤶�Ϊlen���Ӵ�
bool LinearString::SubStr(int pos,int len,LinearString &sub)
{
	if (pos<1||pos>length||len<0||len>(length-pos+1)) //�����Ƿ�
		return false;
	if (len>sub.MaxSize)						//�Ӵ����ȳ���sub������󳤶�
		return false;
	sub.length=len;								//�����Ӵ�����  
	for (int i=0; i<len; i++)
		sub.string[i]=string[pos-1+i] ;			//����ַ����Ƶõ��Ӵ�
	return true;
}
//ʵ���жϴ��Ƿ���str���	
bool LinearString::operator==(const LinearString& str)
{
	if(length!=str.length)
		return false;
	for(int i=0;i<length;i++)
		if (string[i]!=str.string[i])
			return false;
	return true;
}
//���str�ǵ��Ӵ����������ڴ��е�һ�γ��ֵ�λ�ã������Ӵ��򷵻�0
int LinearString::Index(const LinearString& str)
{
	LinearString sub(MaxSize);				//����һ����ʱ��
	for (int i=1;i<=length-str.length+1;i++)//ɨ����ܴ����Ӵ�������
	{
		if(!SubStr(i,str.length,sub))		//ȥ������str�ĳ���һ�µ��Ӵ�
			return 0;						//�����в�������str�ĳ���һ�µ��Ӵ�
		if(sub==str)return i;				//�ҵ��Ӵ��������Ӵ��������е�λ��
	}
	return 0;
}

//���str�ǵ��Ӵ����������ڴ��е�һ�γ��ֵ�λ�ã������Ӵ��򷵻�0
int LinearString::IndexFL(const LinearString& str)
{
	int i=0,j;
	while(length-i>=str.length)		//��������ƥ��Ĵ�
	{	
		for (j=0;j<=str.length/2;j++)
		{
			if(string[i+j]!=str.string[j])		//���ַ���ƥ��
				break;
			if(string[i+str.length-1-j]!=str.string[str.length-1-j]) //β�ַ���ƥ��
				break;
		}
		if (j==str.length/2+1)
			return i+1;							//ƥ�䣬����ģʽ����Ŀ�괮�е�λ��
		i=i+1;									//��ƥ�䣬��������Ŀ�괮ƥ�����ʼ��
	}
  return 0;
}
//ʵ��KMLƥ�䷨
int LinearString::IndexKMP(const LinearString& str)
{
	int  i=0,j=0 ;      /*��ʼƥ��λ������ */
	int *next=new int[length];
	MakeNext(str,next);
	while ((i<length)&&(j<str.length)) 
		if ((j==-1)||(string[i]==str.string[j]))  //�ַ���ȼ�������ȥ
		{  
			i++; 
			j++; 
		}
		else j=next[j];							//��j�ƶ���next[j]���¿�ʼ��һ�ֱȽ�
	if (j>=str.length)
		return(i-str.length+1);	//�ҵ�һ�� 
	else  
		return 0;     
}
int LinearString::At(LinearString& T)//ͳ���Ӵ����ֵĸ�����ʵϰ2��
{
	LinearString S1;
	int num=0,index;
	index=Index(T);
	if (index==0)				//�������Ӵ�
		return 0;
	num++;
	SubStr(index+T.length,length-(index+T.length)+1,S1);//����û�в��ҵ��Ӵ�����S1
	return num+S1.At(T);
}
//ʵ��˳�򴮵����
void LinearString:: OutPut(ostream& out) const
{
	for(int i=0;i<length;i++)
		out<<string[i];
}
//���ز��������<<
ostream& operator<<(ostream& out,const LinearString& x)
{
	x.OutPut(out);
	return out;
}
// KMPģʽƥ�䷨��next����*/
void MakeNext(const LinearString &t,int *next)
{     
      int j=0,k=-1;  
      next[0]=-1;
	  while(j<t.length)
	  {
		  while(k>=0&&t.string[j]!=t.string[k])
			  k=next[k];
		  j++;k++;
		  next[j]=k;
	  }
}
#endif