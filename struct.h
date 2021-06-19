#ifndef struct_h
#define struct_h

typedef struct s_data
{
	struct
	{
		unsigned short show_sign;
		unsigned short left_justify;
		unsigned short zero_pad;
		unsigned short alternate_output;
		unsigned short initial_space;
		unsigned short uppercase;
	}flags;
	int   width;
	int	  precision;
	char  length_modifier;
	char type_specifier;
	enum { OUTPUT_NONE, OUTPUT_STDOUT }mode;
}t_data;

#endif /* struct_h */
