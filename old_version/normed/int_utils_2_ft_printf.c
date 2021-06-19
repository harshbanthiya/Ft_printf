/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils_2_ft_printf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:22:28 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/06/19 13:18:03 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_nbr(struct data *print_data, unsigned long value, int base)
{
	int				chrs_printed;
	unsigned short	remainder;
	char			out;

	if (!print_data)
		return (-1);
	chrs_printed = 0;
	if (value == 0)
	{
		if (print_data->fmt.precision != 0)
			chrs_printed = ft_putchar(print_data, '0');
		return (chrs_printed);
	}
	if (value / base)
		chrs_printed = ft_put_unsigned_nbr(print_data, value / base, base);
	if (chrs_printed == -1)
		return (-1);
	remainder = value % base;
	if (remainder >= 10)
		out = remainder - 10 + (print_data->fmt.flags.uppercase ? 'A' : 'a');
	else
		out = remainder + '0';
	ft_putchar(print_data, out);
	return (chrs_printed + 1);
}

int	assign_base(char chr, int *base)
{
	if (chr == 'X' || chr == 'x' || chr == 'p')
		*base = 16;
	else if (chr == 'o')
		*base = 8;
	else if (chr == 'u')
		*base = 10;
	return (*base);
}

void	put_correct_sign(struct data *p_d, int *tmp, long *val)
{
	if (p_d->fmt.flags.show_sign && *val >= 0)
		*tmp = ft_putchar(p_d, '+');
	else if (*val < 0)
		*tmp = ft_putchar(p_d, '-');
	else if (p_d->fmt.flags.initial_space)
		*tmp = ft_putchar(p_d, ' ');
	else
		*tmp = 0;
}

void	make_precision(struct data *p_d, int *c_p, long *val)
{
	int	digits;

	if (p_d->fmt.precision >= 0)
	{
		digits = get_number_of_digits(*val);
		digits = p_d->fmt.precision - digits;
		while (digits > 0)
		{
			ft_putchar(p_d, '0');
			digits--;
			(*c_p)++;
		}
	}
}

void	mk_precision_unsigned(struct data *p_d, int *c_p, unsigned long *val, int *base)
{
	int		digits;

	if (p_d->fmt.precision >= 0)
	{
		digits = get_number_digits_unsigned(*val, *base);
		digits = p_d->fmt.precision - digits;
		while (digits > 0)
		{
			ft_putchar(p_d, '0');
			digits--;
			(*c_p)++;
		}
	}
}

int	prenum_format(struct data *p_d, int *tp, int *c_p, int *len, long *v)
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
