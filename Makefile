NAME = libftprintf.a
CC = gcc  
CFLAGS = -Wall -Werror -Wextra -I. -c 
RM = rm -f

HEADER = ft_printf.h \
		 function_calls.h \
		 struct.h

SRCS = ft_printf.c \
ftprintf_utils.c \
gen_int.c \
gen_int_utils.c  \
padding_ft_printf.c \
int_utils.c \
parse_ft_printf.c \
parse_utils.c \
print_char.c \
unsigned_int_utils.c


OBJS = $(SRCS:.c=.o)

B_OBJS = $(B_SRCS:.c=.o)

all: ${NAME}

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

$(OBJS):$(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(HEADER)

$(B_OBJS):$(B_SRCS)
	$(CC) $(CFLAGS) $(B_SRCS) $(HEADER)

bonus: $(OBJS) $(B_OBJS)
	rm -f $(NAME)
	ar rcs $(NAME) $(OBJS) $(B_OBJS)

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# I use .PHONY to make sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: clean fclean all re
