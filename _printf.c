#include "main.h"
#include "stdio.h"
#include <stdlib.h>
int _printf(char *format, ...)
{
  va_list ap;
  va_start(ap, format);
  
  int k = 0;
  int i = 0;
  int length = 0;

  while (format && format[i])
    {
      if (k == 0)
	{
	  if (*format != '%' && *format != '\n')
	    {
	      _putchar(*format);
	      length++;
	    }
	  else if (*format == '\n')
	    {
	      _putchar('\n');
	      length++;
	    }

	  else
	    {
	      k = 1;
	    }
	}
      else if (k == 1)
	{
	  switch (*format)
	    {
	    case 's':
	      {
		char *str = va_arg(ap, char *);
		
		while (*str)
		  {
		    _putchar(*str++);
		    length++;
		  }
		break;
	      }
	    case 'c':
	      {
		int ch = va_arg(ap, int);
		_putchar(ch);
		length++;
		break;
	      }
	    case 'd':
	      {
		int ch = va_arg(ap, int);
		char buff[100];
		char *buff1 = itoa(ch, buff, 10);
		while (*buff1)
		  {
		    length++;
		    putchar(*buff1++);
		  }

		break;
	      }
	    case 'i':
	      {
		int ch = va_arg(ap, int);
		char *buff = itoa(ch, buff, 10);
		while (*buff)
		  {
		    length++;
		    putchar(*buff++);
		  }

		break;
	      }
	    case '%':
	      {

		_putchar('%');
		length++;
		break;
	      }
	    }
	  k = 0;
	}

      format++;
    }
  va_end(ap);

  return (length);
}

int main()
{
  int len = _printf("Let's try to printf a simple sentence .\n");
  int len2 = printf("Let's try to printf a simple sentence .\n");

  _printf("Length:[%i]\n", len);
  printf("Length:[%d]\n", len2);
}
