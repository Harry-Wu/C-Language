#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "cs50.h"

//�����ַ����еĵ���,
//������ҳɹ�,��ʾ�������ַ����е�λ��
//���û�ɹ�,����ʾnot found
int search_str(char *strDestination, char *searchstr)
{
	char *buffer;
	int strPosition = -1;
	buffer = strstr(strDestination, searchstr); //�ҵ��ĵ�ַ����buffer
	
	if (buffer != NULL)
		strPosition = buffer - strDestination; //�ҵ��ַ�����λ��, ע��buffer��StrDestination����64λ��,�п��ܻ�������ݶ�ʧ(ȡ�����ַ����ĳ����Ƿ񳬹�int���ֵ)

	return strPosition;
}

void search_str2(char *strDestination, char *searchstr)
{
	//char *buffer;
	//buffer = strstr(strDestination, searchstr); //�ҵ��ĵ�ַ����buffer
	int strPosition = search_str(strDestination, searchstr); //�ҵ��ַ�����λ��
	if (strPosition > -1)
		printf("'%s' found in '%s' at position #%d\n", searchstr, strDestination, strPosition);
	else
		printf("'%s' not found in '%s'\n", searchstr, strDestination);
}