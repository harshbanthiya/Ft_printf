/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_calls.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbanthiy <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 15:28:03 by hbanthiy          #+#    #+#             */
/*   Updated: 2021/06/21 18:18:52 by hbanthiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_CALLS_H
# define FUNCTION_CALLS_H
# include "struct.h"
# include <stdarg.h>
/* Parent Functions & struct reset function */
int		ft_printf(const char *format, ...);
int		general_print(t_data *print_data, char *str, va_list args);
int		parse_format_info(t_data *print_data, char *str, va_list args);
int		generic_print_value(t_data *print_data, char chr, va_list args);
void	reset_data(t_data *print_data);
void	reset_format(t_format *fmt);
/* Parsing Functions -- children functions of parse_format_info*/
int		parse_length_modifier(t_data *print_data, char chr);
int		parse_precision(t_data *print_data, char *str, va_list args);
int		parse_field_width(t_data *print_data, char *str, va_list args);
int		parse_flags(t_data *print_data, char *str);
/* Parsing Utilities */
void	conflict_resolve(t_data *print_data);
int		negative_field_width(t_data *print_data, int *field_width, int *chrs);
int		update_flags(t_data *print_data, char chr);
int		str_to_int(char *str, int *value);
/* Printing Functions - children functions of generic print value */
int		print_general_int(t_data *print_data, char chr, va_list args);
int		print_str(t_data *print_data, char *str);
int		print_char(t_data *print_data, char chr);
/* Str and chr utilities */
void	print_str_sub(t_data *print_data, char *str, int *t, int *l);
int		ft_putchar(t_data *print_data, char chr);
int		ft_putstr(t_data *print_data, char *s);
int		ft_strlen(char *str);
/* Print General int children functions */
int		print_general_unsigned(t_data *print_data, char chr, va_list args);
int		print_long(t_data *p_d, long val);
int		print_unsigned_long(t_data *print_data, unsigned long value, int base);
int		assign_base(char chr, int *base);
/* print long utils */
int		get_length_long(t_data *print_data, long value);
int		prenum_format(t_data *p_d, int *len, long *v);
void	put_correct_sign(t_data *p_d, int *tmp, long *val);
void	make_precision(t_data *p_d, int *c_p, long *val);
int		get_number_of_digits(long value);
int		ft_putnbr(t_data *print_data, long value);
/* print unsigned long utils */
int		get_length_unsigned(t_data *print_data, unsigned long value, int base);
int		prenum_fmt_unsign(t_data *print_data, int *tmp, int *c_p, int *len);
void	mk_precision_unsigned(t_data *p_d, int *c_p, unsigned long *v, int *b);
int		get_number_digits_unsigned(unsigned long number, int base);
int		base_prefix(t_data *p_d, int *tmp, int *cp, int b);
int		ft_put_unsigned_nbr(t_data *print_data, unsigned long value, int base);
/* Padding Functions */
int		print_field_width(t_data *print_data, int length);
int		print_left_padding_before_sign(t_data *print_data, int length);
int		print_left_padding_after_sign(t_data *print_data, int length);
int		print_left_padding(t_data *print_data, int length);
int		print_right_padding(t_data *print_data, int length);
/* General Utils */
int		div_10_sign(long value);
char	*unsigned_symbol(t_data *print_data, int base);
int		ft_isdigit(int c);
int		ft_atoi(char *nptr, char **end_ptr);

#endif /* function_calls_h */
