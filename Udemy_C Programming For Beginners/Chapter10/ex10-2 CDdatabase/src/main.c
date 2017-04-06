/*****************************************************************************
@File name:
@Description:
@	建立CD歌曲信息库
@Author: Harry Wu
@Version: V1.0
@Date: 2017-04-06
@History:
	V1.0: 加上了显示cd信息和添加新cd信息的功能函数

*****************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "cs50.h"
#include "mystring.h"  //查找字符的函数
#include "mycdinfo.h"  //cd_database处理函数

#define FILENAME "cd_database.bin"
#define FILENAME_BAK "cd_database.bak"



int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
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
				//modify_cd(FILENAME);
				break;
			case 'n':
				printf("Numbers of record(s):\n");
				printf("Database contains %d records\n", number_of_records_in_db(FILENAME));
				break;
			case 's':
				printf("Save backup (from memory):\n");
				//backup_cd(FILENAME_BAK);
				break;
			case 'q':
			case 'Q':
				printf("Ending...\n");
				keepgoing = false;
				break;
			default:
				printf("Invalid command! Please try again:\n");
				//break;
		}

	}

	return 0;
}
