# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 10:12:10 by jislim            #+#    #+#              #
#    Updated: 2022/06/10 12:22:58 by jislim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
AR = ar
ARFLAGS = -rcs
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS =  
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) --directory ./libft -s
	cp libft/libft.a $@
	$(AR) $(ARFLAGS) $@ $^
	$(CC) $(FLAGS) -o pipex $(OBJS) $(NAME)
clean :
	$(MAKE) clean --directory ./libft -s
	$(RM) -rf $(OBJS) a.out *.gch a.out.dSYM

fclean : clean
	$(MAKE) fclean --directory ./libft -s
	$(RM) $(NAME) pipex

re :
	make fclean
	make all

.PHONY : all clean fclean re bonus
