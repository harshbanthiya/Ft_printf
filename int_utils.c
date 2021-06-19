/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils_ft_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:31:56 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/06/19 13:20:19 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int get_length_long(t_data *print_data, long value)
{
	t_data 	temp;
	
	temp = *print_data;
	temp.mode = OUTPUT_NONE;
	temp.width = 0;
	
	return (print_long(&temp, value));
}

void	put_correct_sign(t_data *p_d, int *tmp, long *val)
{
	if (p_d->flags.show_sign && *val >= 0)
		*tmp = ft_putchar(p_d, '+');
	else if (*val < 0)
		*tmp = ft_putchar(p_d, '-');
	else if (p_d->flags.initial_space)
		*tmp = ft_putchar(p_d, ' ');
	else
		*tmp = 0;
}

int	prenum_format(t_data *p_d, int *tp, int *c_p, int *len, long *v)
{
	*tp = print_left_padding_before_sign(p_d, *len);
	if (*tp == -1)
		return (-1);
	else
		*c_p += *tp;
	put_correct_sign(p_d, tp, v);
	if (*tp == -1)
		return (-1);
	else
		*c_p += *tp;
	*tp = print_left_padding_after_sign(p_d, *len);
	if (*tp == -1)
		return (-1);
	else
		*c_p += *tp;
	return (1);
}

int	get_number_of_digits(long value)
{
	int 	digits;
	
	digits = 1;
	while((value /= div_10_sign(value)) != 0)
		digits++;
	return digits;
}

void	make_precision(t_data *p_d, int *c_p, long *val)
{
	int	digits;

	if (p_d->precision >= 0)
	{
		digits = get_number_of_digits(*val);
		digits = p_d->precision - digits;
		while (digits > 0)
		{
			ft_putchar(p_d, '0');
			digits--;
			(*c_p)++;
		}
	}
}


