/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ft_printf_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 14:26:54 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/06/18 14:42:48 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conflict_resolve(struct data *print_data)
{
	if (print_data->fmt.flags.zero_pad && print_data->fmt.flags.left_justify)
		print_data->fmt.flags.zero_pad = F;
	if (print_data->fmt.flags.initial_space && print_data->fmt.flags.show_sign)
		print_data->fmt.flags.initial_space = F;
}

int	negative_field_width(struct data *print_data, int *field_width, int *chrs)
{
	print_data->fmt.flags.left_justify = 1;
	if (INT_MAX + *field_width < 0)
		return (-1);
	else
		*field_width = -(*field_width);
	print_data->fmt.width = *field_width;
	return (*chrs);
}

int	update_flags(struct data *print_data, char chr)
{
	if (chr == '+')
		return (print_data->fmt.flags.show_sign = T);
	else if (chr == '-')
		return (print_data->fmt.flags.left_justify = T);
	else if (chr == ' ')
		return (print_data->fmt.flags.initial_space = T);
	else if (chr == '#')
		return (print_data->fmt.flags.alternate_output = T);
	else if (chr == '0')
		return (print_data->fmt.flags.zero_pad = T);
	else
		return (0);
}

int	str_to_int(char *str, int *value)
{
	char	*end_ptr;
	long	parsed;
	int		chrs_read;

	if (!str && !value && (*str != '-' || !ft_isdigit(*str)))
		return (-1);
	parsed = ft_atoi(str, &end_ptr);
	if (parsed > INT_MAX || parsed < INT_MIN)
		return (-1);
	*value = (int)parsed;
	chrs_read = 0;
	while (str != end_ptr)
	{
		chrs_read++;
		str++;
	}
	return (chrs_read);
}

int 	print_field_width(struct data *print_data, int length)
{
	int		chrs_printed;
	char	chr;

	chrs_printed = 0;
	if (!print_data && length < 0)
		return (-1);
	if (length >= print_data->fmt.width)
		return (0);
	if (print_data->fmt.flags.zero_pad)
		chr = '0';
	else
		chr = ' ';
	length = print_data->fmt.width - length;
	while (length > 0)
	{
		if (ft_putchar(print_data, chr) == -1)
			return (-1);
		chrs_printed++;
		length--;
	}
	return (chrs_printed);
}
