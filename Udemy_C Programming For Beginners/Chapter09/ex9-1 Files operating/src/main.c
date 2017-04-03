/*****************************************************************************
@File name:
@Description: 
@	txt文件的打开,关闭,,清空,删除等,也适用于其他文件
@Author: Harry Wu
@Version: V1.0
@Date: 2017-04-02
@History:
	V1.0: 使用了更安全的fopen_s()等函数

*****************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//#include "cs50.h"
#include "main.h"

#define MAXLINE 200
#define FILENAME "Changelog.txt"


void read_file()
{
	FILE *fp;
	errno_t err = fopen_s(&fp, FILENAME, "r");
	char line[MAXLINE];
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

void appending_file()
{
	FILE *fp;
	errno_t err = fopen_s(&fp, FILENAME, "a");
	if (!err && fp != NULL)
	{
		printf("File '%s' is opened for appending.\n", FILENAME);
		fputs("\nHello world", fp);
		fclose(fp);
	}
	else
	{
		printf("Can not open file:%s!\n", FILENAME);
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

int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	appending_file();
	read_file();
	clearfile();
	return 0;
}
