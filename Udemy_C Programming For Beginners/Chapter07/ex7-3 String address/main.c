//了解指针和字符串的联系
#include <stdio.h>
#include <stdbool.h>

int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp)
{
	char str1[] = "Hello";
	char *str2 = "Goodbye";  //指针变量指向字符串所在地址
	char str3[5];
	str3[0] = 'A'; str3[1] = 'm'; str3[2] = 'y'; str3[3] = '.'; str3[4] = '\0';

	printf("straddr str\n");
	printf("%d %s\n", str1, str1);  //数组的值（也是首地址），数组的值
	printf("%d %s\n", str2, str2);  //指针里存放的值（存的是字符串的地址），字符串
	printf("%d %s\n", str3, str3);
	printf("----Test the pointer----\n");
	printf("%d %d %d %d\n", &str3[0], &str3[1], &str3[2], &str3[3]);
	printf("%d %d %d %d\n", str3, str3 + 1, str3 + 2, str3 + 3);  //注意此行和下一句的区别
	printf("%d %d %d %d\n", &str3, &str3 + 1, &str3 + 2, &str3 + 3); //取的是整个数组的首地址，因为str3有5个字符，所以它地址的下一个会加5
	return 0;
}