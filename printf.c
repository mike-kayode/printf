#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - function that produce output
 * @format : character
 * Return: Return count
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int ch;
	const char *str;
	int num;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					ch = va_arg(args, int);
					putchar(ch);
					count++;
					break;
				case 's':
					str = va_arg(args, const char *);
					while (*str != '\0')
					{
						putchar(*str);
						str++;
						count++;
					}
					break;
				case '%':
					putchar('%');
					count++;
					break;
				case 'd':
				case 'i':
					num = va_arg(args, int);
					printf("%d", num);
					count += snprintf(NULL, 0, "%d", num);
					break;
				default:
					putchar('%');
					putchar(*format);
					count += 2;
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
