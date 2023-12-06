#include <stdio.h>
#include <stdlib.h>

/**
 * sum : finds summation of two numbers
 * @num1 : first number argument
 * @num2 : second number argument
 *
 * Return : summation when success , 0 when failed;
 */

int sum(int num1, int num2)
{
	return (num1 + num2);
}



int main(void)
{
	printf("summation is %d\n", sum(2 ,5));
	return (0);
}
