//错误的使用数据类型
#include <stdio.h>

int main(int argc, char** argv)
{
	int subtotal=200, tax, grandtotal;  //subtotal为不含税价格
	double taxrate = 0.174;
	tax = subtotal * taxrate; //总税
	grandtotal = subtotal + tax;  //含税价格
	//printf("pettycash=%.2f\n", pettycash);
	//pettycash = 10.5 / 11;
	printf("The tax on %d is %d, so the grand total is %d.\n", subtotal, tax, grandtotal);
	//printf("grandtotal=%.2f\n", grandtotal);
	return 0;
}