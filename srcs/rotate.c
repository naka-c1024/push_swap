/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:49:33 by ynakashi          #+#    #+#             */
/*   Updated: 2022/02/08 13:50:15 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void	rotate(t_stack *a)
{
	int	first;

	if (a == NULL)
		return ;
	first = a->value;
	while (a->next != NULL)
	{
		a->value = a->next->value;
		a = a->next;
	}
	a->value = first;
}

/*
int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	check_argv(argc, argv);
	a = init_stack(argc, argv);
	b = NULL;

	printf("before:a\n");
	t_stack	*c = a;
	while (a)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
	printf("------------\n");
	rotate(c);
	printf("after:a\n");
	while (c)
	{
		printf("%d\n", c->value);
		c = c->next;
	}
	return (0);
}
 */