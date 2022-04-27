# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jislim <jislim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 00:08:36 by jislim            #+#    #+#              #
#    Updated: 2022/04/05 15:23:30 by jislim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
AR = ar
ARFLAGS = -rcs
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS =  ./src/ft_printf.c \
		./src/ft_printf_char.c \
		./src/ft_printf_hexa_ptr.c \
		./src/ft_printf_hexa.c \
		./src/ft_printf_nbr.c \
		./src/ft_printf_str.c \
		./src/ft_printf_usnbr.c \
		./src/ft_printf.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) --directory ./libft
	cp libft/libft.a $@
	$(AR) $(ARFLAGS) $@ $^

clean :
	$(MAKE) clean --directory ./libft
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) fclean --directory ./libft
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
