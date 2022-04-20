#include "main.h"
#include <stdarg.h>
int _printf(const char *format, ...)
{
  va_list ap;
  int i = 0;
  int length = 0;/*replaced the strlen*/
  int *p;
 
  va_start(ap, format);
  while (format[i] != '\0')
    {

      if (format[i] != '%')
	{
	  _putchar(format[i]);
	  length++;
	}
      else if (format[i] == '%' && format[i + 1] == 'd')
	{

	  _putchar("%d", va_arg(ap, int));
	  length++;
	  i++;
	}
      else if (format[i] == '%' && format[i + 1] == 'i')
	{

	  _putchar("%d", va_arg(ap, int));
	  length++;
	  i++;
	}
      else if (format[i] == '%' && format[i + 1] == 's')
	{
	  _putchar("%s", va_arg(ap, char *));
	  i++;
	}
      else if (format[i] == '%' && format[i + 1] == 'c')
	{
	  p = va_arg(ap, int);
	  _putchar(p);
	  i++;
	}
      else if (format[i] == '%' && format[i + 1] == '%')
	{
	  length -= 1;
	  _putchar('%');
	  length++;
	  i++;
	}
      i++;
    }

  va_end(ap);
  return (length);
}
