# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/28 01:13:32 by jislim            #+#    #+#              #
#    Updated: 2022/04/28 01:23:09 by jislim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
AR = ar
ARFLAGS = -rcs
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS =  push_swap.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) --directory ./libft
	cp libft/libft.a $@
	$(AR) $(ARFLAGS) $@ $^
	$(CC) $(FLAGS) $(SRCS)

clean :
	$(MAKE) clean --directory ./libft
	$(RM) $(OBJS) a.out

fclean : clean
	$(MAKE) fclean --directory ./libft
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
