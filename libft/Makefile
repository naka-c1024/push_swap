# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 16:50:54 by ynakashi          #+#    #+#              #
#    Updated: 2021/08/21 00:02:04 by ynakashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c\
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c\
ft_memcpy.c  ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c\
ft_strmapi.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c\
ft_tolower.c ft_toupper.c ft_strncmp.c ft_strlcpy.c

SRCS_B  =  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS    = $(SRCS:.c=.o)

OBJS_B  = $(SRCS_B:.c=.o)

ifdef WITH_BONUS
OBJS +=  $(OBJS_B)
endif

CC      = gcc

RM      = rm -rf

CFLAGS  = -Wall -Wextra -Werror

NAME    = libft.a

.c.o	:
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
		ar rc $(NAME) $(OBJS)

all     : $(NAME)

clean   :
		$(RM) $(OBJS) $(OBJS_B)

fclean  : clean
		$(RM) $(NAME)

re		: fclean all

bonus	:
		make WITH_BONUS=1

.PHONY: all clean fclean re bonus