#ifndef __WCHEAD_H__
#define __WCHEAD_H__

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

typedef enum{en_success,en_fail,en_true,en_false,en_nullptr} Status;

class class_Data
{
private:
	int itNumOfChar;			//存储当前文件的字符数
	int	itNumOfWord;			//存储当前文件的单词数
	int itNumOfRow;				//存储当前文件的行数
	string strTmpRowStr;		//临时存储刚从文件读入的一行代码


public:
	int GetNumOfChar();							//获取类中已记录的字符数
	int GetNumOfWord();							//获取类中已记录的单词数
	int GetNumOfRow();							//获取类中已记录的行数
	string GetTmpRowStr();						//获取类中存储的临时行代码字符串
	Status SetTmpRowStr(string InputStr);		//设置类中临时行代码字符串

	class_Data()
	{
		itNumOfChar = 0;
		itNumOfWord = 0;
		itNumOfRow = 0;
	}

};

class class_WordCal : public class_Data
{
private:
	ifstream ifs;						//存储当前打开文件的文件读操作类
	string strFileName;					//存储当前文件名
	string strFilePath;					//存储当前文件的路径

public:
	string GetFileName();							//获取当前正在操作的记录文件名
	string GetFilePath();							//获取当前正在操作的记录文件路径
	Status SetFileName(char *InputFileName);		//设置当前正在操作的记录文件名
	Status SetFilePath(char *InputFilePath);		//设置当前正在操作的记录文件路径
	Status SetIfstream();							//设置打开文件的文件读操作类
	Status GetCharNumFormFile();					//获取当前记录文件中的字符数
	Status GetWordNumFormFile();					//获取当前记录文件中的单词数
	Status GetRowNumFormFile();						//获取当前记录文件中的行数



};















#endif