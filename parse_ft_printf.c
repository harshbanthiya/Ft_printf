/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:57:41 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/06/21 15:15:05 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	parse_flags(t_data *print_data, char *str)
{
	int		chrs_read;
	int		is_flag;

	if (!print_data || !str)
		return (-1);
	chrs_read = 0;
	is_flag = 1;
	while (is_flag)
	{
		is_flag = update_flags(print_data, *str);
		if (is_flag)
		{
			str++;
			chrs_read++;
		}
	}
	conflict_resolve(print_data);
	return (chrs_read);
}

int	parse_field_width(t_data *print_data, char *str, va_list args)
{
	int		chrs_read;
	int		field_width;
	int		temp;

	if (*str == 0 || *str == '.' || (!ft_isdigit(*str) && *str != '*'))
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
		return (negative_field_width(print_data, &field_width, &chrs_read));
	print_data->width = field_width;
	return (chrs_read);
}

int 	parse_precision(t_data *print_data, char *str, va_list args)
{
	int		chrs_read;
	int		precision;

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
		chrs_read += str_to_int(str, &precision);
	else
		precision = 0;
	if (precision >= 0)
		print_data->precision = precision;
	return (chrs_read);
}

int 	parse_length_modifier(t_data *print_data, char chr)
{
	if (!print_data)
		return (-1);
	if (chr == 'h' || chr == 'l' || chr == 'L')
		print_data->length_modifier = chr;
	if (print_data->length_modifier)
		return (1);
	else
		return (0);
}


