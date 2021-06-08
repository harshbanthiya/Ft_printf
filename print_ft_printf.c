#include "ft_printf.h"
#include "ft_printf_structs.h"

/* print_long prints values according to data and returns the number of characters printed or error of -1 */
int 	print_long(print_data	*data, long value)
{
	int 	chrs_printed;
	int 	length;
	int 	digits;
	int 	temp;
	
	chrs_printed = 0;
	length = 0;
	if (!data)
		return (-1);
	if (data->fmt.field_width)
		length = get_length_long(data, value);
	temp = print_left_padding_before_sign(data,length);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	/* Making sure that initial space is printed only if there is no sign */
	if (data->fmt.flags.show_sign && value >= 0)
		temp = emit_chr(data, '+');
	else if (value < 0)
		temp = emit_chr(data, '-');
	else if (data->fmt.flags.initial_space)
		temp = emit_chr(data, ' ');
	else
		temp = 0;
	
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	
	/* zeroes must be placed after the sign width zero pad flag */
	temp = print_left_padding_after_sign(data,length);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	
	/* precision with integer is the minimum number of digits to print */
	if (data->fmt.precision >= 0)
	{
		digits = get_nr_digits_long(value);
		/* if digits >= data->fmt.precision there is no print */
		digits = data->fmt.precision - digits;
		while(digits)
		{
			if(emit_chr(data, '0') == -1)
				return (-1);
			digits--;
			chrs_printed++;
		}
	}
	temp = print_long_rec(data, value);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	temp = print_right_padding(data, length);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	return (chrs_printed);
}

/* print_unsigned long: prints "value" according to "data" and "base" and returns the number of characaters printed or error -1
 Base must be valid (8, 10, 16) */
int		print_unsigned_long(print_data *data, unsigned long value, int base)
{
	int		chrs_printed;
	int 	length;
	int 	digits;
	int 	temp;
	
	chrs_printed = 0;
	length = 0;
	if (!data)
		return (-1);
	/* Value used for padding */
	if (data->fmt.field_width > 0)
		length = get_length_unsigned_long(data, value, base);
	temp = print_left_padding(data, length);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	/* Print precision */
	if (data->fmt.precision >= 0)
	{
		digits = get_nr_digits_unsigned_long(value, base);
		digits = data->fmt.precision - digits;
		while(digits)
		{
			if(emit_chr(data, '0') == -1)
				return (-1);
			digits--;
			chrs_printed++;
		}
	}
	
	/* Because zero doesn't have the base prefix */
	if (value != 0 && data->fmt.flags.alternative_output && base != 10)
	{
		temp = emit_str(data, UNSIGNED_SYMBOL(data, base));
		if (temp == -1)
			return (temp);
		else
			chrs_printed += temp;
	}
	temp = print_unsigned_long_rec(data, value, base);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	temp = print_right_padding(data, length);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	return chrs_printed;
}

/* print_generic_int: prints an integer taken from args according to "chr" conversion specifier and returns number of chars prints and error -1*/
int 	print_generic_int(print_data *data, char chr, va_list args)
{
	int 	base;
	union
	{
		long l;
		unsigned long lu;
	}value;
	
	if (!data)
		return (-1);
	/* Zero Padding ignored if precision is given with integers */
	if (data->fmt.precision >= 0 && data->fmt.flags.zero_pad)
		data->fmt.flags.zero_pad = 0;
	/* Calcuating the base for unsigned value */
	switch (chr)
	{
		case 'X':
		case 'x':
			base = 16;
			break;
		case 'o':
			base = 8;
			break;
		case 'u':
			base = 10;
			break;
		default:
			break;
	}
	/* promote ints to longs and short to ints as required in varadic arguments */
	switch (chr)
	{
		case 'd':
		case 'i':
			if (data->fmt.length_modifier == 'l')
				value.l = va_arg(args, long);
			else
				value.l = va_arg(args, int);
			return (print_long(data, value.l));
		case 'X':
			data->fmt.flags.uppercase = 1;
		case 'x':
		case 'o':
		case 'u':
			if(data->fmt.length_modifier == 'l')
				value.lu = va_arg(args, unsigned long);
			else
				value.lu = va_arg(args, unsigned int);
			return print_unsigned_long(data, value.lu, base);
		default:
			return (-1);
	}
}


/* generic_print_value: prints a value taken in "args" according to "chr" conversion specifier and return the number of characters returned*/
int 	generic_print_value(print_data *data, char chr, va_list args)
{
	int 	*n_ptr;
	
	if(!data)
		return (-1);
	data->fmt.specifier = chr;
	switch(chr)
	{
		case '\0': /* Do nothing*/
			return (0);
		case 'X':
			data->fmt.flags.uppercase = 1;
		case 'd':
		case 'i':
		case 'u':
		case 'o':
		case 'x':
			return print_generic_int(data, chr, args);
		case 'c':
			return print_char(data, (unsigned)va_arg(args, int));
		case 's':
			return print_str(data, va_arg(args, char *));
		case '%':
			return emit_chr(data, '%');
		case 'f':
		case 'e':
		case 'g':
			return print_generic_double(data, va_arg(args, double));
		case 'n':
			n_ptr = va_arg(args, int *);
			if(!n_ptr)
				return (-1);
			else
				*n_ptr = data->out_put.chrs_printed;
		default: /* unrecoginsed specifier */
			return (-1);
	}
}

