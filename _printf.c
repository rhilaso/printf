#include "main.h"

/**
 * print_buffer - prints out buffer contents
 * @buffer: Array
 * @buff_ind: lenght or index of next character
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}

/**
 * _printf - a function that prints anything
 * @format: the format string
 * Return: printed bytes
 */

int _printf(const char *format, ...)
{
	va_list cad;
	int i = 0;
	int printed = 0;
	int disp_chars = 0;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(cad, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			disp_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, cad);
			precision = get_precision(format, &i, cad);
			size = get_size(format, &i);
			++i;
			printed = handle print(format, &i, list, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			disp_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(cad);
	return (disp_chars);
}


