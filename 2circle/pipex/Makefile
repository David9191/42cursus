# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 10:12:10 by jislim            #+#    #+#              #
#    Updated: 2022/07/06 09:52:51 by jislim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
AR = ar
ARFLAGS = -rcs
CC = cc
CCFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_DIR	= ./libft/
LIBFT_FLAGS	= -L ./$(LIBFT_DIR) -lft
LIBFT_FILE	= $(LIBFT_DIR)libft.a

SRCS =  pipex.c pipex_utils.c pipex_error.c
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CCFLAGS) -c $< -o $@

all : $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(CCFLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS)

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
	$(CC) $(CCFLAGS) $(SRCS) -o pipex $(LIBFT_FILE) -g3

.PHONY : all clean fclean re bonus
