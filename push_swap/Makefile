# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jislim <jislim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 19:44:31 by jislim            #+#    #+#              #
#    Updated: 2022/05/24 21:02:55 by jislim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
AR = ar
ARFLAGS = -rcs
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS =  push_swap.c push_swap_utils.c push_swap_utils2.c push_swap_test.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) --directory ./libft -s
	cp libft/libft.a $@
	$(AR) $(ARFLAGS) $@ $^
	$(CC) $(FLAGS) push_swap.c push_swap_utils.c push_swap_utils2.c libft/*.c -o push_swap

debug :
	$(CC) $(FLAGS) push_swap.c push_swap_utils.c push_swap_utils2.c libft/*.c -g -o push_swap

clean :
	$(MAKE) clean --directory ./libft -s
	$(RM) -rf $(OBJS) a.out *.gch a.out.dSYM

fclean : clean
	$(MAKE) fclean --directory ./libft -s
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re bonus
