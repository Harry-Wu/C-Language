
/*****************************************************************************
@File name:
@Description: 了解字符测试函数， isxdigit()，isupper()，ispunct()，isspace()，isprint()，islower()等
			  字符测试函数要加入ctype.h
@Author: Harry Wu
@Version: V1.0
@Date: 2017-04-02
@History:
V1.0: 统计输入的字符串的各种字符的个数
*****************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

#define MAXSTRLEN 100

char mystring[MAXSTRLEN];


//查找输入的字符串中的单词, 并统计各种字符的个数
void chartypes()
{
	int i;
	char c;
	int numDigits = 0;
	int numLetters = 0;
	int numUpCase = 0;
	int numLowCase = 0;
	int numSpaces = 0;
	int numPunct = 0;
	int numUnknown = 0;
	int lengthOfStr;
	lengthOfStr = strlen(mystring);
	for (i = 0; i < lengthOfStr; i++) 
	{
		c = mystring[i];
		if (isalpha(c)) 
		{
			numLetters++;
			if (isupper(c)) 
			{
				printf("'%c' [大写字母]\n", c);
				numUpCase++;
			}
			else 
			{
				printf("'%c' [小写字母]\n", c);
				numLowCase++;
			}
		}
		else if (isdigit(c)) 
		{
			printf("'%c' [数字]\n", c);
			numDigits++;
		}
		else if (ispunct(c)) 
		{
			printf("'%c' [标点符号]\n", c);
			numPunct++;
		}
		else if (isblank(c))
		{
			printf("'%c' [空白]\n", c);
			numSpaces++;
		}
		else 
		{
			printf("'%c' [未知]\n", c);
			numUnknown++;
		}
	}
	printf("This string contains %d 个字符:\n%d 个字母(%d 大写, %d 小写)， ", lengthOfStr, numLetters,
		numUpCase, numLowCase);
	printf("%d 个数字, %d 个标点符号, %d 个空格 and %d 个未知符号.\n", numDigits, numPunct, 
		numSpaces, numUnknown);
}

int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	printf("Please input the string you want to test:\n");
	gets_s(mystring, MAXSTRLEN - 1);  //get_s放在函数外面了，会报错。另外，不要输入中文字符
	chartypes();

	return 0;

}