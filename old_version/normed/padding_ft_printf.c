/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_ft_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:27:43 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/06/18 14:39:11 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_right_padding(struct data *print_data, int length)
{
	if (!print_data && length < 0)
		return (-1);
	if (print_data->fmt.width > 0 && print_data->fmt.flags.left_justify)
		return (print_field_width(print_data, length));
	return (0);
}

int	print_left_padding(struct data *print_data, int length)
{
	if (!print_data && length < 0)
		return (-1);
	if (print_data->fmt.width > 0 && !print_data->fmt.flags.left_justify)
		return (print_field_width(print_data, length));
	return (0);
}

int	print_left_padding_before_sign(struct data *print_data, int length)
{
	if (!print_data && length < 0)
		return (-1);
	if (print_data->fmt.width > 0 && !print_data->fmt.flags.left_justify
		&& !print_data->fmt.flags.zero_pad)
		return (print_field_width(print_data, length));
	return (0);
}

int	print_left_padding_after_sign(struct data *print_data, int length)
{
	if (!print_data && length < 0)
		return (-1);
	if (print_data->fmt.width > 0 && !print_data->fmt.flags.left_justify
		&& print_data->fmt.flags.zero_pad)
		return (print_field_width(print_data, length));
	return (0);
}
