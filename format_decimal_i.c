#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * custom_printf - produce output with d and i specifiers
 * @format: required format
 * Return: characers printed
 */
int custom_printf(const char *format, ...)
{
	int count = 0;

	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
			int num = va_arg(args, int);

			printf("%d\n", num);
			count += num < 0 ? 2 : 1;
		}
		else
		{
			putchar('%');
			count++;
		}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
