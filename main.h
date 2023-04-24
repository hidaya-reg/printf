#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * struct fmt_fct - Structure to map format with appropriate function
 * to print it
 * @fmt: format
 * @fct: function to print @format
 */

struct fmt_fct
{
	char fmt;
	int (*fct)(va_list);
};

/**
 * typrdef struct fmt_fct fmt_t - define new type of struct fmt_fct
 * @fmt_fct: struct fmt_fct
 * @fmt_t: typedef fmt_fct
 */
typedef struct fmt_fct fmt_t;

int _putchar(char c);
int _printf(const char *format, ...);

#endif
