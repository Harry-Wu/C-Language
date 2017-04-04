/*****************************************************************************
@File name:
@Description:
@	打开二进制文件并显示状态
@Author: Harry Wu
@Version: V1.0
@Date: 2017-04-04
@History:
	V1.0: 打开二进制文件并显示状态

*****************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "cs50.h"
#include "mystringutils.h"  //查找字符的函数

//#define MAXSTRLEN 200
#define FILENAME "changelog.txt"
#define FILENAME2 "sonnet.txt"

//二进制格式读取文件信息
void read_binfile(char *filename)
{
	FILE *fp;
	errno_t err = fopen_s(&fp, filename, "rb");  //"rb"--二进制方式打开文件
	char line[MAXSTRLEN];  //用于临时存放从文件获取到的一行字符串
	int numlines = 0;  //保存文件有多少行文字
	long numbytes = 0;  //保存文件有多少个字节
	if (!err && fp != NULL)
	{
		printf("File '%s' is opened.\n", filename);
		printf("-----------------------------------------\n");
		fseek(fp, 0, SEEK_END);  //用于二进制方式打开的文件,移动文件读写指针位置到文件结尾
		numbytes = ftell(fp); //到文件位置指针当前位置相对于文件首的偏移字节数
		rewind(fp);  //将文件指针重新指向一个流的开头
		char *buffer = (char *)malloc(numbytes);
		long items_read = fread(buffer, 1, numbytes, fp);		//查询下读到多少个元素
		//注意如果用fgets去计算有多少行的时候，文件指针fp一定要移回到文件开头处
		//另一种方法是遍历buffer[],查询'\n'的个数就知道有多少行了
		rewind(fp);
		while (fgets(line, sizeof(line), fp) != 0)
		{
			numlines++;  //只要读完一行就+1
		}
		fclose(fp);
		printf("number of lines was %d with %d chars (%d items read).\n", numlines, numbytes, items_read);
		free(buffer);
	}
	else
	{
		printf("Can not open file:%s!\n", filename);
	}
	printf("The fopen return address is %p\n", fp);
	printf("\n-----------------------------------------\n");
}


int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	//char *buffer;
	//appending_file(FILENAME);
	//read_file();
	//clearfile();

	//countline_file(FILENAME2);
	///printf("Please input word you want to search:\n");
	//buffer = get_string();
	read_binfile(FILENAME2);

	getchar();

	return 0;
}
