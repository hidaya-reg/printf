#include "main.h"
/**
 * _printf - function that produces output according to format
 * @format: desired format
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	fmt_t t[] = {
		{"%s", print_str},
		{"%c", print_char},
		{"%%", print_pct}
	};
	va_list args;
	int i = 0, j, nbr_char = 0, len_str = 1;

	if (format == NULL)
		return (-1);

	va_start(args, format);
Here:
	while (format[i] != '\0')
	{
		j = 2;
		while (j >= 0)
		{
			if (t[j].fmt[0] == format[i] && t[j].fmt[1] == format[i + 1])
			{
				len_str = t[j].fct(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		i++;
		nbr_char = nbr_char + len_str;
	}
	nbr_char = (nbr_char + i) / 2;
	va_end(args);
	return (nbr_char);
}
