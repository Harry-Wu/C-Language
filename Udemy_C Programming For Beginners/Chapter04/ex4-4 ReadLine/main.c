#include <stdio.h>
//���� stdbool.h ��ʹ�ò�������
#include <stdbool.h>

#define NAMELEN 5

void Flush_Input()
{
	int ch = 0;
	while ((ch = getchar() != '\n' && ch != EOF));
	//return ch;
}

//ͨ���ж���û�а��»س�������������ַ�
int ReadLine1(char s[], int maxlen)
{
	int len_s;
	fgets(s, maxlen, stdin);
	len_s = strlen(s);
	if (s[len_s-1]=='\n')  //��������˻��з������ַ������һλ�滻�ɽ�������ͬʱ�ַ�������-1
	{
		s[len_s - 1] = '\0';
		len_s -= 1;
	}
	rewind(stdin); //This flushes the keyboard buffer (on Windows anyway!)
	return len_s;

}

//ÿ��⵽һ���ַ������Ϸŵ��ַ�����
//����ʵ��Ҫ��ʾ���ַ���
int ReadLine(char s[], int maxlen)
{
	char buffer; //
	int i = 0;  //�ַ�������
	bool chars_remain = true; //����û����Ҫ������ַ�
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


//ʹ�������ReadLine1����
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

//ʹ�������ReadLine����
//�����Ը���
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