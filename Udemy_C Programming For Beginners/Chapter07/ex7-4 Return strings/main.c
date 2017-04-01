/********************************************
	了解字符串的堆和栈
	V1.0: 使用malloc和free
	V1.1: 将strcat换成更安全的strcat_s
********************************************/
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

#define MAXSTRLEN 20
char greeting[MAXSTRLEN];

char *string_function_dynamic(char *astring)
{
	char *s;
	s = malloc(MAXSTRLEN);  //如果不分配内存，s的值不会传出来
	s[0] = 0;  //用来初始化malloc分配的缓冲区
	strcat_s(s, MAXSTRLEN, "Hello,");  //第二个参数代表目标字符串缓冲区的大小
	strcat_s(s, MAXSTRLEN, astring);
	strcat_s(s, MAXSTRLEN, "\n");
	return s;
}

char *string_function(char astring[])
{
	strcat_s(greeting, MAXSTRLEN, "Hello,");
	strcat_s(greeting, MAXSTRLEN, astring);
	strcat_s(greeting, MAXSTRLEN, "\n");
	return greeting;
}

int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	printf("----Use pointer----\n");
	printf(string_function_dynamic("Amy"));
	char *buffer = string_function_dynamic("Amy");
	printf(buffer);
	free(buffer);
	printf(buffer);   //free之后再打印buffer就成了乱码了
	printf("----Use string array----\n");
	printf(string_function("Harry"));
	printf(greeting); 
	
	return 0;
}