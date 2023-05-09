# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 19:29:57 by minjiki2          #+#    #+#              #
#    Updated: 2023/04/22 19:29:58 by minjiki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



MakefileCC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
INCDIR = ft_printf.h
SRCS = ft_printf.c

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