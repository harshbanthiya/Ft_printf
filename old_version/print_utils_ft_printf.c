#include "ft_printf.h"
#include "ft_printf_structs.h"

/* get_nr_digits_long tries to get the number of digits */
int 	get_nr_digits_long(long number)
{
	int 	digits;
	
	/* A number will atleast have 1 digit */
	digits = 1;
	number /= DIVISOR10(number);
	while (number)
	{
		digits++;
		number /= DIVISOR10(number);
	}
	return (digits);
}

/* get_nr_digits_unsigned_long to get the number of digits in "number" */
int 	get_nr_digits_unsigned_long(unsigned long number, int base)
{
	int 	digits;
	digits = 1;
	number /= base;
	while(number != 0)
	{
		digits++;
		number /= base;
	}
	return digits;
}
/* returns the number of characters that should be printed with 'value' according to 'data', except for field width, with "%d" format */
/* Used to calculate the pad for field width */

int get_length_long (print_data *data, long value)
{
	print_data		temp;
	temp = *data;
	temp.fmt.field_width = 0;
	/* Print_long is used to get the number of characters to be printed, I create another data struct to avoid printing and padding */
	return (print_long(&temp, value));
}

/* returns the number of characters that should be printed with 'value' according to 'data', except for field width, with "%d" format */
/* Used to calculate the pad for field width */

int get_length_unsigned_long(print_data *data, unsigned long value, int base)
{
	print_data temp;
	
	temp = *data;
	temp.fmt.field_width = 0;
	return (print_unsigned_long(&temp, value, base));
}

/* recursive function called by print_long that prints each digit of "value" and returns the number of characters printed or error */
int 	print_long_rec(print_data *data, long value)
{
	int 	chrs_printed;
	char 	out;
	
	chrs_printed = 0;
	if (!data)
		return (-1);
	if (value == 0)
	{
		if (data->fmt.precision != 0)
			chrs_printed += emit_chr(data, '0');
		return (chrs_printed);
	}
	if (value / DIVISOR10(value) != 0)
		chrs_printed = print_long_rec(data, value / DIVISOR10(value));
	if (value < 0)
		out = '0' + -(value % -10);
	else
		out = '0' + value % 10;
	if (emit_chr(data, out) == -1)
		return (-1);
	else
		return (chrs_printed + 1);
}

/* print_unsigned_long_rec: recursive function called by print_unsigned_long to print each digit of "value"; it returns the number of chrs printed or error */
int		print_unsigned_long_rec(print_data *data, unsigned long value, int base)
{
	int 			chrs_printed;
	unsigned short	remainder;
	char 			out;
	unsigned long 	div;
	
	if (!data)
		return (-1);
	chrs_printed = 0;
	if (value == 0)
	{
		if (data->fmt.precision != 0)
			chrs_printed = emit_chr(data, '0');
		return (chrs_printed);
	}
	div = value / base;
	if (div != 0)
	{
		chrs_printed = print_unsigned_long_rec(data, div, base);
		if (chrs_printed == -1)
			return (-1);
	}
	remainder = value % base;
	if (remainder > 9)
		out = remainder - 10 + (data->fmt.flags.uppercase ? 'A' : 'a');
	else
		out = remainder + '0';
	if (emit_chr(data, out) == -1)
		return (-1);
	else
		return (chrs_printed + 1);
}

/* print_field_width: pads the output according to "data" and "length" and returns the number of characters printed or error
 length must be length of output except for padding */

int 	print_field_width(print_data *data, int length)
{
	int 	chrs_printed;
	char 	chr;
	
	chrs_printed = 0;
	if (!data && length < 0)
		return (-1);
	if (length >= data->fmt.field_width)
		return (0);
	if (data->fmt.flags.zero_pad)
		chr = '0';
	else
		chr = ' ';
	length = data->fmt.field_width - length;
	while(length)
	{
		if(emit_chr(data, chr) == -1)
			return (-1);
		length--;
		chrs_printed++;
	}
	return (chrs_printed);
}

/* print_right_padding: pads the output with spaces on the right and returns the number of space printed or error
length must be a positive integer */

int 	print_right_padding(print_data *data, int length)
{
	if (!data && length < 0)
		return (-1);
	if (data->fmt.field_width > 0 && data->fmt.flags.left_align)
		return (print_field_width(data, length));
	return (0) /* no padding */;
}

/* print_left_padding_after_sign: pads the output with zeroes on the left and returns the number of space printed or error
 length must be a positive integer */

int		print_left_padding_after_sign(print_data *data, int length)
{
	if (!data && length < 0)
		return (-1);
	if (data->fmt.field_width > 0
		&& !data->fmt.flags.left_align
		&& data->fmt.flags.zero_pad)
		return (print_field_width(data,length));
	return (0)/* no padding */;
}

/* print_left_padding_before_sign: pads the output with spaces on the left and returns the number of space printed or error
 length must be a positive integer indicating length of output except for padding */

int		print_left_padding_before_sign(print_data *data, int length)
{
	if (!data && length < 0)
		return (-1);
	if (data->fmt.field_width > 0
		&& !data->fmt.flags.left_align
		&& !data->fmt.flags.zero_pad)
		return (print_field_width(data,length));
	return (0)/* no padding */;
}

/* print_left_padding: pads the output with spaces or zeroes on the left and returns the number of space printed
 length must be a positive integer */

int	 print_left_padding(print_data *data, int length)
{
	if (!data && length < 0)
		return (-1);
	if (data->fmt.field_width > 0 && !data->fmt.flags.left_align)
		return(print_field_width(data, length));
	return (0);
}

