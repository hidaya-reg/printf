#include "main.h"
/**
 * _printf - function that produces output according to format
 * @format: desired format
 * Return: number of characters printed
 *it's ok
 */
int _printf(const char *format, ...)
{
	fmt_t t[] = {
		{"%s", print_str},
		{"%c", print_char},
		{"%%", print_pct},
	};
	va_list args;
	int i = 0, j, nbr_char = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);


Here:
	while (format[i] != '\0')
	{
		j = 2;
		while (j >= 0)
		{
			if (t[j].fmt[0] == format[i] && t[j].fmt[1] == format[i + 1])
			{
				nbr_char += t[j].fct(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		i++;
		nbr_char++;
	}
	va_end(args);
	return (nbr_char);
}
