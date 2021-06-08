#include "ft_printf.h"
#include "ft_printf_structs.h"

void	reset_format(format *fmt)
{
	fmt->flags.show_sign = 0;
	fmt->flags.left_align = 0;
	fmt->flags.initial_space = 0;
	fmt->flags.zero_pad = 0;
	fmt->flags.alternative_output = 0;
	fmt->flags.uppercase = 0;
	fmt->flags.trailing_zeroes = 1;
	fmt->field_width = 0;
	fmt->precision = -1;
	fmt->length_modifier = 0;
	fmt->specifier = 0;
}
void	reset_data(print_data *data)
{
	reset_format(&data->fmt);
	data->out_put.str = 0;
	data->out_put.str_ptr = 0;
	data->out_put.chrs_printed = 0;
}

