#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * cs_printf - custom printf
 * Return: chars printed
 */
int cs_printf(const char *format, ...){
	int len = 0;
	char spec = *format;

	va_list args;
	va_start(args, format);

	while (*format){
		if (*format == '%' && format[1] != '%'){
			format++;

			if (spec == 'd' || spec == 'i' || spec == 'u') {
				len += printf("%s:[%d]\n", spec == 'u' ? "Unsigned" : "Negative", va_arg(args, int));
			} else if (spec == 'o' || spec == 'x' || spec == 'X') {
				len += printf("%s:[%#o, %#x]\n",
					       	spec == 'o' ? "Unsigned octal" : "Unsigned hexadecimal",
						va_arg(args, unsigned int), va_arg(args, unsigned int));
			} else if (spec == 'c') {
				len += printf("Character:[%c]\n", va_arg(args, int));
			} else if (spec == 's') {
				len += printf("String:[%s]\n", va_arg(args, const char *));
			} else if (spec == 'p') {
				len += printf("Address:[%p]\n", va_arg(args, void *));
			} else if (spec == '%') {
				len += printf("Percent:[%%]\n");
			} else {
				len += printf("Unknown:[%%%c]\n", spec);
			}
		} else {
			putchar(*format);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}
