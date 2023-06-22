MakefileCC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
INCDIR = ft_printf.h
SRCS = ft_putchar.c ft_printf.c ft_puthex.c ft_putstr.c ft_putnbr.c ft_putptr.c ft_printf_format.c ft_printf.c ft_putunbr.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
