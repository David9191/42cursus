NAME = push_swap.a
AR = ar
ARFLAGS = -rcs
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS =  push_swap.c push_swap_utils.c push_swap_test.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) --directory ./libft -s
	cp libft/libft.a $@
	$(AR) $(ARFLAGS) $@ $^
	$(CC) $(FLAGS) push_swap.c push_swap_utils.c push_swap_utils2.c libft/*.c

debug :
	$(CC) $(FLAGS) push_swap.c push_swap_utils.c push_swap_utils2.c libft/*.c -g

clean :
	$(MAKE) clean --directory ./libft -s
	$(RM) -rf $(OBJS) a.out *.gch a.out.dSYM

fclean : clean
	$(MAKE) fclean --directory ./libft -s
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
