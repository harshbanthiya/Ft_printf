/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:38:55 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/06/18 12:56:56 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* general_print prints an output according to the arguments
 * and returns the number of characters printed or -1 on error */

int	general_print(struct data *print_data, char *str, va_list args)
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

/* printf takes a string and variable number of arguments 
 * and returns the number of chars printed */

int 	ft_printf(const char	*format, ...)
{
	int				chrs_printed;
	va_list			args;
	struct data		print_data;

	if (!format)
		return (-1);
	chrs_printed = 0;
	va_start(args, format);
	reset_data(&print_data);
	print_data.output.mode = OUTPUT_STDOUT;
	chrs_printed = general_print(&print_data, (char *) format, args);
	va_end(args);
	return (chrs_printed);
}
