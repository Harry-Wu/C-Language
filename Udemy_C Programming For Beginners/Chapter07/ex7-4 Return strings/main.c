//了解字符串的堆和栈 
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
	printf(buffer);   //free之后再打印buffer就成了乱码了
	printf("----Use string array----\n");
	printf(string_function("Harry"));
	printf(greeting); 
	
	return 0;
}