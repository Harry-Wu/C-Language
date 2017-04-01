//从这一课程开始，函数名都以小写命名，单词之间用_分隔符合C的习惯
#include <stdio.h>
#include <stdbool.h>

int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	char str1[] = "Hello";
	char *str2 = "Goodbye";  //指针变量指向字符串所在地址
	char *str3 = &str1;
	//下面两句等同于char *str4 = str1;
	char *str4; 
	str4 = str1;
	printf("pointaddr  straddr  str\n");
	printf("%x %x %s\n", &str1, str1, str1);  //数组的首地址，数组的值（也是首地址），数组的值
	printf("%x %x %s\n", &str2, str2, str2);  //指针变量所在地址，指针里存放的值（存的是字符串的地址），字符串
	printf("%x %x %s\n", &str3, str3, str3);
	printf("%x %x %s\n", &str4, str4, str4);
	return 0;
}