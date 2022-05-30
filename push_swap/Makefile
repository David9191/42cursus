# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jislim <jislim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 19:44:31 by jislim            #+#    #+#              #
#    Updated: 2022/05/30 18:30:16 by jislim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
AR = ar
ARFLAGS = -rcs
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS =  push_swap.c push_swap_utils.c  check_duplicate.c check_sorted.c \
		ft_atoi_push.c ft_error.c less_than_or_equal_five.c less_than_or_equal_five2.c \
		push_swap_command_s_p.c push_swap_command_r_rr.c push_swap_parsing.c \
		push_swap_sort_big.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) --directory ./libft -s
	cp libft/libft.a $@
	$(AR) $(ARFLAGS) $@ $^
	$(CC) $(FLAGS) $(OBJS) $(NAME) -o push_swap

debug :
	$(CC) $(FLAGS) $(SRCS) $(NAME) -g -o push_swap

clean :
	$(MAKE) clean --directory ./libft -s
	$(RM) -rf $(OBJS) a.out *.gch a.out.dSYM push_swap

fclean : clean
	$(MAKE) fclean --directory ./libft -s
	$(RM) $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re bonus
