/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_ft_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:27:43 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/06/21 16:23:17 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	print_field_width(t_data *print_data, int length)
{
	int		chrs_printed;
	char	chr;

	chrs_printed = 0;
	if (!print_data && length < 0)
		return (-1);
	if (length >= print_data->width)
		return (0);
	if (print_data->s_flags.zero_pad)
		chr = '0';
	else
		chr = ' ';
	length = print_data->width - length;
	while (length > 0)
	{
		if (ft_putchar(print_data, chr) == -1)
			return (-1);
		chrs_printed++;
		length--;
	}
	return (chrs_printed);
}

int	print_right_padding(t_data *print_data, int length)
{
	if (!print_data && length < 0)
		return (-1);
	if (print_data->width > 0 && print_data->s_flags.left_justify)
		return (print_field_width(print_data, length));
	return (0);
}

int	print_left_padding(t_data *print_data, int length)
{
	if (!print_data && length < 0)
		return (-1);
	if (print_data->width > 0 && !print_data->s_flags.left_justify)
		return (print_field_width(print_data, length));
	return (0);
}

int	print_left_padding_before_sign(t_data *print_data, int length)
{
	if (!print_data && length < 0)
		return (-1);
	if (print_data->width > 0 && !print_data->s_flags.left_justify
		&& !print_data->s_flags.zero_pad)
		return (print_field_width(print_data, length));
	return (0);
}

int	print_left_padding_after_sign(t_data *print_data, int length)
{
	if (!print_data && length < 0)
		return (-1);
	if (print_data->width > 0 && !print_data->s_flags.left_justify
		&& print_data->s_flags.zero_pad)
		return (print_field_width(print_data, length));
	return (0);
}
