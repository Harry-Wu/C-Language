/*****************************************************************************
@File name:
@Description:
@	建立CD歌曲信息库
@Author: Harry Wu
@Version: V1.2
@Date: 2017-04-09
@History:
	V1.0: 加上了显示cd信息和添加新cd信息的功能函数
	V1.1: 加上了修改cd信息和备份内存中cd信息的功能函数
	V1.2: 加上了输入的序列号有可能是负数, 或超出范围的判定; 增加了控制台程序的标题
*****************************************************************************/
//TODO: display_cdcollection()函数有很多警告, 有时间优化

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "cs50.h"
#include "mystring.h"  //查找字符的函数
#include "mycdinfo.h"  //cd_database处理函数

#define FILENAME "cd_database.bin"
#define FILENAME_BAK "cd_database.bak"



int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	system("title CD_DATABASE"); //程序标题
	bool keepgoing = true;  //是否继续操作标识符
	create_cdcollection();
	while (keepgoing)
	{
		printf("\nEnter a command or 'q/Q' to quit.");
		printf("\nCommands: 'a'=add record, 'd'=display record(s), 'm'=modify record");
		printf("\n          'n'=number of record(s), 's'=save backup (from memory)\n> ");
		switch (get_char())
		{
			case 'a':
				printf("Add record:\n");
				add_cd(FILENAME);
				break;
			case 'd':
				printf("Display record(s):\n");
				display_cdcollection(FILENAME);
				break;
			case 'm':
				printf("Modify record:\n");
				modify_cd(FILENAME);
				break;
			case 'n':
				printf("Numbers of record(s):\n");
				printf("Database contains %d records\n", number_of_records_in_db(FILENAME));
				break;
			case 's':
				printf("Save backup (from memory):\n");
				backup_cd();
				break;
			case 'q':
			case 'Q':
				printf("Ending...\n");
				keepgoing = false;
				break;
			default:
				printf("Invalid command! Please try again:\n");
				break;
		}

	}
	system("pause");

	return 0;
}
