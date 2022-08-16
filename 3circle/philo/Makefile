# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 23:41:03 by jislim            #+#    #+#              #
#    Updated: 2022/08/12 22:01:33 by jislim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CC_FLAGS = -Wall -Werror -Wextra
SRCS := philo.c
RM = rm -rf

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean :
	$(RM) -rf $(OBJS) a.out *.gch a.out.dSYM

fclean : clean
	$(RM) $(NAME) philo

re :
	make fclean
	make all

.PHONY : all clean fclean re bonus
