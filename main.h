#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 * struct test - defines a structure for symbols and functions
 *
 * @sym: The operator
 * @f: The function associated
 */
struct test
{
	char *sym;

	int (*f)(va_list);
};
typedef struct test test_t;

/* Main functions */
int parser(const char *format, test_t f_list[], va_list arg_list);
int _printf(const char *format, ...);
int _write_char(char c);
int print_char(va_list list);
int print_string(va_list list);
int print_percent(va_list list);
int print_integer(va_list list);
int print_number(va_list list);

/*Helper functions*/
void write_base(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);


#endif
