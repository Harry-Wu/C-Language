//����һ�γ̿�ʼ������������Сд����������֮����_�ָ�����C��ϰ��
#include <stdio.h>
#include <stdbool.h>

int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	char str1[] = "Hello";
	char *str2 = "Goodbye";  //ָ�����ָ���ַ������ڵ�ַ
	char *str3 = &str1;
	//���������ͬ��char *str4 = str1;
	char *str4; 
	str4 = str1;
	printf("pointaddr  straddr  str\n");
	printf("%x %x %s\n", &str1, str1, str1);  //������׵�ַ�������ֵ��Ҳ���׵�ַ���������ֵ
	printf("%x %x %s\n", &str2, str2, str2);  //ָ��������ڵ�ַ��ָ�����ŵ�ֵ��������ַ����ĵ�ַ�����ַ���
	printf("%x %x %s\n", &str3, str3, str3);
	printf("%x %x %s\n", &str4, str4, str4);
	return 0;
}