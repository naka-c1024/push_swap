/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:56:50 by ynakashi          #+#    #+#             */
/*   Updated: 2022/02/09 13:38:43 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	should_sort(t_stack *a) // leak対策done
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

	sort(&a, &b); // 実装

	// write(1, "all finish\n", 11); // debug
	return (0);
}
