//����һ�γ̿�ʼ������������Сд����������֮����_�ָ�����C��ϰ��
#include <stdio.h>
#include <stdbool.h>

char str1[] = "Hello, ";
char str2[] = "Amy.\0 Goodbye!";

void show_string(char *str)
{
	int len = strlen(str);
	printf("The length of '%s' is %d.\n", str, len);
	for (int i = 0; i <= len ; i++)
	{
		if (str[i] == '\0')
		{
			printf("char[%d] = NULL\t", i);
		}
		else
		{
			printf("char[%d] = %c\t", i, str[i]);
		}
	}
	printf("\n");
}

int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	printf("The original string is %s\n", str1);
	show_string(str1);
	printf("The original string is %s\n", str2);
	show_string(str2);

}