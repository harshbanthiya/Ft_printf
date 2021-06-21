/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:48:29 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/06/21 16:25:58 by hbanthiy         ###   ########.fr       */
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

int	ft_putstr(t_data *print_data, char *s)
{
	int	length;

	if (!print_data)
		return (-1);
	length = ft_strlen(s);
	if (print_data->e_mode == OUTPUT_NONE)
		return (length);
	else
		return ((int)(write(1, s, ft_strlen(s))));
}

int	print_char(t_data *print_data, char chr)
{
	int			chrs_printed;
	int			temp;
	const int	length = 1;

	chrs_printed = 0;
	if (!print_data)
		return (-1);
	print_data->s_flags.zero_pad = 0;
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

void	print_str_sub(t_data *print_data, char *str, int *t, int *l)
{
	if (print_data->precision >= 0)
	{
		*t = *l;
		while (*str != '\0' && --*t >= 0)
			ft_putchar(print_data, *str++);
	}
	else
		ft_putstr(print_data, str);
}

int 	print_str(t_data *print_data, char *str)
{
	int		length;
	int		chrs_printed;
	int		temp;

	if (!str)
		str = "(null)";
	print_data->s_flags.zero_pad = 0;
	length = ft_strlen(str);
	if (print_data->precision >= 0 && length > print_data->precision)
		length = print_data->precision;
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
