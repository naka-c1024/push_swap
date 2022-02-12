# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 09:33:10 by ynakashi          #+#    #+#              #
#    Updated: 2022/02/12 09:02:55 by ynakashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

$(NAME) :
	gcc -Wall -Wextra -Werror srcs/* libft/libft.a -o $(NAME)

debug :
	gcc -g srcs/* libft/libft.a -o $(NAME)

fclean :
	rm $(NAME)

# sh
run :
	ARG=$$(jot -r -s " " 3 -2147483648 2147483647); ./push_swap $$ARG | ./checker $$ARG
	ARG=$$(jot -r -s " " 5 -2147483648 2147483647); ./push_swap $$ARG | ./checker $$ARG
	ARG=$$(jot -r -s " " 100 -2147483648 2147483647); ./push_swap $$ARG | ./checker $$ARG
	ARG=$$(jot -r -s " " 500 -2147483648 2147483647); ./push_swap $$ARG | ./checker $$ARG

re :fclean $(NAME)

kati : re run