/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:56:50 by ynakashi          #+#    #+#             */
/*   Updated: 2022/02/11 20:52:47 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	should_sort(t_stack *a)
{
	if (my_lstsize(a) == 1)
	{
		my_lstclear(&a);
		exit(EXIT_SUCCESS);
	}
	while (a->next)
	{
		if (a->value > a->next->value)
		{
			return ;
		}
		a = a->next;
	}
	my_lstclear(&a);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	check_argv(argc, argv);
	a = init_stack(argc, argv);
	b = NULL;
	should_sort(a);
	sort(&a, &b);
	my_lstclear(&a);
	return (0);
}
