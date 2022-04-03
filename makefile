NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_DIR = ./lib
INC = -I./lib -I./header

SRC_DIR = ./src
SRC_NAME = ft_printf.c
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_NAME))

OBJ_DIR = ./obj
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJS = $(addprefix $(OBJ_DIR)/, $(OBJ_NAME))

$(NAME) : $(OBJS)
    $(MAKE) -C $(LIB_DIR) bonus
    cp $(LIB_DIR)/libft.a $@
    ar rc $@ $^

$(OBJS) :
    $(CC) $(CFLAGS) $(INC) -c $(SRCS) -o $@

all : $(NAME)

clean :
    $(MAKE) -C ./lib clean
    rm -rf $(OBJS)

fclean :
    $(MAKE) -C ./lib fclean
    rm -rf $(NAME) $(OBJS)

re : fclean all

.PHONY : all clean fclean re
