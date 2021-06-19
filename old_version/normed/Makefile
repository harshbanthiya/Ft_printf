NAME = libftprintf.a
CC = gcc  # C compiler
CFLAGS = -Wall -Werror -Wextra -I. -c  # C flags
RM = rm -f   # rm command

HEADER = ft_printf.h

SRCS = ft_printf.c \
int_ft_printf.c \
parse_ft_printf.c \
parse_ft_printf_utils.c  \
padding_ft_printf.c \
print_ft_printf.c \
int_utils_ft_printf.c \
int_utils_2_ft_printf.c \
print_utils_ft_printf.c \
printf_utils.c


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
