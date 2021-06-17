#ifndef ft_printf_structs_h
#define ft_printf_structs_h

/* Formatting struct */
typedef struct
{
	struct{
		unsigned char show_sign;  /* '+'*/
		unsigned char left_align; /* '-' */
		unsigned char initial_space; /* ' ' */
		unsigned char zero_pad; /* '0' */
		unsigned char alternative_output; /* '#' */
		unsigned char uppercase; /* 'X' */
		unsigned char trailing_zeroes;
	}flags;
	
	int 	field_width; /* 0 is not present*/
	int 	precision;  /* -1 is no precision*/
	char 	length_modifier; /* NULL if not present*/
	char 	specifier; /* Conversion specifier*/
}format;

/* Output details struct */
typedef struct
{
	char 	*str;
	char 	*str_ptr;
	int 	chrs_printed;
}print_output;

/* all the information struct */
typedef struct
{
	format			fmt;
	print_output	out_put;
}print_data;

#endif /* ft_printf_structs_h */
