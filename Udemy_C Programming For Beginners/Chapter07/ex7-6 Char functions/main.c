
/*****************************************************************************
@File name:
@Description: �˽��ַ����Ժ����� isxdigit()��isupper()��ispunct()��isspace()��isprint()��islower()��
			  �ַ����Ժ���Ҫ����ctype.h
@Author: Harry Wu
@Version: V1.0
@Date: 2017-04-02
@History:
V1.0: ͳ��������ַ����ĸ����ַ��ĸ���
*****************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>

#define MAXSTRLEN 100

char mystring[MAXSTRLEN];


//����������ַ����еĵ���, ��ͳ�Ƹ����ַ��ĸ���
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
				printf("'%c' [��д��ĸ]\n", c);
				numUpCase++;
			}
			else 
			{
				printf("'%c' [Сд��ĸ]\n", c);
				numLowCase++;
			}
		}
		else if (isdigit(c)) 
		{
			printf("'%c' [����]\n", c);
			numDigits++;
		}
		else if (ispunct(c)) 
		{
			printf("'%c' [������]\n", c);
			numPunct++;
		}
		else if (isblank(c))
		{
			printf("'%c' [�հ�]\n", c);
			numSpaces++;
		}
		else 
		{
			printf("'%c' [δ֪]\n", c);
			numUnknown++;
		}
	}
	printf("This string contains %d ���ַ�:\n%d ����ĸ(%d ��д, %d Сд)�� ", lengthOfStr, numLetters,
		numUpCase, numLowCase);
	printf("%d ������, %d ��������, %d ���ո� and %d ��δ֪����.\n", numDigits, numPunct, 
		numSpaces, numUnknown);
}

int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	printf("Please input the string you want to test:\n");
	gets_s(mystring, MAXSTRLEN - 1);  //get_s���ں��������ˣ��ᱨ�����⣬��Ҫ���������ַ�
	chartypes();

	return 0;

}