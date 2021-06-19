/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_ft_printf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 11:34:23 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/06/19 11:39:42 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

int	ft_putstr(struct data *print_data, char *s)
{
	int	length;

	if (!print_data)
		return (-1);
	length = ft_strlen(s);
	if (print_data->output.mode == OUTPUT_NONE)
		return (length);
	else
		return ((int)(write(1, s, ft_strlen(s))));
}

int	ft_putnbr(struct data *print_data, long value)
{
	int		chrs_printed;
	char	out;

	if (!print_data)
		return (-1);
	chrs_printed = 0;
	if (value == 0)
	{
		if (print_data->fmt.precision != 0)
			chrs_printed += ft_putchar(print_data, '0');
		return (chrs_printed);
	}
	if (value < 0)
		value = -value;
	if (value / 10)
		chrs_printed = ft_putnbr(print_data, value / 10);
	out = '0' + value % 10;
	ft_putchar(print_data, out);
	return (chrs_printed + 1);
}
