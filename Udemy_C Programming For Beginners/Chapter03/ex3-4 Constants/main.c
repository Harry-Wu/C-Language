//�������������ͣ������float����
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
//#include <cmath>

int main(int argc, char** argv)
{
	#define PI 3.1415926	
	printf("%f\n", PI);
	printf("%.10f\n\n", M_PI);

	#define TAXRATE 0.174
	const double TAXRATE_CONST = 0.174;

	double taxrate = 0.171;
	double subtotal = 200;
	double tax, grandtotal;  //subtotalΪ����˰�۸�
	taxrate = 0.2;
	tax = subtotal * taxrate; //��˰
	grandtotal = subtotal + tax;  //��˰�۸�
	printf("The taxrate is %.3f.\n", taxrate);
	printf("The tax on %f is %f, so the grand total is %f.\n\n", subtotal, tax, grandtotal);

	subtotal = 200; //change back to default value
	#define TAXRATE 0.2		// redefine a #define 'constant',�������¶��壬����ע�����ʱ�ᾯ��
	tax = subtotal * TAXRATE;
	grandtotal = subtotal + tax;
	printf("The TAXRATE is %.3f.\n", TAXRATE);
	printf("The tax on %.2f is %.2f, so the grand total is %.2f.\n\n", subtotal, tax, grandtotal);

	subtotal = 200;
	//TAXRATE_CONST = 0.2;			// cannot redefine a true constant!
	tax = subtotal * TAXRATE_CONST;
	grandtotal = subtotal + tax;
	printf("The TAXRATE_CONST is %.3f.\n", TAXRATE_CONST);
	printf("The tax on %.2f is %.2f, so the grand total is %.2f.\n\n", subtotal, tax, grandtotal);
	return 0;
}