# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 16:07:19 by jislim            #+#    #+#              #
#    Updated: 2022/06/20 16:08:10 by jislim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
AR = ar
ARFLAGS = -rcs
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_DIR	= ./libft/
LIBFT_FLAGS	= -L ./$(LIBFT_DIR) -lft
LIBFT_FILE	= $(LIBFT_DIR)libft.a

SRCS =  so_long.c so_long_utils.c
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
	$(RM) $(NAME) so_long so_long.dSYM

re :
	make fclean
	make all

debug :
	$(CC) $(FLAGS) $(SRCS) -o so_long $(LIBFT_DIR)*.c -g3

.PHONY : all clean fclean re bonus
