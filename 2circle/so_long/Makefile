# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 11:58:44 by jislim            #+#    #+#              #
#    Updated: 2022/07/01 13:35:11 by jislim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
AR = ar
ARFLAGS = -rcs
CC = cc
CCFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LIBFT_DIR	= ./libft
LIBFT_FLAGS	= -L$(LIBFT_DIR) -lft
LIBFT_FILE	= $(LIBFT_DIR)/libft.a

MLX_DIR	= ./mlx/
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit

SRCS = ft_so_long.c ft_fill_image_to_window.c ft_error_exit.c \
		ft_create_images.c ft_on_key_press.c ft_parse_map.c \
		ft_check_map.c ft_init_map.c
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CCFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR) 2>/dev/null
	$(CC) $(FLAGS) -o so_long $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS)

clean :
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	$(RM) -rf $(OBJS) a.out *.gch a.out.dSYM

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) ft_so_long ft_so_long.dSYM

re :
	make fclean
	make all

debug :
	$(CC) $(FLAGS) $(SRCS) $(MLX_FLAGS) $(LIBFT_FILE) -o ft_$(NAME) -g -fsanitize=address

.PHONY : all clean fclean re bonus
