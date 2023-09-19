#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - produces output
 * @format: character string
 * Return: number of chars printed
 */
int _printf(const char *format, ...)
{
	int count = 0;

	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
				{
					char c = va_arg(args, int);
					putchar(c);
					count++;
					break;
				}
				case 's':
				{
					char *s = va_arg(args, char*);
					while (*s != '\0')
					{
						putchar(*s);
						s++;
						count++;
					}
					break;
				}
				case '%':
					putchar('%');
					count++;
					break;
				default:
					break;
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
