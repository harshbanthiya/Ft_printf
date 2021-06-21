/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:38:55 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/06/21 16:18:36 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	generic_print_value(t_data *print_data, char chr, va_list args)
{
	if (!print_data)
		return (-1);
	print_data->type_specifier = chr;
	if (chr == '\0')
		return (0);
	else if (chr == 'X')
	{
		print_data->s_flags.uppercase = T;
		return (print_general_int(print_data, chr, args));
	}
	else if (chr == 'd' || chr == 'i' || chr == 'u')
		return (print_general_int(print_data, chr, args));
	else if (chr == 'o' || chr == 'x' || chr == 'p')
		return (print_general_int(print_data, chr, args));
	else if (chr == 'c')
		return (print_char(print_data, (unsigned)va_arg(args, int)));
	else if (chr == 's')
		return (print_str(print_data, va_arg(args, char *)));
	else if (chr == '%')
		return (ft_putchar(print_data, '%'));
	else
		return (-1);
}

int	parse_format_info(t_data *print_data, char *str, va_list args)
{
	int		temp;
	int		chrs_read;

	if (!print_data || !str || *str == '\0')
		return (-1);
	chrs_read = 0;
	reset_data(print_data);
	temp = parse_flags(print_data, str);
	chrs_read += temp;
	str += temp;
	temp = parse_field_width(print_data, str, args);
	chrs_read += temp;
	str += temp;
	temp = parse_precision(print_data, str, args);
	chrs_read += temp;
	str += temp;
	return (chrs_read + parse_length_modifier(print_data, *str));
}

/* general_print prints an output according to the arguments
 * and returns the number of characters printed or -1 on error */

int	general_print(t_data *print_data, char *str, va_list args)
{
	int		chrs_printed;
	int		temp;

	if (!print_data || !str)
		return (-1);
	chrs_printed = 0;
	while (*str)
	{
		if (*str != '%')
		{
			chrs_printed += ft_putchar(print_data, *str);
			str++;
			continue ;
		}
		temp = parse_format_info(print_data, ++str, args);
		if (temp == -1)
			return (-1);
		str += temp;
		temp = generic_print_value(print_data, *str, args);
		if (temp == -1)
			return (-1);
		chrs_printed += temp;
		str++;
	}
	return (chrs_printed);
}

int 	ft_printf(const char	*format, ...)
{
	int			chrs_printed;
	va_list		args;
	t_data		print_data;

	if (!format)
		return (-1);
	chrs_printed = 0;
	va_start(args, format);
	reset_data(&print_data);
	chrs_printed = general_print(&print_data, (char *) format, args);
	va_end(args);
	return (chrs_printed);
}
