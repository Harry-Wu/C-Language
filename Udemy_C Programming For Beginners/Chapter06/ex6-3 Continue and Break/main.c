/*****************************************************************************
@File name:
@Description: 测试循环体中continue和break的用法，此例子用了一个加密字符串的算法
@Author: Harry Wu
@Version: V1.1
@Date: 2017-03-31
@History:
	V1.0:加密一段字符串（原字符加1）
	V1.1:加上解密功能
	V1.2:另外，使用continue并不安全，所以改成了if-else判断
*****************************************************************************/

#include <stdio.h>
#include <stdbool.h>
char chararray[50];

void whilebreak() 
{
	int i;
	char c;
	char str[50];
	i = 0;
	while (i >= 0) 
	{
		c = chararray[i];
		printf("[%d]='%c' ", i, c);
		if ((c == '!') || (c == '\0')) 
		{
			str[i] = '\0';
			break;  //遇到结束符跳出循环了，所以！没有被放进str[]里
		}
		str[i] = c;
		i++;
	}
	printf("\nAfter while loop, str='%s'", str);
}

void forbreak()
{
	int i;
	char str[50];
	char c;
	// for loop #1 - encrypt string
	for (i = 0; i < 50; i++)
	{
		c = chararray[i];
		if (c == ' ')
		{
			str[i] = c;  //遇到空格不做加密处理
			//continue;  
		}
		else if (c == '!' || (c == '\0'))  //遇到！或结束符，不再加密
		{
			str[i] = '\0';
			break;
		}
		else  //除了以上两种情况，均加密
		{
			str[i] = c + 1;
		}
	}
	printf("\nThe encrypted str='%s'", str);
	//decrypt string
	for (i = 0; i < 50; i++)
	{
		c = str[i];
		if (c == ' ')
		{
			str[i] = c;  //遇到空格跳过后面的str[i] = c + 1;加密处理
			//continue;  
		}
		else if (c == '!' || (c == '\0'))  //遇到！或结束符，不再加密
		{
			str[i] = '\0';
			break;
		}
		else  //除了以上两种情况，均解密
		{
			str[i] = c - 1;
		}
	}
	printf("\nThe decrypted str='%s'", str);
}

int main(int argc, char** argv)
{
	printf("Please input the string you want to process:\n");
	gets_s(chararray, 50);
	//scanf_s("%s", chararray, 50);  //scanf() 读取到空格时就认为字符串输入结束了，不会继续读取了
	whilebreak();
	forbreak();
	printf("\n");
}