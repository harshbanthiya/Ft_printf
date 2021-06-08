#ifndef ft_printf_h
#define ft_printf_h

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_printf_structs.h"

void	reset_format(format *fmt);
void	reset_data(print_data *data);

#endif /* ft_printf_h */
