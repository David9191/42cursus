NAME = push_swap.a
AR = ar
ARFLAGS = -rcs
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS =  ./push_swap.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(MAKE) --directory ./libft
	cp libft/libft.a $@
	$(AR) $(ARFLAGS) $@ $^
	$(CC) $(CFLAG) $(NAME)

clean :
	$(MAKE) clean --directory ./libft
	$(RM) $(OBJS) a.out *.gch

fclean : clean
	$(MAKE) fclean --directory ./libft
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
