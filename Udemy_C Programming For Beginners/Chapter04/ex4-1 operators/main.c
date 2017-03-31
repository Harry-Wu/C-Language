#include <stdio.h>
//导入 stdbool.h 来使用布尔类型
#include <stdbool.h>

void showPrefixAndPostfixOps() 
{
	int num1, num2;
	printf("\nPrefix and Postfix operators... (num1 = 10)");
	num1 = 10;
	num2 = num1++; // num2 = 10, num1 = 11
	printf("\nnum2 = num1++; so num2 = %d and num1 = %d", num2, num1);

	num1 = 10;
	num2 = ++num1; // num2 = 11, num1 = 11
	printf("\nnum2 = ++num1; so num2 = %d and num1 = %d\n", num2, num1);
}

int main(int argc, char **argv)
{
	int age;
	int bonus;
	char agestring[10];
	bool playagain = true;

	int a = 10;
	int b = 2;

	
	while (playagain == true)
	{
		printf("Please input your age, input 'Q' to quit:\n");
		gets(agestring);
		age = atoi(agestring);

		if (agestring[0] == 'q' || agestring[0] == 'Q')
		{
			playagain = false;
		}

		else if (age <= 0)
		{
			printf("You entered an invalid age, so your bonus cannot be calculated.\n");
		}
		else
		{
			if (age > 45)	bonus = 1000;
			else			bonus = 500;
			printf("Your age is %d, so your bonus is %d.\n", age, bonus);

			if (age < 50)
			{
				printf("You are one of our youngest employees!\n");
			}
			if (bonus >= 1000)
			{
				printf("You've earned a high bonus!\n");
			}

			
		}
	}
	showPrefixAndPostfixOps();
}