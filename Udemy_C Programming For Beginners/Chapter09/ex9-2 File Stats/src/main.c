/*****************************************************************************
@File name:
@Description: 
@	�ļ�״̬��ѯ
@Author: Harry Wu
@Version: V1.0
@Date: 2017-04-02
@History:
	V1.0: ����ļ�����������

*****************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
//#include "cs50.h"
//#include "main.h"

#define MAXLINE 200
#define FILENAME "changelog.txt"
#define FILENAME2 "sonnet.txt"


void read_file()
{
	FILE *fp;
	errno_t err = fopen_s(&fp, FILENAME, "r");
	char line[MAXLINE];
	if (!err && fp != NULL)
	{
		printf("File '%s' is opened.\n", FILENAME);
		printf("-----------------------------------------\n");
		//int i = sizeof(line);  //����ռ���ٸ��ֽ�byte
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

//����ļ�����
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

//ɾ���ļ�
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
	char line[MAXLINE];
	int numlines = 0;
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

int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	appending_file(FILENAME);
	read_file();
	clearfile();

	countline_file(FILENAME2);

	return 0;
}
