#include "ft_printf.h"

int print_char (struct data *print_data, char 	chr)
{
	int 			chrs_printed;
	int 			temp;
	const int		length = 1; /*char is one character */
	
	chrs_printed = 0;
	if (!print_data)
		return (-1);
	print_data->fmt.flags.zero_pad = 0; /* useless with char */
	temp = print_left_padding(print_data, length);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	temp = ft_putchar(print_data, chr);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	temp = print_right_padding(print_data, length);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	return (chrs_printed);
	
}

int 	print_str(struct data *print_data, char *str)
{
	int 	length;
	int 	chrs_printed;
	int 	temp;
	
	if (!print_data || !str)
		return (-1);
	print_data->fmt.flags.zero_pad = 0;
	/* Useless in case of strings */
	/* Precision however can limit characters */
	length = ft_strlen(str);
	if (print_data->fmt.precision >= 0 && length > print_data->fmt.precision)
		length = print_data->fmt.precision;
	chrs_printed = length;
	temp = print_left_padding(print_data, length);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	/* Print the entire string of just some characters */
	if (print_data->fmt.precision >= 0)
	{
		temp = length; /* length <= strlen(str) */
		while (*str != '\0' && --temp >= 0)
		{
			if (ft_putchar(print_data, *str++) == -1)
				return (-1);
		}
	}
	else
		ft_putstr(print_data, str);
	temp = print_right_padding(print_data, length);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	return (chrs_printed);
}

int		generic_print_value(struct data *print_data, char chr, va_list args)
{
	if (!print_data)
		return (-1);
	print_data->fmt.type_specifier = chr;
	switch(chr)
	{
		case '\0':
			return (0);
		case 'X':
			print_data->fmt.flags.uppercase = T;
		case 'd':
		case 'i':
		case 'u':
		case 'o':
		case 'x':
		case 'p':
			return (print_general_int(print_data, chr, args));
		case 'c':
			return (print_char(print_data, (unsigned)va_arg(args, int)));
		case 's':
			return (print_str(print_data, va_arg(args, char *)));
		case '%':
			return (ft_putchar(print_data, '%'));
		default:
			return (-1);
	}
}
