/* Person.h��Լɪ������Ԫ�ؽ����*/
#ifndef PERSON
#define PERSON
class Person
{
	public:
		void SetPerson(int no,int password);		//����㸳ֵ��
		int GetNo(){return No;}						//ȡ���
		int	GetPassWord(){return PassWord;}			//ȡ����
		void OutPutPerson(ostream& out) const;		//����������
	private:
		int No;
		int PassWord;
};
//ʵ�ָ���㸳ֵ����
void Person::SetPerson(int no,int password)
{
	No=no;
	PassWord=password;
}
//ʵ�����������ݺ���
void Person::OutPutPerson(ostream& out) const
{
	out<<"��Ȧ�˱�ţ�"<<No<<endl;
	out<<"��Ȧ�����룺"<<PassWord<<endl;
}
//���ز��������<<
ostream& operator<<(ostream& out,const Person& x)
{
	x.OutPutPerson(out);
	return out;
}
#endif
