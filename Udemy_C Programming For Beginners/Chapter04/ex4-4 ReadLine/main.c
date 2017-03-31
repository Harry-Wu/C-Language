#include <stdio.h>
//导入 stdbool.h 来使用布尔类型
#include <stdbool.h>

#define NAMELEN 5

void Flush_Input()
{
	int ch = 0;
	while ((ch = getchar() != '\n' && ch != EOF));
	//return ch;
}

//通过判断有没有按下回车来处理输入的字符
int ReadLine1(char s[], int maxlen)
{
	int len_s;
	fgets(s, maxlen, stdin);
	len_s = strlen(s);
	if (s[len_s-1]=='\n')  //如果输入了换行符，则字符串最后一位替换成结束符，同时字符串长度-1
	{
		s[len_s - 1] = '\0';
		len_s -= 1;
	}
	rewind(stdin); //This flushes the keyboard buffer (on Windows anyway!)
	return len_s;

}

//每检测到一个字符就马上放到字符串中
//返回实际要显示的字符数
int ReadLine(char s[], int maxlen)
{
	char buffer; //
	int i = 0;  //字符串长度
	bool chars_remain = true; //还有没有需要处理的字符
	while (chars_remain)
	{
		buffer = getchar();
		if ((buffer == '\n') || (buffer == EOF)) chars_remain = false;
		else if (i < maxlen - 1)
		{
			s[i] = buffer;
			i++;
		}
		
	}
	s[i] = '\0';
	return i;
}


//使用上面的ReadLine1函数
void GetInput1()
{
	char firstname[NAMELEN];
	char lastname[NAMELEN];
	int lens_firstname, lens_lastname;
	printf("Enter your first name:");
	lens_firstname = ReadLine1(firstname, NAMELEN);
	printf("Enter your last name:");
	lens_lastname = ReadLine1(lastname, NAMELEN);

	printf("Hello, %s, %s\n", firstname, lastname);
	printf("lens_firstname is %d, lens_lastname is %d\n", lens_firstname, lens_lastname);

}

//使用上面的ReadLine函数
//兼容性更好
void GetInput()
{
	char firstname[NAMELEN];
	char lastname[NAMELEN];
	int lens_firstname, lens_lastname;
	printf("Enter your first name:");
	lens_firstname = ReadLine(firstname, NAMELEN);
	printf("Enter your last name:");
	lens_lastname = ReadLine(lastname, NAMELEN);

	printf("Hello, %s, %s\n", firstname, lastname);
	printf("lens_firstname is %d, lens_lastname is %d\n", lens_firstname, lens_lastname);

}


int main(int argc, char **argv)
{
	printf("Try GetInput1:\n");
	GetInput1();

	printf("Try GetInput:\n");
	GetInput();
	return 0;
}