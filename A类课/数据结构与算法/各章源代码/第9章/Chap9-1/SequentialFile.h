// SequentialFile.h
#ifndef _SEQUENTIALFILE_H
#define _SEQUENTIALFILE_H
#include <fstream>
#include <string>
using namespace std;
// �����ļ���¼��ģ��
template <class T>
class  TransRecord
{
public:
	T record;	// ��¼
	char op;	// ������'I'�����룬'D'��ɾ����'U'���޸ģ�
};
// ˳���ļ�����������
// strFileNameΪ���ļ�����strTransFileNameΪ�����ļ�����strNewFileNameΪ�µ���
// �ļ�����������������ļ��еļ�¼�Ѱ����ؼ�������
template <class T>
void SequentialFileBatchProcess(const string &strFileName, const string &strTransFileName, const string &strNewFileName, T record)
{
	ifstream infile, intransfile;
	ofstream outnewfile;
	TransRecord<T> transrecord;
	infile.open(strFileName.c_str());	// �����ļ�
	intransfile.open(strTransFileName.c_str());	// �������ļ�
	outnewfile.open(strNewFileName.c_str());	// ���µ����ļ�
	infile>>record;	// �����ļ��ж�ȡһ����¼
	intransfile>>transrecord;	// �������ļ��ж�ȡһ����¼
	while (!infile.eof() || !intransfile.eof())	// �����ļ��������ļ��л��м�¼
	{
		if (infile.eof())	// �����ļ����޼�¼���������ļ��е�ʣ���¼ȫ�����뵽��
					// �����ļ���
		{
			do 
			{
				if (transrecord.op != 'I')	// �����ǲ���������������
					exit(0);
				outnewfile<<transrecord.record;
				intransfile>>transrecord;
			} while (!intransfile.eof());
			break;
		}
		else if (intransfile.eof())	// �������ļ����޼�¼�������ļ��е�ʣ���¼ȫ��
							// ���뵽�µ����ļ���
		{
			do 
			{
				outnewfile<<record;
				infile>>record;
			} while (!infile.eof());
			break;
		}
		if (record < transrecord.record)// �����ļ���¼С�������ļ���¼
		{
			// �����ļ���¼д���µ����ļ��У��������ļ��ж�ȡ��һ����¼
			outnewfile<<record;
			infile>>record;
		}
		else if (record == transrecord.record)	// �����ļ���¼���������ļ���¼��ӦΪ
										// ɾ�����޸Ĳ���
		{
			if (transrecord.op == 'D')	// ��Ϊɾ������������д�ļ�����
				;
			else if (transrecord.op == 'U')	// ��Ϊ�޸Ĳ������������ļ���¼д���µ�
									// ���ļ���
				outnewfile<<transrecord.record;
			else
				exit(0);	// ��Ϊ�����������������
			// ��ȡ��һ�����ļ���¼�������ļ���¼
			infile>>record;
			intransfile>>transrecord;
		}
		else	// �����ļ���¼���������ļ���¼��ӦΪ�������
		{
			if (transrecord.op == 'I')	// ��Ϊ����������������ļ���¼д���µ�����
								// ����
				outnewfile<<transrecord.record;
			else
				exit(0);	// ��Ϊ�����������������
			// ��ȡ��һ�������ļ���¼
			intransfile>>transrecord;
		}
	}
	outnewfile.close();	// �ر��µ����ļ�
	intransfile.close();	// �ر������ļ�
	infile.close();	// �ر����ļ�
}
#endif	// end of _SEQUENTIALFILE_H
