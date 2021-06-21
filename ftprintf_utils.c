/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:26:48 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/06/21 18:03:54 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	ft_putchar(t_data *print_data, char chr)
{
	if (print_data->output.e_mode == OUTPUT_NONE)
		return (1);
	else
		return ((int)(write(1, &chr, 1)));
}

char	*unsigned_symbol(t_data *print_data, int base)
{
	char	*octal_base;
	char	*hex_lower;
	char	*hex_upper;

	octal_base = "0";
	hex_lower = "0x";
	hex_upper = "0X";
	if (base == 8)
		return (octal_base);
	else
	{
		if (print_data->fmt.s_flags.uppercase)
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

void 	reset_format(t_format *fmt)
{
	fmt->s_flags.show_sign = F;
	fmt->s_flags.left_justify = F;
	fmt->s_flags.alternate_output = F;
	fmt->s_flags.initial_space = F;
	fmt->s_flags.alternate_output = F;
	fmt->s_flags.uppercase = F;
	fmt->s_flags.zero_pad = F;
	fmt->width = 0;
	fmt->precision = -1;
	fmt->length_modifier = 0;
	fmt->type_specifier = 0;
}

void 	reset_data(t_data *print_data)
{
	reset_format(&print_data->fmt);
	print_data->output.chrs_printed = 0;
	print_data->output.e_mode = OUTPUT_STDOUT;
}
