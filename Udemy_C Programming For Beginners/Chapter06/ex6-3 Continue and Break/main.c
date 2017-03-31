/*****************************************************************************
@File name:
@Description: ����ѭ������continue��break���÷�������������һ�������ַ������㷨
@Author: Harry Wu
@Version: V1.0
@Date: 2017-xx-xx
@History:
V1.0:
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
			break;  //��������������ѭ���ˣ����ԣ�û�б��Ž�str[]��
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
			str[i] = c;
			continue;  //�����ո����������str[i] = c + 1;���ܴ���
		}
		if (c == '!' || (c == '\0'))  //������������������ټ���
		{
			str[i] = '\0';
			break;
		}
		str[i] = c + 1;
	}
	printf("\nThe encrypted str='%s'", str);
}

int main(int argc, char** argv)
{
	printf("Please input the string you want to process:\n");
	gets_s(chararray, 50);
	//scanf_s("%s", chararray, 50);  //scanf() ��ȡ���ո�ʱ����Ϊ�ַ�����������ˣ����������ȡ��
	whilebreak();
	forbreak();
	printf("\n");
}