#ifndef ft_printf_h
#define ft_printf_h

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf_structs.h"
#include <limits.h>
#include <string.h>

#define DIVISOR10(value) (value < 0 ? -10 : 10)
#define UNSIGNED_SYMBOL(data, base) (base == 8 ? "0" : (data->fmt.flags.uppercase ? "0X" : "0x"))
/* utils */
void	reset_format(format *fmt);
void	reset_data(print_data *data);
int		ft_isdigit(int c);
int 	str_to_int(char *str, int *result);
int 	emit_chr(print_data	*data, char chr);
int 	emit_str(print_data *data, char *str);
int		ft_strlen(const char *str);
void 	ft_putstr(char *s);
int 	print_str(print_data *data, char *str);
int 	print_char (print_data *data, char 	chr);

/* parsers */
int 	parse_flags(print_data *data, char *str);
int 	parse_field_width(print_data *data, char *str, va_list args);
int 	parse_precision(print_data *data, char 	*str, va_list args);
int 	parse_length_modifier(print_data *data, char chr);
int		parse_format(print_data *data, char *str, va_list args);

/* printing */
int 	print_long(print_data	*data, long value);
int 	generic_print_value(print_data *data, char chr, va_list args);
int 	print_generic_int(print_data *data, char chr, va_list args);
int 	generic_print(print_data *data, char *format, va_list args);
int		print_unsigned_long(print_data *data, unsigned long value, int base);

/* print utils */
int 	get_nr_digits_long(long number);
int 	print_long_rec(print_data *data, long value);
int 	print_right_padding(print_data *data, int length);
int 	get_length_long (print_data *data, long value);
int		print_left_padding_after_sign(print_data *data, int length);
int		print_left_padding_before_sign(print_data *data, int length);
int 	print_field_width(print_data *data, int length);
int		print_unsigned_long_rec(print_data *data, unsigned long value, int base);
int 	get_length_unsigned_long(print_data *data, unsigned long value, int base);
int 	get_nr_digits_unsigned_long(unsigned long number, int base);
int	 	print_left_padding(print_data *data, int length);

#endif /* ft_printf_h */
