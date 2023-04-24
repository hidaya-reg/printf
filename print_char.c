#include "main.h"

/**
 * print_char - print a character
 * @args: arguments
 * Return: 1
 */

int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	_putchar(c);
	return (1);
}
