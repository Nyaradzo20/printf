#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

int _printf(const char *format, ...)
{
    va_list ap;
    int i = 0;
    int l = strlen(format);


    va_start(ap, format);
    while (format[i] != '\0')
    {

        if (format[i] != '%')
        {
            putchar(format[i]);
        }
        else if (format[i] == '%' && format[i + 1] == 'd')
        {

            printf("%d", va_arg(ap, int));
            i++;
        }
        else if (format[i] == '%' && format[i + 1] == 'i')
        {

            printf("%d", va_arg(ap, int));
            i++;
        }
        else if (format[i] == '%' && format[i + 1] == 's')
        {
            printf("%s", va_arg(ap, char *));
            i++;
        }
        else if (format[i] == '%' && format[i + 1] == 'c')
        {
            putchar(va_arg(ap, int));
            i++;
        }
        else if (format[i] == '%' && format[i + 1] == '%')
        {
            l -= 1;
            putchar('%');
            i++;
        }
        i++;
    }

    va_end(ap);
    return (l);
}

int main(void)
{
    int len;
    int len2;
    /*unsigned int ui;
    void *addr;*/

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    /*ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;*/
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    /* _printf("Unsigned:[%u]\n", ui);
     printf("Unsigned:[%u]\n", ui);
     _printf("Unsigned octal:[%o]\n", ui);
     printf("Unsigned octal:[%o]\n", ui);
     _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
     printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);*/
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    /* _printf("Address:[%p]\n", addr);
     printf("Address:[%p]\n", addr);*/
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    /* _printf("Unknown:[%r]\n");
     printf("Unknown:[%r]\n");*/
    return (0);
}
