/*****************************************************************************
@File name:
@Description:
@	查找text文件中的字符串
@Author: Harry Wu
@Version: V1.0
@Date: 2017-04-04
@History:
	V1.0: 查找text文件中的字符串在哪一行

*****************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "cs50.h"
#include "mystringutils.h"  //查找字符的函数

//#define MAXSTRLEN 200
#define FILENAME "changelog.txt"
#define FILENAME2 "sonnet.txt"


void read_file()
{
	FILE *fp;
	errno_t err = fopen_s(&fp, FILENAME, "r");
	char line[MAXSTRLEN];
	if (!err && fp != NULL)
	{
		printf("File '%s' is opened.\n", FILENAME);
		printf("-----------------------------------------\n");
		//int i = sizeof(line);  //计算占多少个字节byte
		while (fgets(line, sizeof(line), fp) != 0)
		{
			fputs(line, stdout);
		}
		printf("\n-----------------------------------------\n");
		fclose(fp);
	}
	else
	{
		printf("Can not open file:%s!\n", FILENAME);
	}
	printf("\nThe fopen return value is %p\n", fp);
}

void appending_file(char *filename)
{
	FILE *fp;
	errno_t err = fopen_s(&fp, filename, "a");
	if (!err && fp != NULL)
	{
		printf("File '%s' is opened for appending.\n", filename);
		fputs("\nHello world", fp);
		fclose(fp);
	}
	else
	{
		printf("Can not open file:%s!\n", filename);
	}
	printf("The fopen return value is %p\n", fp);
}

//清空文件内容
void clearfile()
{
	FILE *fp;
	errno_t err = fopen_s(&fp, FILENAME, "w");
	if (!err && fp != NULL)
	{
		printf("%s file cleared.\n", FILENAME);
		fclose(fp);
	}
	else
		printf("Unable to clear the file: %s.\n", FILENAME);
}

//删除文件
void deletefile()
{
	if (remove(FILENAME) == 0)
		printf("%s file deleted.\n", FILENAME);
	else
		printf("Unable to delete the file: %s.\n", FILENAME);
}

void countline_file(char *filename)
{
	FILE *fp;
	errno_t err = fopen_s(&fp, filename, "r");
	char line[MAXSTRLEN];
	int numlines = 0;  //保存文件有多少行
	if (!err && fp != NULL)
	{
		printf("File '%s' is opened, will count how many lines.\n", FILENAME);
		printf("-----------------------------------------\n");
		while (fgets(line, sizeof(line), fp) != 0)
		{
			fputs(line, stdout);
			numlines++;
		}
		printf("\n-----------------------------------------\n");
		fclose(fp);
		printf("File '%s' contains %d lines of text.\n", filename, numlines);
	}
	else
	{
		printf("Can not open file:%s!\n", filename);
	}
}

void search_str_file(char *filename, char *searchstr)
{
	FILE *fp;
	errno_t err = fopen_s(&fp, filename, "r");
	char line[MAXSTRLEN]; //用于临时存放从文件获取到的一行字符串
	int numlines = 0;  //保存文件有多少行文字
	bool isFound = false; //标记是否找到单词

	if (!err && fp != NULL)
	{
		printf("File '%s' is opened, will search for word.\n", FILENAME);
		//printf("-----------------------------------------\n");
		while (fgets(line, sizeof(line), fp) != 0)
		{
			//fputs(line, stdout);
			numlines++;  //只要读完一行就+1
			if (search_str(line, searchstr) >= 0) //如果没找到就是-1
			{
				isFound = true;
				printf("'%s' was found in #%d lines within file '%s'.\n", searchstr, numlines, filename);
			}
		}
		//循环结束后，查询是否有找到单词，如果没有执行下面的语句
		if (!isFound)
		{
			printf("Can not find '%s' with file:'%s'!\n", searchstr, filename);
		}
		fclose(fp);
	}
	else
	{
		printf("Can not open file:'%s'!\n", filename);
	}

}

int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	char *buffer;
	appending_file(FILENAME);
	read_file();
	clearfile();

	countline_file(FILENAME2);
	printf("Please input word you want to search:\n");
	buffer = get_string();
	search_str_file(FILENAME2, buffer);

	return 0;
}
