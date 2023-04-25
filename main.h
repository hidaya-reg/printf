#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>


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
int print_str(va_list args);
int print_char(va_list args);
int print_pct(void);
int print_int(int n);
int print_bin(unsigned int n);


#endif
