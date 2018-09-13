#include"WChead.h"


//class_Data 方法集
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

void class_WordCal::Option(int argc, char *argv[])		////功能选择函数
{
	int i;
	for (i = 1; i < argc; ++i)
	{
		string s = argv[i];
		if (s == "-l")
		{
			bOpLine = true;
		}
		else if (s == "-w")
		{
			bOpWord = true;
		}
		else if (s == "-c")
		{
			bOpChar = true;
		}
		else if (s == "-s")
		{
			bOpRecursion = true;
		}
		else if (s == "-a")
		{
			bOpAll = bOpChar = bOpWord = bOpLine = true;
		}
		else
		{
			vStrFileName.push_back(s);
		}
	}
}

int class_WordCal::getword(FILE *fp)
{
	if (!fp || feof(fp))
	{
		return 0;
	}
	int c;
	int word = 0;
	while ((c = getc(fp)) != EOF)
	{
		if (isalpha(c))
		{
			iNumOfWord++;
			break;
		}
		iNumOfChar++;        
		if ((c) == '\n')
		{
			iNumOfLine++;
		}

	}
	while (c != EOF)
	{
		iNumOfChar++;
		if ((c) == '\n')
		{
			iNumOfLine++;
		}
		if (!isalpha(c))
		{
			break;
		}
		c = getc(fp);
	}

	return c != EOF;
}

void class_WordCal::Display(int Index)
{
	if (bOpChar)
	{
		cout << "The Num of chars: " << iNumOfChar << "  " << vStrFileName[Index] << endl;
	}
	if (bOpWord)
	{
		cout << "The Num of words: " << iNumOfWord << "  " << vStrFileName[Index] << endl;
	}
	if (bOpLine)
	{
		cout << "The Num of Lines: " << iNumOfLine << "  " << vStrFileName[Index] << endl;
	}
	if (bOpAll)
	{
		cout << "all function continue..." << endl;
	}

}

Status class_WordCal::SetIfstream()								//设置打开文件的文件读操作类
{
	const char *FileName = vStrFileName[iFileNameIndex].c_str();
	ifs.open(FileName);
	if (!ifs)
	{
		cout << "File "<< FileName << " isn't existed." << endl;
		return en_nullptr;
	}
	return en_success;
}

Status class_WordCal::CountFormFile(int Index)				//获取当前记录文件中的字符数
{
	if (Index < 0 ||Index >= vStrFileName.size())
	{
		return en_fail;
	}
	const char *FileName = vStrFileName[Index].c_str();
	FILE *fp = fopen(FileName, "r");

	if (!fp)
	{
		cout << "Can't open the file " << FileName << endl;
		return en_fail;
	}

	iNumOfChar = iNumOfLine = iNumOfWord = 0;
	while (getword(fp));
	fclose(fp);
	return en_success;
}

Status class_WordCal::CountFormFileAll(int Index)				//对vector<string>中第Index个文件名对应文件进行高级代码统计(-a)
{
	if (Index < 0 || Index >= vStrFileName.size())
	{
		return en_fail;
	}
	allStatus.bComm = allStatus.bCommM = allStatus.bEffective = allStatus.bEmpty = false;	//高级统计状态机初始化


}

void class_WordCal::workMain(int argc, char *argv[])
{
	Option(argc, argv);
	if (bOpRecursion != true)
	{
		int i;
		for (i = 0; i < vStrFileName.size(); ++i)
		{
			CountFormFile(i);
			Display(i);
			cout << endl;
		}
	}
	else
	{
		cout << "-s continue..." << endl;
	}

}

