
/*****************************************************************************
@File name:
@Description: 了解处理字符串的多个函数，strcat, strcpy, strstr, strncpy等
@Author: Harry Wu
@Version: V1.0
@Date: 2017-04-01
@History:
	V1.0: 新的都建议用带_s的函数,更安全
*****************************************************************************/
 
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

#define MAXSTRLEN 100

char mystring[] = "On the 2nd day of Christmas my true love gave to me, 2 turtle doves and a partridge in a pear tree.";
char nums[] = "12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890";  //用来数位置的
char tens[] = "0        1         2         3         4         5         6         7         8         9         0         1";  //用来数位置的

char msg1[MAXSTRLEN] = "Result1: ";
char msg2[MAXSTRLEN] = "Result2: ";
char myotherstr[6] = "test";

//查找字符串中的单词,
//如果查找成功,显示单词在字符串中的位置
//如果没成功,则显示not found
void search_str(char *strDestination, char *searchstr)
{
	char *buffer;
	buffer = strstr(strDestination, searchstr); //找到的地址发给buffer
	int strPosition = buffer - strDestination + 1; //找到字符串的位置
	if (buffer != NULL)
		printf("'%s' found at position %d\n", searchstr, strPosition);
	else
		printf("'%s' not found\n", searchstr);
}


int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	printf("%s\n%s\n%s\n",mystring, nums, tens);
	printf("Length of mystring = %d", strlen(mystring));
	printf("\nLength of 'Hello' = %d", strlen("Hello"));
	search_str(mystring, "2nd");
	search_str(mystring, "Christmas");
	search_str(mystring, "Easter");

	printf("The original string is '%s'\n", myotherstr);
	strncpy_s(myotherstr, 6, "Easter", 4);
	printf("Use strncpy_s: Copied this string: '%s'\n", myotherstr);

	strcat_s(msg1, 20, "Hello");
	printf("Use strcat_s: '%s'\n", msg1);
	strncat_s(msg2, 20, "Hello", 4);
	printf("Use strncat_s: '%s'\n", msg2);

}