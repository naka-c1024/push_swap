# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 09:33:10 by ynakashi          #+#    #+#              #
#    Updated: 2022/02/12 09:37:15 by ynakashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

CC		=	gcc

RM		=	rm -rf

CFLAGS	=	-Wall -Wextra -Werror

DEBUG_FLAGS	=	-g

NO_BUILTIN_FLAGS	=	-fno-builtin

SRCS	=	./srcs/a_to_b.c\
			./srcs/b_to_a.c\
			./srcs/check_arguments.c\
			./srcs/cmd.c\
			./srcs/error.c\
			./srcs/init_stack.c\
			./srcs/main.c\
			./srcs/median.c\
			./srcs/push.c\
			./srcs/reverse_rotate.c\
			./srcs/rotate.c\
			./srcs/sort_main.c\
			./srcs/swap.c\
			./srcs/three_sort.c\
			./srcs/under_seven_sort.c

OBJS	=	$(SRCS:.c=.o)

LIBFT_PATH	=	./libft/
LIBFT_OBJS	=	$(LIBFT_PATH)*.o
LIBFT_ARC	=	$(LIBFT_PATH)*.a
LIBFT_MAKE	=	make -C $(LIBFT_PATH)

# suffix rule
# make -p で暗黙のルールが見れる
# explicitly add a flag when creating object files
#$< 最初の依存するファイルの名前 -> 元になるファイル
#$@ ターゲットファイル名 -> 作りたいファイル
#echo $<
#echo $@
.c.o	:
	$(CC) $(CFLAGS) -c $< -o $@
# もしくは
#$(OBJS)	: $(SRCS)
#	$(CC) $(CFLAGS) -c $(SRCS)

$(NAME)	: $(OBJS)
	$(LIBFT_MAKE)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_ARC) -o $(NAME)

all		: $(NAME)

clean	:
	$(RM) $(OBJS) $(LIBFT_OBJS)

fclean	: clean
	$(RM) $(NAME) $(LIBFT_ARC)

re		: fclean all

# sh
run		:
	ARG=$$(jot -r -s " " 3 -2147483648 2147483647); ./push_swap $$ARG | ./checker $$ARG
	ARG=$$(jot -r -s " " 5 -2147483648 2147483647); ./push_swap $$ARG | ./checker $$ARG
	ARG=$$(jot -r -s " " 100 -2147483648 2147483647); ./push_swap $$ARG | ./checker $$ARG
	ARG=$$(jot -r -s " " 500 -2147483648 2147483647); ./push_swap $$ARG | ./checker $$ARG

nm		: fclean $(OBJS)
	$(LIBFT_MAKE)
	$(CC) $(CFLAGS) $(NO_BUILTIN_FLAGS) $(OBJS) $(LIBFT_ARC) -o $(NAME)
	nm -u $(NAME)

debug	: fclean $(OBJS)
	$(LIBFT_MAKE)
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(OBJS) $(LIBFT_ARC) -o $(NAME)

.PHONY	: all clean fclean re run nm debug
