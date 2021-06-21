/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_ft_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 15:31:15 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/06/21 14:24:48 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_long(t_data *p_d, long val)
{
	int		c_p;
	int		len;
	int		tmp;

	c_p = 0;
	len = 0;
	if (p_d->width > 0)
		len = get_length_long(p_d, val);
	if ((prenum_format(p_d, &tmp, &c_p, &len, &val)) == -1)
		return (-1);
	make_precision(p_d, &c_p, &val);
	tmp = ft_putnbr(p_d, val);
	if (tmp == -1)
		return (-1);
	else
		c_p += tmp;
	tmp = print_right_padding(p_d, len);
	if (tmp == -1)
		return (-1);
	else
		c_p += tmp;
	return (c_p);
}

int	print_unsigned_long(t_data *print_data, unsigned long value, int base)
{
	int		chrs_printed;
	int		length;
	int		temp;

	chrs_printed = 0;
	length = 0;
	if (print_data->width > 0)
		length = get_length_unsigned(print_data, value, base);
	if ((prenum_fmt_unsign(print_data, &temp, &chrs_printed, &length)) == -1)
		return (-1);
	mk_precision_unsigned(print_data, &chrs_printed, &value, &base);
	if (base_prefix(print_data, &temp, &chrs_printed, base) == -1)
		return (-1);
	temp = ft_put_unsigned_nbr(print_data, value, base);
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

int	print_general_unsigned(t_data *print_data, char chr, va_list args)
{
	void			*p;
	unsigned long	lu;
	int				base;

	assign_base(chr, &base);
	if (chr == 'p')
	{
		if (sizeof(void *) > sizeof(unsigned long))
			return (-1);
		print_data->flags.alternate_output = T;
		p = va_arg(args, void *);
		lu = (unsigned long)p;
		return (print_unsigned_long(print_data, lu, base));
	}
	else
	{
		if (chr == 'X')
			print_data->flags.uppercase = T;
		if (print_data->length_modifier == 'l')
			lu = va_arg(args, unsigned long);
		else
			lu = va_arg(args, unsigned int);
	}
	return (print_unsigned_long(print_data, lu, base));
}

int	print_general_int(t_data *print_data, char chr, va_list args)
{
	long	value;

	if (print_data->precision >= 0 && print_data->flags.zero_pad)
		print_data->flags.zero_pad = 0;
	if (chr == 'd' || chr == 'i')
	{
		if (print_data->length_modifier == 'l')
			value = va_arg(args, long);
		else
			value = va_arg(args, int);
		return (print_long(print_data, value));
	}
	else if (chr == 'p' || chr == 'x' || chr == 'X' || chr == 'o' || chr == 'u')
		return (print_general_unsigned(print_data, chr, args));
	else
		return (-1);
}
