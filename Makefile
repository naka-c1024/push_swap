# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/10 09:33:10 by ynakashi          #+#    #+#              #
#    Updated: 2022/02/10 11:59:57 by ynakashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

$(NAME) :
	gcc srcs/* libft/libft.a -o $(NAME)

debug :
	gcc -g srcs/* libft/libft.a -o $(NAME)

fclean :
	rm $(NAME)