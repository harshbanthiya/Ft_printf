#include "ft_printf.h"

int 	parse_flags(struct data *print_data, char *str)
{
	int 	chrs_read;
	int 	is_flag;
	
	if (!print_data || !str)
		return (-1);
	chrs_read = 0;
	is_flag = 1;
	while(is_flag)
	{
		switch(*str)
		{
			case '+':
				print_data->fmt.flags.show_sign = T;
				break;
			case '-':
				print_data->fmt.flags.left_justify = T;
				break;
			case ' ':
				print_data->fmt.flags.initial_space = T;
				break;
			case '#':
				print_data->fmt.flags.alternate_output = T;
				break;
			case '0':
				print_data->fmt.flags.zero_pad = T;
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
	/* conflict resolve */
	if(print_data->fmt.flags.zero_pad && print_data->fmt.flags.left_justify)
		print_data->fmt.flags.zero_pad = F;
	if (print_data->fmt.flags.initial_space && print_data->fmt.flags.show_sign)
		print_data->fmt.flags.initial_space = F;
	return (chrs_read);
}

int		parse_field_width(struct data *print_data, char *str, va_list args)
{
	int 	chrs_read;
	int 	field_width;
	int 	temp;
	
	if(*str == 0 || *str == '.'|| (!ft_isdigit(*str) && *str != '*'))
		return (0);
	chrs_read = 0;
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
		print_data->fmt.flags.left_justify = 1;
		if (INT_MAX + field_width < 0)
			return (-1); /* Overflow */
		else
			field_width = -field_width;
	}
	print_data->fmt.width = field_width;
	return (chrs_read);
}

int 	parse_precision(struct data *print_data, char *str, va_list args)
{
	int 	chrs_read;
	int 	precision;
	
	if (!print_data || !str)
		return (-1);
	chrs_read = 0;
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
		if (chrs_read == -1)
			return (-1);
	}
	else
		precision = 0;
	if (precision >= 0)
		print_data->fmt.precision = precision;
	return (chrs_read);
}

int 	parse_length_modifier(struct data *print_data, char chr)
{
	if (!print_data)
		return (-1);
	switch(chr)
	{
		case 'h':
		case 'l':
		case 'L':
			print_data->fmt.length_modifier = chr;
			break;
		default:
			break;
	}
	if (print_data->fmt.length_modifier)
		return (1);
	else
		return (0);
}

int 	parse_format_info(struct data *print_data, char *str, va_list args)
{
	int 	temp;
	int 	chrs_read;
	
	if(!print_data || !str || *str == '\0')
		return(-1);
	chrs_read = 0;
	reset_format_info(&print_data->fmt);
	/* First parse flags */
	temp = parse_flags(print_data, str);
	if (temp == -1)
		return (-1);
	else
	{
		chrs_read += temp;
		str += temp;
	}
	/* Parse field width */
	temp = parse_field_width(print_data, str, args);
	if (temp == -1)
		return (-1);
	else
	{
		chrs_read += temp;
		str += temp;
	}
	/* Parse Precision */
	temp = parse_precision(print_data, str, args);
	if (temp == -1)
		return (-1);
	else
	{
		chrs_read += temp;
		str += temp;
	}
	/* Parse Length Modifier */
	temp = parse_length_modifier(print_data, *str);
	if (temp == -1)
		return (-1);
	else
	{
		chrs_read += temp;
		str += temp;
	}
	return (chrs_read);
}
