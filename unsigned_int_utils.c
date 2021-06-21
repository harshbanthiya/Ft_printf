/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_int_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:47:22 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/06/21 16:33:32 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_length_unsigned(t_data *print_data, unsigned long value, int base)
{
	t_data	temp;

	temp = *print_data;
	temp.e_mode = OUTPUT_NONE;
	temp.width = 0;
	return (print_unsigned_long(&temp, value, base));
}

int	prenum_fmt_unsign(t_data *print_data, int *tmp, int *c_p, int *len)
{
	*tmp = print_left_padding(print_data, *len);
	if (*tmp == -1)
		return (-1);
	else
		*c_p += *tmp;
	return (1);
}

int	get_number_digits_unsigned(unsigned long number, int base)
{
	int		digits;

	digits = 1;
	number = number / base;
	while (number != 0)
	{	
		digits++;
		number = number / base;
	}
	return (digits);
}

void	mk_precision_unsigned(t_data *p_d, int *c_p, unsigned long *v, int *b)
{
	int		digits;

	if (p_d->precision >= 0)
	{
		digits = get_number_digits_unsigned(*v, *b);
		digits = p_d->precision - digits;
		while (digits > 0)
		{
			ft_putchar(p_d, '0');
			digits--;
			(*c_p)++;
		}
	}
}

int	base_prefix(t_data *p_d, int *tmp, int *cp, int b)
{
	if (p_d->s_flags.alternate_output && b != 10)
	{
		*tmp = ft_putstr(p_d, (unsigned_symbol(p_d, b)));
		if (*tmp == -1)
			return (-1);
		else
			*cp += *tmp;
	}
	return (1);
}
