#include "ft_printf.h"


static int get_number_of_digits(long value)
{
	int 	digits;
	
	digits = 1;
	while((value /= DIVISOR_10_SIGN(value)) != 0)
		digits++;
	return digits;
}
static int get_number_digits_unsigned(unsigned long number, int base)
{
	int 	digits;
	
	digits = 1;
	while ((number /= base) != 0)
		digits++;
	return digits;
}
int get_length_unsigned(struct data *print_data, unsigned long value, int base)
{
	struct data	temp;
	temp = *print_data;
	temp.output.mode = OUTPUT_NONE;
	temp.fmt.width = 0;
	return(print_unsigned_long(&temp, value, base));
}

char *unsigned_symbol(struct data *print_data, int base)
{
	char *octal_base = "0";
	char *hex_lower = "0x";
	char *hex_upper = "0X";
	
	if (base == 8)
		return (octal_base);
	else
	{
		if (print_data->fmt.flags.uppercase)
			return (hex_upper);
		else
			return (hex_lower);
	}
}

int ft_put_unsigned_nbr(struct data *print_data, unsigned long value, int base)
{
	int 			chrs_printed;
	unsigned short	remainder;
	char 			out;
	
	if (!print_data)
		return (-1);
	chrs_printed = 0;
	if (value == 0)
	{
		if (print_data->fmt.precision != 0)
			chrs_printed = ft_putchar(print_data, '0');
		return (chrs_printed);
	}
	
	if (value / base)
		chrs_printed = ft_put_unsigned_nbr(print_data, value / base , base);
	if (chrs_printed == -1)
		return (-1);
	remainder = value % base;
	if (remainder >= 10)
		out = remainder - 10 + (print_data->fmt.flags.uppercase ? 'A' : 'a');
	else
		out = remainder + '0';
	ft_putchar(print_data, out);
	return (chrs_printed + 1);
}

int print_unsigned_long(struct data *print_data, unsigned long value, int base)
{
	int 	chrs_printed;
	int 	length;
	int 	digits;
	int 	temp;
	
	chrs_printed = 0;
	length = 0;
	if (!print_data)
		return (-1);
	if (print_data->fmt.width > 0)
		length = get_length_unsigned(print_data, value, base);
	temp = print_left_padding(print_data, length);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	if (print_data->fmt.precision >= 0)
	{
		digits = get_number_digits_unsigned(value, base);
		digits = print_data->fmt.precision - digits;
		while (digits > 0)
		{
			ft_putchar(print_data, '0');
			digits--;
			chrs_printed++;
		}
	}
	if (value != 0 && print_data->fmt.flags.alternate_output
			&& base != 10)
	{
		temp = ft_putstr(print_data, (unsigned_symbol(print_data, base)));
		if (temp == -1)
			return (-1);
		else
			chrs_printed += temp;
	}
	temp = ft_put_unsigned_nbr(print_data, value, base);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	temp = print_right_padding(print_data, length);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	return(chrs_printed);
}

int print_long(struct data *print_data, long value)
{
	int 	chrs_printed;
	int 	length;
	int 	digits;
	int 	temp;
	
	if (!print_data)
		return (-1);
	chrs_printed = 0;
	length = 0;
	if (print_data->fmt.width > 0)
		length = get_length_long(print_data, value);
	temp = print_left_padding_before_sign(print_data, length);
	if(temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	if (print_data->fmt.flags.show_sign && value >= 0)
		temp = ft_putchar(print_data, '+');
	else if (value < 0)
		temp = ft_putchar(print_data, '-');
	else if (print_data->fmt.flags.initial_space)
		temp = ft_putchar(print_data, ' ');
	else
		temp = 0;
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	temp = print_left_padding_after_sign(print_data, length);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	if (print_data->fmt.precision >= 0)
	{
		digits = get_number_of_digits(value);
		digits = print_data->fmt.precision - digits;
		while(digits > 0)
		{
			ft_putchar(print_data, '0');
			digits--;
			chrs_printed++;
		}
	}
	temp = ft_putnbr(print_data, value);
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

int get_length_long(struct data *print_data, long value)
{
	struct data 	temp;
	
	temp = *print_data;
	temp.output.mode = OUTPUT_NONE;
	temp.fmt.width = 0;
	
	return (print_long(&temp, value));
}


int print_general_int(struct data *print_data, char chr, va_list args)
{
	union
	{
		void			*p;
		long unsigned 	lu;
		long			l;
	}value;
	int 	base;
	
	if (!print_data)
		return (-1);
	if (print_data->fmt.precision >= 0 && print_data->fmt.flags.zero_pad)
		print_data->fmt.flags.zero_pad = 0;
	if (chr == 'p')
	{
		if (sizeof(void *) > sizeof(unsigned long))
			return (-1);
		print_data->fmt.flags.alternate_output = 1;
	}
	switch (chr)
	{
		case 'X':
		case 'x':
		case 'p':
			base = 16;
			break;
		case 'o':
			base = 8;
			break;
		case 'u':
			base = 10;
			break;
		default: /* 'd' and 'i' */
			break;
	}
	switch (chr)
	{
		case 'p':
			value.p = va_arg(args, void *);
			value.lu = (unsigned long)value.p;
			return (print_unsigned_long(print_data, value.lu, base));
		case 'd':
		case 'i':
			if(print_data->fmt.length_modifier == 'l')
				value.l = va_arg(args, long);
			else
				value.l = va_arg(args, int);
			return print_long(print_data,value.l);
		case 'X':
			print_data->fmt.flags.uppercase = T;
		case 'x':
		case 'o':
		case 'u':
			if (print_data->fmt.length_modifier == 'l')
				value.lu = va_arg(args, unsigned long);
			else
				value.lu = va_arg(args, unsigned int);
			return print_unsigned_long(print_data, value.lu, base);
		default:
			return (-1);
	}
}

