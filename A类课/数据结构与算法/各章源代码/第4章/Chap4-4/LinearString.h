#ifndef LINEARSTRING
#define LINEARSTRING
class LinearString
{
	public:
		LinearString(int LSMaxSize=100);		//构造函数，创建空串
		LinearString(const char *str);			//由字符串常量str创建串的构造函数
		LinearString(const LinearString& str);	//拷贝构造函数
		~LinearString();						//析构函数
		bool IsEmpty() const;				
		int Length() const;		
		bool StrCat(const LinearString& str);			//将串t连接到串后形成新串
		bool LinearString::SubStr(int pos,int len,LinearString &sub);//求从第pos个字符起长度为len的子串放到sub中
		bool operator==(const LinearString& str);		//判断串是否与str相等
		int Index(const LinearString& str);				//如果str是的子串，返回它在串中第一次出现的位置，不是子串则返回0
		int IndexFL(const LinearString& str);			//首尾匹配法
		int IndexKMP(const LinearString& str);			//KMP首尾匹配法
		int At(LinearString& T);//统计子串出现的个数，实习2用
		void OutPut(ostream& out) const;				//输出字符串
		friend void MakeNext(const LinearString &t,int *next);		//KMP法的得到next数组的函数
private:
		int length;
		int MaxSize;
		char *string;  //一维数组
};
//实现创建空串的构造函数
LinearString::LinearString(int LSMaxSize)
{
	MaxSize=LSMaxSize;
	string=new char[LSMaxSize];
	length=0;                    
}
//实现构造函数
LinearString::LinearString(const char* str)
{
	int len=0;
	while(str[len])len++;		//计算字符串常量str的长度
	MaxSize=len;
	length=len;
	string=new char[len];
	for(int i=0;i<len;i++)
		string[i]=str[i];
}
//实现拷贝构造函数
LinearString::LinearString(const LinearString& str)
{
	MaxSize=str.MaxSize;
	length=str.length;
	string=new char[MaxSize];
	for(int i=0;i<length;i++)
		string[i]=str.string[i];
}
//实现析构函数
LinearString::~LinearString()
{
	delete []string;
}
//实现判断是否为空串
bool LinearString::IsEmpty() const
{
	return length==0;
}
//实现求串的长度
int LinearString::Length() const
{
	return length;
}
//实现将串t连接到串后形成新串
bool LinearString::StrCat(const LinearString& str)
{
	if (MaxSize<length+str.length)
		return false;
	for (int i=0;i<str.length;i++)
		string[length+i]=str.string[i];
	length=length+str.length;
	return true;
}
//实现求从第pos个字符起长度为len的子串
bool LinearString::SubStr(int pos,int len,LinearString &sub)
{
	if (pos<1||pos>length||len<0||len>(length-pos+1)) //参数非法
		return false;
	if (len>sub.MaxSize)						//子串长度超出sub串的最大长度
		return false;
	sub.length=len;								//计算子串长度  
	for (int i=0; i<len; i++)
		sub.string[i]=string[pos-1+i] ;			//逐个字符复制得到子串
	return true;
}
//实现判断串是否与str相等	
bool LinearString::operator==(const LinearString& str)
{
	if(length!=str.length)
		return false;
	for(int i=0;i<length;i++)
		if (string[i]!=str.string[i])
			return false;
	return true;
}
//如果str是的子串，返回它在串中第一次出现的位置，不是子串则返回0
int LinearString::Index(const LinearString& str)
{
	LinearString sub(MaxSize);				//创建一个临时串
	for (int i=1;i<=length-str.length+1;i++)//扫描可能存在子串的区域
	{
		if(!SubStr(i,str.length,sub))		//去长度与str的长度一致的子串
			return 0;						//主串中不存在与str的长度一致的子串
		if(sub==str)return i;				//找到子串，返回子串在主串中的位置
	}
	return 0;
}

//如果str是的子串，返回它在串中第一次出现的位置，不是子串则返回0
int LinearString::IndexFL(const LinearString& str)
{
	int i=0,j;
	while(length-i>=str.length)		//还可能有匹配的串
	{	
		for (j=0;j<=str.length/2;j++)
		{
			if(string[i+j]!=str.string[j])		//首字符不匹配
				break;
			if(string[i+str.length-1-j]!=str.string[str.length-1-j]) //尾字符不匹配
				break;
		}
		if (j==str.length/2+1)
			return i+1;							//匹配，返回模式串在目标串中的位置
		i=i+1;									//不匹配，重新设置目标串匹配的起始点
	}
  return 0;
}
//实现KML匹配法
int LinearString::IndexKMP(const LinearString& str)
{
	int  i=0,j=0 ;      /*初始匹配位置设置 */
	int *next=new int[length];
	MakeNext(str,next);
	while ((i<length)&&(j<str.length)) 
		if ((j==-1)||(string[i]==str.string[j]))  //字符相等继续比下去
		{  
			i++; 
			j++; 
		}
		else j=next[j];							//将j移动到next[j]重新开始下一轮比较
	if (j>=str.length)
		return(i-str.length+1);	//找到一个 
	else  
		return 0;     
}
int LinearString::At(LinearString& T)//统计子串出现的个数，实习2用
{
	LinearString S1;
	int num=0,index;
	index=Index(T);
	if (index==0)				//不存在子串
		return 0;
	num++;
	SubStr(index+T.length,length-(index+T.length)+1,S1);//将还没有查找的子串放入S1
	return num+S1.At(T);
}
//实现顺序串的输出
void LinearString:: OutPut(ostream& out) const
{
	for(int i=0;i<length;i++)
		out<<string[i];
}
//重载插入运算符<<
ostream& operator<<(ostream& out,const LinearString& x)
{
	x.OutPut(out);
	return out;
}
// KMP模式匹配法求next数组*/
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