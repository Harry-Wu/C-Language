#include <stdio.h>
//���� stdbool.h ��ʹ�ò�������
#include <stdbool.h>
void Flush_Input()
{
	int ch = 0;
	while ((ch = getchar() != '\n' && ch != EOF));
	//return ch;
}

//�涨�����������ַ�����������˳���ᱨ��
void GetInputWithGets()
{
	char firstname[5];
	char lastname[5];
	printf("Enter your first name:");
	gets_s(firstname, 5);
	printf("Enter your last name:");
	gets_s(lastname, 5);
	

	printf("Hello, %s, %s\n", firstname, lastname);

}

//�涨�����������ַ�����������˻�ֻȥǰ4���ַ���+������\0)
//���и����⣬���������ַ�����5��������ͻ�ȴ�������Enter
void GetInput_With_Fgets()
{
	char firstname[5];
	char lastname[5];
	//int leftchar;
	printf("Enter your first name:");
	fgets(firstname, 5, stdin);
	Flush_Input();
	//printf("The left char is %d\n", leftchar);

	printf("Enter your last name:");
	//fflush(stdin); //This function may not (invariably) work with input!
	fgets(lastname, 5, stdin);
	Flush_Input();
	//printf("The left char is %d\n", leftchar);
	printf("Hello, %s, %s\n", firstname, lastname);

}

int main(int argc, char **argv)
{
	printf("Try GetInputWithGets:\n");
	GetInputWithGets();
	fflush(stdin); //This function may not (invariably) work with input!

	printf("Try GetInput_With_Fgets:\n");
	GetInput_With_Fgets();
	return 0;
}