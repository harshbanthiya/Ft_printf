#include "ft_printf.h"

int get_length_unsigned(t_data *print_data, unsigned long value, int base)
{
	t_data	temp;
	
	temp = *print_data;
	temp.mode = OUTPUT_NONE;
	temp.width = 0;
	return(print_unsigned_long(&temp, value, base));
}

int prenum_fmt_unsign(t_data *print_data, int *tmp, int *c_p, int *len)
{
	*tmp = print_left_padding(print_data, *len);
	if (*tmp == -1)
		return (-1);
	else
		*c_p += *tmp;
	return (1);
}

int get_number_digits_unsigned(unsigned long number, int base)
{
	int 	digits;
	
	digits = 1;
	while ((number /= base) != 0)
		digits++;
	return digits;
}

void	mk_precision_unsigned(t_data *p_d, int *c_p, unsigned long *val, int *base)
{
	int		digits;

	if (p_d->precision >= 0)
	{
		digits = get_number_digits_unsigned(*val, *base);
		digits = p_d->precision - digits;
		while (digits > 0)
		{
			ft_putchar(p_d, '0');
			digits--;
			(*c_p)++;
		}
	}
}

int base_prefix(t_data *p_d, int *tmp, int *cp, int b)
{
	if (p_d->flags.alternate_output && b != 10)
	{
		*tmp = ft_putstr(p_d, (unsigned_symbol(p_d, b)));
		if (*tmp == -1)
			return (-1);
		else
			*cp += *tmp;
	}
	return (1);
}


