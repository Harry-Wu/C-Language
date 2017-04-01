//�˽��ַ����ĶѺ�ջ 
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

#define MAXSTRLEN 20
char greeting[MAXSTRLEN];

char *string_function_dynamic(char *astring)
{
	char *s;
	s = malloc(MAXSTRLEN);  //����������ڴ棬s��ֵ���ᴫ����
	s[0] = 0;  //������ʼ��malloc����Ļ�����
	strcat(s, "Hello,");
	strcat(s, astring);
	strcat(s, "\n");
	return s;
}

char *string_function(char astring[])
{
	strcat(greeting, "Hello,");
	strcat(greeting, astring);
	strcat(greeting, "\n");
	return greeting;
}

int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	printf("----Use pointer----\n");
	printf(string_function_dynamic("Amy"));
	char *buffer = string_function_dynamic("Amy");
	printf(buffer);
	free(buffer);
	printf(buffer);   //free֮���ٴ�ӡbuffer�ͳ���������
	printf("----Use string array----\n");
	printf(string_function("Harry"));
	printf(greeting); 
	
	return 0;
}