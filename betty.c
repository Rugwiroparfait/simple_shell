#include <stdio.h>

/**
 * print_hello - Prints a hello message.
 */
void print_hello(void)
{
	printf("Hello, world!\n");
}

/**
 * add_numbers - Adds two numbers.
 *
 * @a: The first number.
 * @b: The second number.
 *
 * Return: The sum of a and b.
 */
int add_numbers(int a, int b)
{
	return (a + b);
}

/**
 * main - Entry point of the program.
 *
 * Return: 0 on success.
 */
int main(void)
{
	print_hello();

	int result = add_numbers(5, 7);

	printf("The sum is: %d\n", result);

	return (0);
}

