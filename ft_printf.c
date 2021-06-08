#include "ft_printf.h"
#include "ft_printf_structs.h"

/* generic_print prints an output according to the arguments and returns
	the number of characters printed, or -1 on error */

int 	emit_chr(print_data	*data, char chr)
{
	if (!data)
		return (-1);
	if (chr == -1)
		return (-1);
	write(1, &chr, 1);
	*data->out_put.str_ptr++ = chr;
	*data->out_put.str_ptr = '\0';
	return (1);
}

int 	generic_print(print_data *data, char *format, va_list args)
{
	char 	*chr;
	int 	chrs_printed;
	int 	temp;
	
	if(!data || !format)
		return (-1);
	chrs_printed = 0;
	chr = format;
	while (*chr)
	{
		if (*chr != '%')
		{
			temp = emit_chr(data, *chr);
			if (temp == -1)
				return (-1);
			chrs_printed += temp;
			continue;
		}
		temp = parse_format(data, ++chr, args);
		if (temp == -1)
			return (-1);
		chr += temp;
		
			
	}
}

int 	ft_printf(char 	*format, ...)
{
	int 		return_val;
	va_list		args;
	print_data	data;
	
	va_start(args, format);
	reset_data(&data);
	return_val = generic_print(&data, format, args);
	va_end(args);
	return (return_val);
}


