#include"WChead.h"


//class_Data 方法集
int class_Data::GetNumOfChar()		//获取类中已记录的字符数
{
	return itNumOfChar;
}

int class_Data::GetNumOfWord()		//获取类中已记录的单词数
{
	return itNumOfWord;
}

int class_Data::GetNumOfRow()		//获取类中已记录的行数
{
	return itNumOfRow;
}

Status class_Data::SetTmpRowStr(string InputStr)		//设置类中临时行代码字符串
{
	strTmpRowStr = InputStr;
	return en_success;
}

string class_Data::GetTmpRowStr()	//获取类中存储的临时行代码字符串
{
	return strTmpRowStr;
}



//class_WordCal 方法集
string class_WordCal::GetFileName()				//获取当前正在操作的记录文件名
{
	return strFileName;
}

string class_WordCal::GetFilePath()				//获取当前正在操作的记录文件路径
{
	return strFilePath;
}

Status class_WordCal::SetFileName(char *InputFileName) 		//设置当前正在操作的记录文件名
{
	if (!InputFileName)
	{
		return en_nullptr;
	}
	//可能需添加检查文件名是否正确的功能代码
	strFileName = InputFileName;
	return en_success;
}

Status class_WordCal::SetFilePath(char *InputFilePath)		//设置当前正在操作的记录文件路径
{
	if (!InputFilePath)
	{
		return en_nullptr;
	}
	//可能需添加检查文件路径是否正确的功能代码
	strFilePath = InputFilePath;
	return en_success;
}

Status class_WordCal::SetIfstream()								//设置打开文件的文件读操作类
{
	ifs.open(GetFileName().c_str);
	if (!ifs)
	{
		cout << "File "<< GetFileName().c_str  << " isn't existed." << endl;
		return en_nullptr;
	}
	return en_success;
}

Status class_WordCal::GetCharNumFormFile()						//获取当前记录文件中的字符数
{
	//待加入功能代码
}

Status class_WordCal::GetWordNumFormFile()						//获取当前记录文件中的单词数
{
	//待加入功能代码
}
Status class_WordCal::GetRowNumFormFile()						//获取当前记录文件中的行数
{
	//待加入功能代码
}
