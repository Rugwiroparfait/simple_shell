#include "shell.h"

/**
 * is_digit - Checks if a character is a digit
 * @c: The character to check
 *
 * Return: 1 if the character is a digit, 0 otherwise
 */
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _atoi_recursive - Recursively converts a string to an integer
 * @str: The string to convert
 * @sign: The sign of the number (1 for positive, -1 for negative)
 *
 * Return: The converted integer
 */
int _atoi_recursive(char *str, int sign)
{
	if (*str == '\0' || !is_digit(*str))
	return (0);

	return ((*str - '0') + _atoi_recursive(str + 1, sign) * 10);
}

/**
 * _atoi - Converts a string to an integer
 * @str: The string to convert
 *
 * Return: The converted integer
 */
int _atoi(char *str)
{
	int sign = 1;  /** Sign of the number, 1 for positive, -1 for negative**/

    /** Handle negative sign **/
	if (*str == '-')
	{
	sign = -1;
	str++;
	}

	return (sign * _atoi_recursive(str, sign));
}
