#include "main.h"

/**
 * print_dec - print out integer and return its length
 * @args: arguments
 * Return: integer's length
 */

int print_dec(va_list args)
{
        int num = va_arg(args, int);
        unsigned int abs_num, test_power, power, len = 1;


        if (num < 0)
        {
                _putchar('-');
                num = num * (-1);
                len++;
        }

        abs_num = num;
        power = 1;
        test_power = 1;

        while (test_power)
        {
                if (abs_num / (power * 10) > 0)
                        power *= 10;
                else
                        test_power = 0;
        }

        test_power = 1;
        while (test_power)
        {
                if (power == 1)
                {
                        _putchar(abs_num % 10 +'0');
                        test_power = 0;
                }
                else
                {
                        _putchar((abs_num / power % 10) + '0');
                        power /= 10;
                        len++;
                }
        }
        return (len);
}
