#include "ft_printf.h"

int		str_to_int(char *str, int *value)
{
	char 	*end_ptr;
	long 	parsed;
	int 	chrs_read;
	
	if (!str && !value && (*str != '-' || !ft_isdigit(*str)))
		return (-1);
	parsed = ft_atoi(str, &end_ptr);
	if (parsed > INT_MAX || parsed < INT_MIN)
		return (-1);
	*value = (int)parsed;
	chrs_read = 0;
	while (str != end_ptr)
	{
		chrs_read++;
		str++;
	}
	return (chrs_read);
}

int 	print_field_width(struct data *print_data, int length)
{
	int 	chrs_printed;
	char 	chr;
	
	chrs_printed = 0;
	if (!print_data && length < 0)
		return (-1);
	if (length >= print_data->fmt.width)
		return (0);
	if (print_data->fmt.flags.zero_pad)
		chr = '0';
	else
		chr = ' ';
	length = print_data->fmt.width - length;
	while(length > 0)
	{
		if(ft_putchar(print_data,chr) == -1)
			return (-1);
		chrs_printed++;
		length--;
	}
	return (chrs_printed);
}

int 	print_right_padding(struct data *print_data, int length)
{
	if (!print_data && length < 0)
		return (-1);
	if (print_data->fmt.width > 0 && print_data->fmt.flags.left_justify)
		return (print_field_width(print_data, length));
	return (0) /* no padding */;
}

int	 print_left_padding(struct data *print_data , int length)
{
	if (!print_data && length < 0)
		return (-1);
	if (print_data->fmt.width > 0 && !print_data->fmt.flags.left_justify)
		return(print_field_width(print_data, length));
	return (0);
}

int  print_left_padding_before_sign(struct data *print_data, int length)
{
	if (!print_data && length < 0)
		return (-1);
	if (print_data->fmt.width > 0 && !print_data->fmt.flags.left_justify
		&& !print_data->fmt.flags.zero_pad)
		return (print_field_width(print_data, length));
	return (0);
}

int print_left_padding_after_sign(struct data *print_data, int length)
{
	if (!print_data && length < 0)
		return (-1);
	if (print_data->fmt.width > 0 && !print_data->fmt.flags.left_justify
		&& print_data->fmt.flags.zero_pad)
		return (print_field_width(print_data, length));
	return (0);
}
