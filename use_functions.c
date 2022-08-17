#include "holberton.h"
#include <stdio.h>
/**
* write_base - function
* @str: string to convert
*
* Description: write base
* Return: string
*/
void write_base(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		_write_char(str[i]);
}

/**
 * _memcpy - copy memory area
 * @dest: Destination for copying
 * @src: Source to copy from
 * @n: The number of bytes to copy
 * Return: The _memcpy() function returns a pointer to dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
		dest[i] = '\0';
	return (dest);
}
/**
 * print_number - prints a number send to this function
 * @args: List of arguments
 * Return: The number of arguments printed
 */
int print_number(va_list args)
{
	int n;
	int div;
	int len;
	unsigned int num;

	n  = va_arg(args, int);
	div = 1;
	len = 0;

	if (n < 0)
	{
		len += _write_char('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / div > 9; )
		div *= 10;

	for (; div != 0; )
	{
		len += _write_char('0' + num / div);
		num %= div;
		div /= 10;
	}

	return (len);
}
/**
* _write_char - function
* @c: char to print
*
* Description: function to write chars to stdout
* Return: integer
*/
int _write_char(char c)
{
	return (write(1, &c, 1));
}
/**
* parser - function
* @format: string
* @f_list: struct
* @arg_list: struct
*
* Description: parse
* Return: integer
*/
int parser(const char *format, test_t f_list[], va_list arg_list)
{
	int i, j, r_val, printed_chars;

	printed_chars = 0;
	for (i = 0; format[i] != '\0'; i++) /* Iterates through the main str */
	{
		if (format[i] == '%') /*Checks for format specifiers */
		{
/*Iterates through struct to find the right func*/
			for (j = 0; f_list[j].sym != NULL; j++)
			{
				if (format[i + 1] == f_list[j].sym[0])
				{
					r_val = f_list[j].f(arg_list);
					if (r_val == -1)
						return (-1);
					printed_chars += r_val;
					break;
				}
			}
			if (f_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_write_char(format[i]);
					_write_char(format[i + 1]);
					printed_chars = printed_chars + 2;
				}
			else
				return (-1);
			}
			i = i + 1; /* Updating i to skip format symbols */
		}
		else
		{
			_write_char(format[i]); /*call the write function*/
			printed_chars++;
		}
	}
	return (printed_chars);
}
