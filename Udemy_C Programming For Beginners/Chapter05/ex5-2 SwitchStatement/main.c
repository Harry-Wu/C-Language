/*****************************************************************************
@File name:
@Description: 使用switch-case语句
@Author: Harry Wu
@Version: V1.0
@Date: 2017-03-31
@History:
V1.0:
*****************************************************************************/
#include <stdio.h>
#include <stdbool.h>

char *chartype;

void findchartype(int i)
{
	switch (i)
	{
		case 0:
			chartype = "NULL";
			break;
		case 7:
			chartype = "Bell";
			break;
		case 8:
			chartype = "BackSpace";
			break;
		case 9:
			chartype = "Tab";
			break;
		case 10:
			chartype = "LineFeed";
			break;
		case 13:
			chartype = "Carriage Return";
			break;
		case 32:
			chartype = "Space";
			break;
		case 48:
		case 49:
		case 50:
		case 51:
		case 52:
		case 53:
		case 54:
		case 55:
		case 56:
		case 57:
			chartype = "Number";
			break;
			/*
			//Visual Studio的编译器不行
			// These use ranges (values between 65 and 90; values between 97 and 122)
			// Ranges in Switch/case are an extension to standard C and this syntax
			// is not supported by all C compilers
			case 65 ... 90:
			chartype = "Uppercase Letter";
			break;
			case 97 ... 122:
			chartype = "Lowercase Letter";
			break;
			*/
		default:
			chartype = "Character";
			break;
	}
}

void ShowAscii()
{
	int i;
	char c;
	for (i = 0; i <= 127; i++) {
		findchartype(i);
		printf("%-3d = %c\t\t[%s]\n", i, i, chartype);
	}
	printf("\nPress Enter to continue...\n");
	c = getchar();
	for (i = 0; i <= 127; i++) {
		//findchartype2(i);
		printf("%-3d = %c\t\t[%s]\n", i, i, chartype);
	}
}

int main(int argc, char **argv) 
{
	ShowAscii();
	return 0; 
}