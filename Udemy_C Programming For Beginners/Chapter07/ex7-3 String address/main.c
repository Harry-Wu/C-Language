//�˽�ָ����ַ�������ϵ
#include <stdio.h>
#include <stdbool.h>

int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	char str1[] = "Hello";
	char *str2 = "Goodbye";  //ָ�����ָ���ַ������ڵ�ַ
	char str3[5];
	str3[0] = 'A'; str3[1] = 'm'; str3[2] = 'y'; str3[3] = '.'; str3[4] = '\0';

	printf("straddr str\n");
	printf("%d %s\n", str1, str1);  //�����ֵ��Ҳ���׵�ַ���������ֵ
	printf("%d %s\n", str2, str2);  //ָ�����ŵ�ֵ��������ַ����ĵ�ַ�����ַ���
	printf("%d %s\n", str3, str3);
	printf("----Test the pointer----\n");
	printf("%d %d %d %d\n", &str3[0], &str3[1], &str3[2], &str3[3]);
	printf("%d %d %d %d\n", str3, str3 + 1, str3 + 2, str3 + 3);  //ע����к���һ�������
	printf("%d %d %d %d\n", &str3, &str3 + 1, &str3 + 2, &str3 + 3); //ȡ��������������׵�ַ����Ϊstr3��5���ַ�����������ַ����һ�����5
	return 0;
}