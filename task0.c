#include "main.h"

/**
 * _printf - function that simulates printf function
 * @format: format string
 * @...: variable parameters
 * Return: number of characters printed
 *
 */

int _printf(const char *format, ...)
{
	int num = 0;
	va_list compute;

	while (*format != '\0')
	{
		if (*format != '%')
		{
			write(1, format, sizeof(char));
			num++;
		}
		else
		{
			++format;
			va_start(compute, format);

			if (*format == 'c')
			{
				char chsamp = va_arg(compute, int);

				write(1, &chsamp, sizeof(char));
				num++;
			}
			else if (*format == 's')
			{
				char *strsamp = va_arg(compute, char *);
				int length = strlen(strsamp);

				write(1, strsamp, length);
				num++;
			}
			else if (*format == '%')
			{
				ampsamp();
				num++;
			}
		}
		format++;
	}
	va_end(compute);
	return (num);
}

/**
 * ampsamp - function that prints out the '%' sign
 *
 * Return: the '%' sign
 *
 */

char ampsamp(void)
{
	char ampsamp = '%';

	write(1, &ampsamp, sizeof(char));
	return ('%');
}
