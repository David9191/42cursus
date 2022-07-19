# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 14:11:10 by seuhan            #+#    #+#              #
#    Updated: 2022/07/19 16:10:02 by jislim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 

CC_FLAGS = -Wall -Werror -Wextra

NAME := minishell

SRCS := main.c \
		parse_args.c \
		parse_args_utils.c \
		exec.c \
		find_path.c \
		cd.c \
		echo.c \
		env.c \
		builtins.c \
		exec_utils.c \
		cells_utils.c \
		parse_args_process_part01.c \
		parse_args_process_part02.c \
		parse_args_process_part03.c \
		redir.c \
		return_error.c \
		unset.c \
		prompt.c \
		pwd.c \
		export.c \
		exit.c \
		display_export.c \
		heredoc.c \
		noars.c	\
		signal.c \
		signal2.c \
		return_error_syntax.c \
		is_in_env.c \
		shlvl.c \
		heredoc_utils.c \
		rterp.c

ifneq ($(shell uname), Linux)
READLINE_LIB_DIR_FLAG := -L$(shell brew --prefix readline)/lib
READLINE_INC_DIR_FLAG := -I$(shell brew --prefix readline)/include
endif

OBJS := $(SRCS:.c=.o)

all : libft $(NAME)

$(NAME):	$(addprefix objs/, $(OBJS)) Makefile
			$(CC) $(CC_FLAGS) -o $(NAME) $(addprefix objs/, $(OBJS)) libft/libft.a $(READLINE_LIB_DIR_FLAG) -lreadline
#			$(CC) -o $(NAME) $(addprefix objs/, $(OBJS)) libft/libft.a  -lreadline $(READLINE_LIB_DIR_FLAG) $(READLINE_INC_DIR_FLAG) -fsanitize=address -g3

objs/%.o:	srcs/%.c includes/minishell.h libft/libft.a libft/libft.h Makefile
			@mkdir -p objs
			$(CC) $(CC_FLAGS) -c $< -o $@ $(READLINE_INC_DIR_FLAG)

libft :	
		$(MAKE) -C libft
		
clean :
		rm -rf objs
		make clean -C libft

fclean : clean
		rm -f $(NAME)
		make fclean -C libft

re : fclean all

.PHONY : re clean fclean libft all .PHONY