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

int 	ft_putchar(t_data *print_data, char chr)
{
	if (print_data->mode == OUTPUT_NONE)
		return (1);
	else
		return ((int)(write(1, &chr, 1)));
}

char *unsigned_symbol(t_data *print_data, int base)
{
	char *octal_base;
	char *hex_lower;
	char *hex_upper;

	octal_base = "0";
	hex_lower = "0x";
	hex_upper = "0X";
	
	if (base == 8)
		return (octal_base);
	else
	{
		if (print_data->flags.uppercase)
			return (hex_upper);
		else
			return (hex_lower);
	}
}

int 	div_10_sign(long value)
{
	if (value < 0)
		return (-10);
	else
		return (10);
}

void 	reset_data(t_data *print_data)
{
	print_data->flags.show_sign = F;
	print_data->flags.left_justify = F;
	print_data->flags.alternate_output = F;
	print_data->flags.initial_space = F;
	print_data->flags.alternate_output = F;
	print_data->flags.uppercase = F;
	print_data->flags.zero_pad = F;
	print_data->width = 0;
	print_data->precision = -1;
	print_data->length_modifier = 0;
	print_data->type_specifier = 0;
	print_data->mode = OUTPUT_NONE;
}
