/*****************************************************************************
@File name:
@Description:
@	����CD������Ϣ��
@Author: Harry Wu
@Version: V1.2
@Date: 2017-04-09
@History:
	V1.0: ��������ʾcd��Ϣ�������cd��Ϣ�Ĺ��ܺ���
	V1.1: �������޸�cd��Ϣ�ͱ����ڴ���cd��Ϣ�Ĺ��ܺ���
	V1.2: ��������������к��п����Ǹ���, �򳬳���Χ���ж�; �����˿���̨����ı���
*****************************************************************************/
//TODO: display_cdcollection()�����кܶྯ��, ��ʱ���Ż�

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "cs50.h"
#include "mystring.h"  //�����ַ��ĺ���
#include "mycdinfo.h"  //cd_database������

#define FILENAME "cd_database.bin"
#define FILENAME_BAK "cd_database.bak"



int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	system("title CD_DATABASE"); //�������
	bool keepgoing = true;  //�Ƿ����������ʶ��
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
