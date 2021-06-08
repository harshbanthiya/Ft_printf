#include "ft_printf.h"
#include "ft_printf_structs.h"

/*	parse-flags parses flag characters and updates them to format struct and returns number of char read*/
int 	parse_flags(print_data *data, char *str)
{
	int 	is_flag;
	int 	chrs_read;
	
	is_flag = 1;
	chrs_read = 0;
	while(is_flag)
	{
		switch (*str)
		{
			case '-':
				data->fmt.flags.left_align = 1;
				break;
			case '+':
				data->fmt.flags.show_sign = 1;
				break;
			case ' ':
				data->fmt.flags.initial_space = 1;
				break;
			case '0':
				data->fmt.flags.zero_pad = 1;
				break;
			case '#':
				data->fmt.flags.alternative_output = 1;
				break;
			default:
				is_flag = 0;
				break;
		}
		if (is_flag)
		{
			str++;
			chrs_read++;
		}
	}
	/* Straight Conflicts resolve */
	if (data->fmt.flags.zero_pad && data->fmt.flags.left_align)
		data->fmt.flags.zero_pad = 0;
	if (data->fmt.flags.initial_space && data->fmt.flags.show_sign)
		data->fmt.flags.initial_space = 0;
	return (chrs_read);
}

int 	parse_field_width(print_data *data, char *str, va_list args)
{
	int 	chrs_read;
	int 	field_width;
	int 	temp;
	
	chrs_read = 0;
	if(*str == 0 || *str == '.' || (!ft_isdigit(*str) && *str != '*'))
		return (0);
	if (*str == '*')
	{
		chrs_read++;
		field_width = va_arg(args, int);
	}
	else
	{
		temp = str_to_int(str, &field_width);
		if (temp == -1)
			return (-1);
		chrs_read += temp;
	}
	if (field_width < 0)
	{
		data->fmt.flags.left_align = 1;
		if (INT_MAX + field_width < 0)
			return (-1); /* OVerflow*/
		else
			field_width = -field_width;
	}
	data->fmt.field_width = field_width;
	return (chrs_read);
}

/* parse precision parses precision and saves value on data->fmt.precision and returns characters read and error is -1 */
int 	parse_precision(print_data *data, char 	*str, va_list args)
{
	int 	chrs_read;
	int 	precision;
	
	chrs_read = 0;
	if (!data || !str)
		return (-1);
	if (*str != '.')
		return (chrs_read);
	chrs_read++;
	str++;
	if (*str == '*')
	{
		chrs_read++;
		precision = va_arg(args, int);
	}
	else if (ft_isdigit(*str) || *str == '-')
	{
		chrs_read += str_to_int(str, &precision);
		if(chrs_read == -1)
			return (-1);
	}
	else
		precision = 0;
	/* Negative precision is taken as if it is omitted */
	if (precision >= 0)
		data->fmt.precision =precision;
	return (chrs_read);
}
/* parses optional length modifier for 'h' 'l' 'L' saves value on data->fmt.length_modifier return 1 if good else 0*/
int 	parse_length_modifier(print_data *data, char chr)
{
	if (!data)
		return (-1);
	switch(chr)
	{
		case 'h':
		case 'l':
		case 'L':
			data->fmt.length_modifier = chr;
			break;
		default: /* no modifier present */
			break;
	}
	if (data->fmt.length_modifier)
		return (1);
	else
		return (0);
}

/* parse format parses format string except the conversion specifier
	the *str  must start after '%' character and returns number of chars read
	returns error othewise */
int		parse_format(print_data *data, char *str, va_list args)
{
	int 	temp;
	int 	chrs_read;
	
	if (!data || !str || !*str)
		return (-1);
	chrs_read = 0;
	reset_format(&data->fmt);
	/* flag parsing */
	temp = parse_flags(data, str);
	if (temp == -1)
		return (-1);
	else
	{
		chrs_read += temp;
		str += temp;
	}
	/* Field Width */
	temp = parse_field_width(data, str, args);
	if (temp == -1)
		return (-1);
	else
	{
		chrs_read += temp;
		str += temp;
	}
	/* Precision */
	temp = parse_precision(data, str, args);
	if (temp == -1)
		return (-1);
	else
	{
		chrs_read += temp;
		str += temp;
	}
	/*	Length Modifier */
	return (chrs_read + parse_length_modifier(data, *str));
}
