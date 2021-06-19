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

int	get_number_of_digits(long value)
{
	int 	digits;
	
	digits = 1;
	while((value /= DIVISOR_10_SIGN(value)) != 0)
		digits++;
	return digits;
}

int get_number_digits_unsigned(unsigned long number, int base)
{
	int 	digits;
	
	digits = 1;
	while ((number /= base) != 0)
		digits++;
	return digits;
}

int get_length_unsigned(struct data *print_data, unsigned long value, int base)
{
	struct data	temp;
	temp = *print_data;
	temp.output.mode = OUTPUT_NONE;
	temp.fmt.width = 0;
	return(print_unsigned_long(&temp, value, base));
}

int get_length_long(struct data *print_data, long value)
{
	struct data 	temp;
	
	temp = *print_data;
	temp.output.mode = OUTPUT_NONE;
	temp.fmt.width = 0;
	
	return (print_long(&temp, value));
}

char *unsigned_symbol(struct data *print_data, int base)
{
	char *octal_base = "0";
	char *hex_lower = "0x";
	char *hex_upper = "0X";
	
	if (base == 8)
		return (octal_base);
	else
	{
		if (print_data->fmt.flags.uppercase)
			return (hex_upper);
		else
			return (hex_lower);
	}
}
