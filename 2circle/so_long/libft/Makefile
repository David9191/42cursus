# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jislim <jislim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 15:26:40 by jislim            #+#    #+#              #
#    Updated: 2022/07/01 13:39:06 by jislim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
AR = ar
ARFLAGS = -rcs
CC = cc
CCFLAG = -Wall -Wextra -Werror
RM = rm -rf

SRCS =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
		ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_putusnbr_fd.c ft_printf.c ft_printf_char.c \
		ft_printf_hexa_ptr.c ft_printf_hexa.c ft_printf_nbr.c ft_printf_str.c \
		ft_printf_usnbr.c ft_printf.c ft_linkedstack.c ft_linkedstack_utils.c \
		ft_atoll.c ft_numlen.c ft_doublep_len.c ft_get_next_line.c \
		ft_get_next_line_utils.c ft_double_free.c

OBJS = $(SRCS:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJS = $(BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CCFLAG) -c $< -o $@

clean :
	$(RM) $(OBJS) $(BONUS_OBJS) *.gch

fclean : clean
	$(RM) $(NAME)

re : fclean $(NAME)

bonus : $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

.PHONY : all clean fclean re bonus
