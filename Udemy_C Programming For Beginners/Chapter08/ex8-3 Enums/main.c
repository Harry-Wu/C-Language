/*****************************************************************************
@File name:
@Description: ö�����͵�ʹ��
@Author: Harry Wu
@Version: V1.0
@Date: 2017-04-02
@History:
V1.0: �ṹ�������ֵ��ȡֵ
V1.1: ����cd��Ϣ�ĺ����ŵ�������c�ļ�,Ȼ�������main.c�ļ���

*****************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include "mycdinfo.h"



int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	//struct cd thiscd;
	CD thiscd;
	create_cdcollection();
	for (int i = 0; i < 4; i++)  //��ӡ��4���ṹ��������������
	{
		thiscd = cd_collection[i];
		printf("CD #%d: '%s' by %s has %d tracks. My rating = %d\n", i, thiscd.name, thiscd.artist, thiscd.trackcount, thiscd.rating);
	}
	printf("Enum, use head file\n");
	return 0;
}
