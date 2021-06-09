#include "ft_printf.h"
#include "ft_printf_structs.h"

void	reset_format(format *fmt)
{
	fmt->flags.show_sign = 0;
	fmt->flags.left_align = 0;
	fmt->flags.initial_space = 0;
	fmt->flags.zero_pad = 0;
	fmt->flags.alternative_output = 0;
	fmt->flags.uppercase = 0;
	fmt->flags.trailing_zeroes = 1;
	fmt->field_width = 0;
	fmt->precision = -1;
	fmt->length_modifier = 0;
	fmt->specifier = 0;
}
void	reset_data(print_data *data)
{
	reset_format(&data->fmt);
	data->out_put.str = 0;
	data->out_put.str_ptr = 0; 
	data->out_put.chrs_printed = 0;
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/* str_to_int is a wrapper around strtol that saves result in result as an int and returns the number of characters consumed*/
int str_to_int(char *str, int *result)
{
	char 	*end_ptr;
	long 	parsed;
	int 	chrs_read;
	
	if (!str && !result && (*str == '-' || ft_isdigit(*str)))
		return (-1);
	parsed = strtol(str, &end_ptr, 10); /* change later */
	if (parsed > INT_MAX || parsed < INT_MIN)
		return (-1);
	*result = (int) parsed;
	chrs_read = 0;
	while (str != end_ptr)
	{
		chrs_read++;
		str++;
	}
	return (chrs_read);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

void 	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}
/* emit str prints string str and returns the length of the string */
int 	emit_str(print_data *data, char *str)
{
	int 	length;
	if (!data || !str)
		return (-1);
	length = ft_strlen(str);
	ft_putstr(str);
	strcat(data->out_put.str_ptr, str);  /* string h change later */
	data->out_put.str_ptr += length;
	return (length);
}

/* emit_chr write chr to stdout and returns 1 else error -1 */
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
/* Print_Str prints a string 'str' according to the format given in "data" and returns the number of chrs_printed or -1 */
int 	print_str(print_data *data, char *str)
{
	int 	length;
	int 	chrs_printed;
	int 	temp;
	
	if (!data || !str)
		return (-1);
	data->fmt.flags.zero_pad = 0;
	/* Useless in case of strings */
	/* Precision however can limit characters */
	length = ft_strlen(str);
	if (data->fmt.precision >= 0 && length > data->fmt.precision)
		length = data->fmt.precision;
	chrs_printed = length;
	temp = print_left_padding(data, length);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	/* Print the entire string of just some characters */
	if (data->fmt.precision >= 0)
	{
		temp = length; /* length <= strlen(str) */
		while (*str != '\0' && --temp >= 0)
		{
			if (emit_chr(data, *str++) == -1)
				return (-1);
		}
	}
	else
	{
		if (emit_str(data, str) == -1)
			return (-1);
	}
	temp = print_right_padding(data, length);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	return (chrs_printed);
}

/* print_char prints a char according to "data" and returns the number of characters printed or -1 */

int print_char (print_data *data, char 	chr)
{
	int 			chrs_printed;
	int 			temp;
	const int		length = 1; /*char is one character */
	
	chrs_printed = 0;
	if (!data)
		return (-1);
	data->fmt.flags.zero_pad = 0; /* useless with char */
	temp = print_left_padding(data, length);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	temp = emit_chr(data, length);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	return (chrs_printed);
	
}
