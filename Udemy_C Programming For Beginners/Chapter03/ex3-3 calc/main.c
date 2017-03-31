//改正了数据类型，如果用float试试
#include <stdio.h>

int main(int argc, char** argv)
{
	double subtotal = 200;
	double tax, grandtotal;  //subtotal为不含税价格
	double taxrate = 0.174;
	tax = subtotal * taxrate; //总税
	grandtotal = subtotal + tax;  //含税价格
	//printf("pettycash=%.2f\n", pettycash);
	//pettycash = 10.5 / 11;
	printf("The tax on %f is %f, so the grand total is %f.\n", subtotal, tax, grandtotal);
	//printf("grandtotal=%.2f\n", grandtotal);
	return 0;
}