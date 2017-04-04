/*****************************************************************************
@File name:
@Description:
@	�򿪶������ļ�����ʾ״̬
@Author: Harry Wu
@Version: V1.0
@Date: 2017-04-04
@History:
	V1.0: �򿪶������ļ�����ʾ״̬

*****************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "cs50.h"
#include "mystringutils.h"  //�����ַ��ĺ���

//#define MAXSTRLEN 200
#define FILENAME "changelog.txt"
#define FILENAME2 "sonnet.txt"

//�����Ƹ�ʽ��ȡ�ļ���Ϣ
void read_binfile(char *filename)
{
	FILE *fp;
	errno_t err = fopen_s(&fp, filename, "rb");  //"rb"--�����Ʒ�ʽ���ļ�
	char line[MAXSTRLEN];  //������ʱ��Ŵ��ļ���ȡ����һ���ַ���
	int numlines = 0;  //�����ļ��ж���������
	long numbytes = 0;  //�����ļ��ж��ٸ��ֽ�
	if (!err && fp != NULL)
	{
		printf("File '%s' is opened.\n", filename);
		printf("-----------------------------------------\n");
		fseek(fp, 0, SEEK_END);  //���ڶ����Ʒ�ʽ�򿪵��ļ�,�ƶ��ļ���дָ��λ�õ��ļ���β
		numbytes = ftell(fp); //���ļ�λ��ָ�뵱ǰλ��������ļ��׵�ƫ���ֽ���
		rewind(fp);  //���ļ�ָ������ָ��һ�����Ŀ�ͷ
		char *buffer = (char *)malloc(numbytes);
		long items_read = fread(buffer, 1, numbytes, fp);		//��ѯ�¶������ٸ�Ԫ��
		//ע�������fgetsȥ�����ж����е�ʱ���ļ�ָ��fpһ��Ҫ�ƻص��ļ���ͷ��
		//��һ�ַ����Ǳ���buffer[],��ѯ'\n'�ĸ�����֪���ж�������
		rewind(fp);
		while (fgets(line, sizeof(line), fp) != 0)
		{
			numlines++;  //ֻҪ����һ�о�+1
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
