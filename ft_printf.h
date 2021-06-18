#ifndef ft_printf_h
#define ft_printf_h

/* Standard Libraries used */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>


/* True and false to be used for bool variables*/
#define T 1
#define F 0
#define DIVISOR_10_SIGN(value) (value < 0 ? -10 : 10)
/* // STRUCTS //  */
/* Data structure to hold all the formating information */
struct format_info
{
	struct
	{
		unsigned short show_sign; 		/* '+' flag */
		unsigned short left_justify;		/* '-' flag */
		unsigned short zero_pad; 		/* '0' flag */
		unsigned short alternate_output; /* '#' flag */
		unsigned short initial_space; 	/* ' ' flag */
		unsigned short uppercase;		/* 'X' flag */
	}flags;
	int   width;
	int	  precision;
	char  length_modifier;
	char type_specifier; 	/* format specifier */
};

/* Data structure for storing the string pointer information */
struct string_info
{
	enum { OUTPUT_NONE, OUTPUT_STDOUT }mode;
	char 	*start;
	char 	*current_ptr;
	int 	chrs_printed;
};

/* Parent Struct for access to all the informartion */

struct data
{
	struct format_info	fmt;
	struct string_info	output;
};

// FUNCTION CALLS 
/* Utilities */
void 			reset_format_info(struct format_info *format);
void 			reset_data(struct data *print_data);
int 			ft_putchar(struct data *print_data, char chr);
int				ft_atoi(char *nptr, char **end_ptr);
int				ft_isdigit(int c);
int				str_to_int(char *str, int *value);
int	 			print_left_padding(struct data *print_data , int length);
int 			print_right_padding(struct data *print_data, int length);
int  			print_left_padding_before_sign(struct data *print_data, int length);
int 			print_left_padding_after_sign(struct data *print_data, int length);
int				ft_strlen(char *str);
int 			ft_putstr(struct data *print_data, char *s);
int				ft_putnbr(struct data *print_data, long value);
int 			get_length_long(struct data *print_data, long value);
int 			get_number_of_digits(long value);
int 			get_number_digits_unsigned(unsigned long number, int base);
int				parse_field_width(struct data *print_data, char *str, va_list args);
int 			print_field_width(struct data *print_data, int length);
int				assign_base(char chr, int *base);
void				put_correct_sign(struct data *print_data, int *temp, long *val);
void			make_precision(struct data *print_data, int *chrs_p, long *val);
int				prenum_format(struct data *p_d, int *tp, int *c_p, int *len, long *v);
void			mk_precision_unsigned(struct data *p_d, int *c_p, unsigned long *val, int *base);
/* Parse */
int 	parse_format_info(struct data *print_data, char *str, va_list args);
void 	conflict_resolve(struct data *print_data);
int 	update_flags(struct data *print_data, char chr);
int		negative_field_width(struct data *print_data, int *field_width, int *chrs);

/* Print */
int 	ft_printf(const char  *format, ...);
int		generic_print_value(struct data *print_data, char chr, va_list args);
int 	print_general_int(struct data *print_data, char chr, va_list args);
int 	print_long(struct data *print_data, long value);
int 	get_length_unsigned(struct data *print_data, unsigned long value, int base);
char 	*unsigned_symbol(struct data *print_data, int base);
int 	ft_put_unsigned_nbr(struct data *print_data, unsigned long value, int base);
int 	print_unsigned_long(struct data *print_data, unsigned long value, int base);

#endif /* ft_printf_h */
