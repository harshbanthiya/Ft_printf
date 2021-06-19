/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:48:29 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/06/18 15:29:27 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(struct data *print_data, char chr)
{
	int			chrs_printed;
	int			temp;
	const int	length = 1;

	chrs_printed = 0;
	if (!print_data)
		return (-1);
	print_data->fmt.flags.zero_pad = 0;
	temp = print_left_padding(print_data, length);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	temp = ft_putchar(print_data, chr);
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

void	print_str_sub(struct data *print_data, char *str, int *t, int *l)
{
	if (print_data->fmt.precision >= 0)
	{
		*t = *l;
		while (*str != '\0' && --*t >= 0)
			ft_putchar(print_data, *str++);
	}
	else
		ft_putstr(print_data, str);
}

int 	print_str(struct data *print_data, char *str)
{
	int		length;
	int		chrs_printed;
	int		temp;

	if (!print_data || !str)
		return (-1);
	print_data->fmt.flags.zero_pad = 0;
	length = ft_strlen(str);
	if (print_data->fmt.precision >= 0 && length > print_data->fmt.precision)
		length = print_data->fmt.precision;
	chrs_printed = length;
	temp = print_left_padding(print_data, length);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	print_str_sub(print_data, str, &temp, &length);
	temp = print_right_padding(print_data, length);
	if (temp == -1)
		return (-1);
	else
		chrs_printed += temp;
	return (chrs_printed);
}

int	generic_print_value(struct data *print_data, char chr, va_list args)
{
	if (!print_data)
		return (-1);
	print_data->fmt.type_specifier = chr;
	if (chr == '\0')
		return (0);
	else if (chr == 'X')
	{
		print_data->fmt.flags.uppercase = T;
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
