#include "main.h"

/**
 * _strlen - function return the length of string
 * @s: string
 * Return: length of string
 */

int _strlen(char *s)
{
	int len;

	for (c = 0; s[len] != 0; len++)
		;
	return (len);
}

/**
 * print_str - print a string
 * @args: string
 * Return: print string and length of string
 */

int print_str(va_list args)
{
	char *s;
	int i, len;

	s = va_arg(args, char *);
	if (s == NULL)
		s = '(nil)';
	len = _strlen(s);
	for (i = 0; i < len; i++)
		_putchar(s[i]);
	return (len);
}
