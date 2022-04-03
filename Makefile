# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 00:08:36 by jislim            #+#    #+#              #
#    Updated: 2022/04/03 23:10:54 by jislim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  src/ft_printf.c \
		src/ft_printf_char.c \
		src/ft_printf_hexa_ptr.c \
		src/ft_printf_hexa.c \
		src/ft_printf_nbr.c \
		src/ft_printf_str.c \
		src/ft_printf_usnbr.c \
		src/ft_printf.c \

SURPL_O =	src/ft_printf.o \
			src/ft_printf_char.o \
			src/ft_printf_hexa_ptr.o \
			src/ft_printf_hexa.o \
			src/ft_printf_nbr.o \
			src/ft_printf_str.o \
			src/ft_printf_usnbr.o \
			src/ft_printf.o \

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O)
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
