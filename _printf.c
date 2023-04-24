#include "main.h"
/**
 * _printf - function that produces output according to format
 * @format: desired format
 * Return: number of characters printed
 */
int _printf(const char * const format, ...)
{
	fmt_t fmt[] = {
		{"%s", print_str},
		{"%c", print_char},
		{"%%", print_pct}
	};
	va_list args;
	int i, j, nbr_char = 0, len_str = 1;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i += 2)
	{
		j = 2;
		while (j >= 0)
		{
			if (fmt_t[j].fmt[0] == format[i] && fmt_t[j].fmt[1] == format[i + 1])
			{
				len_str = fmt[j].fct(args);
			}
			j--;
		}
		nbr_char += len_str;
	}
	nbr_char = (nbr_char + i) / 2;
	va_end(args);
	return (nbr_char);
}
