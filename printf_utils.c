#include "ft_printf.h"

/* reset all values inside the format struct */
void 	reset_format_info(struct format_info *format)
{
	format->flags.show_sign = F;
	format->flags.left_justify = F;
	format->flags.alternate_output = F;
	format->flags.initial_space = F;
	format->flags.alternate_output = F;
	format->flags.uppercase = F;
	format->flags.zero_pad = F;
	format->width = 0;
	format->precision = -1;
	format->length_modifier = 0;
	format->type_specifier = 0;
}

/* initialising the struct and making all the values 0 */
void 	reset_data(struct data *print_data)
{
	reset_format_info(&print_data->fmt);
	print_data->output.mode = OUTPUT_NONE;
	print_data->output.start = 0;
	print_data->output.current_ptr = 0;
	print_data->output.chrs_printed = 0;
}

/* printing a character on stdout */

int 	ft_putchar(struct data *print_data, char chr)
{
	if (print_data->output.mode == OUTPUT_NONE)
		return (1);
	else
		return ((int)(write(1, &chr, 1)));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/* to convert string values to ints */

int	ft_atoi(char *nptr, char **end_ptr)
{
	int 		sign;
	int			result;

	sign = 1;
	result = 0;
	while ((9 <= *nptr && *nptr <= 13) || (*nptr == 32))
	{
		nptr++;
	}
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
