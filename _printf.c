#include "holberton.h"
/**
* _printf - function
* @format: string to print
*
* Description: function to print specifiers c, s, %, d, and i
* Return: printed chars
*/
int _printf(const char *format, ...)
{
	int printed_chars;

	test_t f_list[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{NULL, NULL}
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
/*Calling parser function*/
	printed_chars = parser(format, f_list, arg_list);
	va_end(arg_list);
	return (printed_chars);
}
