#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "cs50.h"

//查找字符串中的单词,
//如果查找成功,显示单词在字符串中的位置
//如果没成功,则显示not found
int search_str(char *strDestination, char *searchstr)
{
	char *buffer;
	int strPosition = -1;
	buffer = strstr(strDestination, searchstr); //找到的地址发给buffer
	
	if (buffer != NULL)
		strPosition = buffer - strDestination; //找到字符串的位置, 注意buffer和StrDestination都是64位的,有可能会造成数据丢失(取决与字符串的长度是否超过int最大值)

	return strPosition;
}

void search_str2(char *strDestination, char *searchstr)
{
	//char *buffer;
	//buffer = strstr(strDestination, searchstr); //找到的地址发给buffer
	int strPosition = search_str(strDestination, searchstr); //找到字符串的位置
	if (strPosition > -1)
		printf("'%s' found in '%s' at position #%d\n", searchstr, strDestination, strPosition);
	else
		printf("'%s' not found in '%s'\n", searchstr, strDestination);
}