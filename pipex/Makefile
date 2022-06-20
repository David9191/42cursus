# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 10:12:10 by jislim            #+#    #+#              #
#    Updated: 2022/06/20 09:47:40 by jislim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
AR = ar
ARFLAGS = -rcs
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_DIR	= ./libft/
LIBFT_FLAGS	= -L ./$(LIBFT_DIR) -lft
LIBFT_FILE	= $(LIBFT_DIR)libft.a

SRCS =  pipex.c pipex_utils.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS)

clean :
	make -C $(LIBFT_DIR) clean
	$(RM) -rf $(OBJS) a.out *.gch a.out.dSYM

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) pipex pipex.dSYM

re :
	make fclean
	make all

debug :
	$(CC) $(FLAGS) $(SRCS) -o pipex $(LIBFT_DIR)*.c -g3

.PHONY : all clean fclean re bonus
