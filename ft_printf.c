/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:38:55 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/06/22 11:53:10 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	sub_gen_print_val(t_data *print_data, char chr, va_list args)
{
	if (chr == '\0')
		return (0);
	else if (chr == 'X')
	{
		print_data->fmt.s_flags.uppercase = T;
		return (print_general_int(print_data, chr, args));
	}
	else if (chr == 'd' || chr == 'i' || chr == 'u')
		return (print_general_int(print_data, chr, args));
	else if (chr == 'o' || chr == 'x' || chr == 'p')
		return (print_general_int(print_data, chr, args));
	else
		return (-1);
}

int	generic_print_value(t_data *print_data, char chr, va_list args)
{
	int		*n_ptr;

	if (!print_data)
		return (-1);
	print_data->fmt.type_specifier = chr;
	if (chr == 'c')
		return (print_char(print_data, (unsigned)va_arg(args, int)));
	else if (chr == 's')
		return (print_str(print_data, va_arg(args, char *)));
	else if (chr == '%')
		return (ft_putchar(print_data, '%'));
	else if (chr == 'n')
	{
		n_ptr = va_arg(args, int *);
		if (n_ptr == NULL)
			return (-1);
		else
			*n_ptr = print_data->output.chrs_printed;
		return (0);
	}
	else
		return (sub_gen_print_val(print_data, chr, args));
}

int	parse_format_info(t_data *print_data, char *str, va_list args)
{
	int		temp;
	int		chrs_read;

	if (!print_data || !str || *str == '\0')
		return (-1);
	chrs_read = 0;
	reset_format(&print_data->fmt);
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

	chrs_printed = 0;
	while (*str)
	{
		if (*str != '%')
		{
			chrs_printed += ft_putchar(print_data, *str++);
			print_data->output.chrs_printed = chrs_printed;
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
		print_data->output.chrs_printed = chrs_printed;
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
