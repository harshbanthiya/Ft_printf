#include "ft_printf.h"

int	general_print(struct data *print_data, char *str, va_list args)
{
	int 	chrs_printed;
	char	*chr;
	int 	temp;
	
	if(!print_data || !str)
		return (-1);
	chrs_printed = 0;
	chr = str;
	while(*chr)
	{
		if(*chr != '%')
		{
  			temp = ft_putchar(print_data, *chr);
			if (temp == -1)
				return (-1);
			chrs_printed += temp;
			chr++;
			continue;
		}
		temp = parse_format_info(print_data, ++chr, args);
		if (temp == -1)
			return (-1);
		chr += temp;
		temp = generic_print_value(print_data, *chr, args);
		if (temp == -1)
			return (-1);
		chrs_printed += temp;
		chr++;
		print_data->output.chrs_printed = chrs_printed;
	}
	return (chrs_printed);
}

/* printf takes a string and variable number of arguments and returns the number of chars printed */
int 	ft_printf(char	*format, ...)
{
	int			chrs_printed;
	va_list 	args;
	struct data print_data;
	
	
	if (!format)
		return (-1);
	chrs_printed = 0;
	va_start(args, format);
	reset_data(&print_data);
	print_data.output.mode = OUTPUT_STDOUT;
	chrs_printed = general_print(&print_data, format, args);
	va_end(args);
	return (chrs_printed);
}
