# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 11:58:44 by jislim            #+#    #+#              #
#    Updated: 2022/06/22 15:42:24 by jislim           ###   ########.fr        #
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

MLX_DIR	= ./mlx/

SRCS = so_long.c so_long_utils.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	$(CC) $(FLAGS) -L./ -lmlx -framework OpenGL -framework Appkit -o $(NAME) $(OBJS) $(LIBFT_FLAGS)

clean :
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) -rf $(OBJS) a.out *.gch a.out.dSYM

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) so_long so_long.dSYM

re :
	make fclean
	make all

debug :
	$(CC) $(FLAGS) $(SRCS) -L./ -lmlx -framework OpenGL -framework Appkit $(LIBFT_FILE) -o $(NAME) -g
.PHONY : all clean fclean re bonus
