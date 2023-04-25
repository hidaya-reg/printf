#include "main.h"
/**
 * print_bin
 *@n:number decimal
 *Return: times of number print
 */
int print_bin(unsigned int n)
{
	unsigned int a, b, c, d, f;
	int count = 0;

	b = n;
	c = 1;
	for (a = 1 ; b > 1 ; a++)
	{
		b = b / 2;
		c = c * 2;
	}
	for (f = 1; f <= a; f++)
	{
		d = n / c;
		n = n % c;
		c = c / 2;
		_putchar(d + '0');
		count++;
	}
	return (count);
}
