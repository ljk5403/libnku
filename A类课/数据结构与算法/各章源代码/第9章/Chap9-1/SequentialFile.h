// SequentialFile.h
#ifndef _SEQUENTIALFILE_H
#define _SEQUENTIALFILE_H
#include <fstream>
#include <string>
using namespace std;
// 事务文件记录类模板
template <class T>
class  TransRecord
{
public:
	T record;	// 记录
	char op;	// 操作（'I'：插入，'D'：删除，'U'：修改）
};
// 顺序文件的批量处理
// strFileName为主文件名，strTransFileName为事务文件名，strNewFileName为新的主
// 文件名。这里假设事务文件中的记录已按主关键字排序
template <class T>
void SequentialFileBatchProcess(const string &strFileName, const string &strTransFileName, const string &strNewFileName, T record)
{
	ifstream infile, intransfile;
	ofstream outnewfile;
	TransRecord<T> transrecord;
	infile.open(strFileName.c_str());	// 打开主文件
	intransfile.open(strTransFileName.c_str());	// 打开事务文件
	outnewfile.open(strNewFileName.c_str());	// 打开新的主文件
	infile>>record;	// 从主文件中读取一条记录
	intransfile>>transrecord;	// 从事务文件中读取一条记录
	while (!infile.eof() || !intransfile.eof())	// 若主文件或事务文件中还有记录
	{
		if (infile.eof())	// 若主文件已无记录，则将事务文件中的剩余记录全部插入到新
					// 的主文件中
		{
			do 
			{
				if (transrecord.op != 'I')	// 若不是插入操作，则出错返回
					exit(0);
				outnewfile<<transrecord.record;
				intransfile>>transrecord;
			} while (!intransfile.eof());
			break;
		}
		else if (intransfile.eof())	// 若事务文件已无记录，则将主文件中的剩余记录全部
							// 插入到新的主文件中
		{
			do 
			{
				outnewfile<<record;
				infile>>record;
			} while (!infile.eof());
			break;
		}
		if (record < transrecord.record)// 若主文件记录小于事务文件记录
		{
			// 将主文件记录写入新的主文件中，并从主文件中读取下一条记录
			outnewfile<<record;
			infile>>record;
		}
		else if (record == transrecord.record)	// 若主文件记录等于事务文件记录，应为
										// 删除或修改操作
		{
			if (transrecord.op == 'D')	// 若为删除操作，则不做写文件操作
				;
			else if (transrecord.op == 'U')	// 若为修改操作，则将事务文件记录写到新的
									// 主文件中
				outnewfile<<transrecord.record;
			else
				exit(0);	// 若为其他操作，则出错返回
			// 读取下一条主文件记录和事务文件记录
			infile>>record;
			intransfile>>transrecord;
		}
		else	// 若主文件记录大于事务文件记录，应为插入操作
		{
			if (transrecord.op == 'I')	// 若为插入操作，则将事务文件记录写到新的主文
								// 件中
				outnewfile<<transrecord.record;
			else
				exit(0);	// 若为其他操作，则出错返回
			// 读取下一条事务文件记录
			intransfile>>transrecord;
		}
	}
	outnewfile.close();	// 关闭新的主文件
	intransfile.close();	// 关闭事务文件
	infile.close();	// 关闭主文件
}
#endif	// end of _SEQUENTIALFILE_H
