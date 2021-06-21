/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_int_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:35:46 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/06/21 17:54:06 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *nptr, char **end_ptr)
{
	int		sign;
	int		result;

	sign = 1;
	result = 0;
	while ((9 <= *nptr && *nptr <= 13) || (*nptr == 32))
		nptr++;
	while (*nptr == '-' || *nptr == '+')
	{
		if (result >= 1)
			return (0);
		if (*nptr == '-')
			sign = -1;
		result++;
		nptr++;
	}
	result = 0;
	while ('0' <= *nptr && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	*end_ptr = nptr;
	return (sign * result);
}

int	value_zero(t_data *print_data)
{
	if (print_data->fmt.precision != 0)
		return (ft_putchar(print_data, '0'));
	return (0);
}

int	ft_put_unsigned_nbr(t_data *print_data, unsigned long value, int base)
{
	int				chrs_printed;
	unsigned short	remainder;
	char			out;

	chrs_printed = 0;
	if (value == 0)
		return (value_zero(print_data));
	if (value / base)
		chrs_printed = ft_put_unsigned_nbr(print_data, value / base, base);
	if (chrs_printed == -1)
		return (-1);
	remainder = value % base;
	if (remainder >= 10)
	{
		if (print_data->fmt.s_flags.uppercase)
			out = remainder - 10 + 'A';
		else
			out = remainder - 10 + 'a';
	}
	else
		out = remainder + '0';
	ft_putchar(print_data, out);
	return (chrs_printed + 1);
}

int	ft_putnbr(t_data *print_data, long value)
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
