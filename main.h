#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>


/**
 * typrdef struct fmt_fct fmt_t - define new type of struct fmt_fct
 * @fmt_fct: struct fmt_fct
 * @fmt_t: typedef fmt_fct
 */
typedef struct fmt_fct
{
	char *fmt;
	int (*fct)();
} fmt_t;

int _putchar(char c);
int _printf(const char *format, ...);

#endif
