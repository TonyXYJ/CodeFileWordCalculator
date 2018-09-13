#ifndef __WCHEAD_H__
#define __WCHEAD_H__
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<stdarg.h>
using namespace std;

typedef enum{en_success,en_fail,en_true,en_false,en_nullptr} Status;
typedef struct {
	bool bEffective;
	bool bCommM;
	bool bComm;
	bool bEmpty;
}AllStatus;


class class_Data
{
public:
	int iNumOfChar;				//存储当前文件的字符数
	int	iNumOfWord;				//存储当前文件的单词数
	int iNumOfLine;				//存储当前文件的行数
	int iNumOfEffectiveLine;	//存储当前文件的有效代码行数
	int iNumOfEmptyLine;		//存储当前文件的空行数
	int iNumOfCommentLine;		//存储当前文件的注释行数
	string strTmpRowStr;		//临时存储刚从文件读入的一行代码
	AllStatus allStatus;		//高级统计状态机

	string GetTmpRowStr();						//获取类中存储的临时行代码字符串
	Status SetTmpRowStr(string InputStr);		//设置类中临时行代码字符串
	
	class_Data()
	{
		iNumOfChar = 0;
		iNumOfWord = 0;
		iNumOfLine = 0;
	}

};

class class_WordCal : public class_Data
{
public:
	bool bOpChar;						//字符统计输出开关						
	bool bOpLine;						//行数统计输出开关
	bool bOpWord;						//词组统计输出开关
	bool bOpRecursion;					//递归统计开关
	bool bOpAll;						//更复杂数据统计开关
	int iFileNameIndex;					//存储文件名的stringVector中带操作的文件名下标
	ifstream ifs;						//存储当前打开文件的文件读操作类
	vector<string> vStrFileName;		//存储当前文件名的stringVector
	string strFilePath;					//存储当前文件的路径


	void Option(int argc, char *argv[]);			//功能选择函数
	void Display(int Index);						//统计输出函数
	int getword(FILE *fp);							//从输入流中获取下一个词组，读取至文件结尾或异常情况出现时返回0，返回1则为其他情况
	Status SetIfstream();							//设置打开文件的文件读操作类
	Status CountFormFile(int Index);				//对vector<string>中第Index个文件名对应文件进行代码统计(-l -w -c)
	Status CountFormFileAll(int Index);				//对vector<string>中第Index个文件名对应文件进行高级代码统计(-a)

	void workMain(int argc, char *argv[]);			//功能主函数

};















#endif