#include "shell.h"
/**
 * print_prompt - prints prompt to the stdout.
 *@prompt: pinter to char.
 *
 * Return: void.
 */
void print_prompt(char *prompt)
{
	write(1, prompt, sizeof(prompt));
}
