/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:21:11 by ynakashi          #+#    #+#             */
/*   Updated: 2022/02/08 13:22:37 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// passive -> 受動,pushされる方
// active -> 能動,pushする方
void	push(t_stack **passive, t_stack **active)
{
	t_stack	*tmp;
	t_stack	*seconde_ptr;
	size_t	size;

	if (!*active)
		return ;

	size = my_lstsize(*passive);
	if (size == 0)
		seconde_ptr = NULL;
	else
		seconde_ptr = (*passive);

	tmp = (*active)->next;
	my_lstadd_front(passive, *active);
	*active = tmp;

	(*passive)->next = seconde_ptr;
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
	b = my_lstnew(42);

	printf("before:a\n");
	t_stack	*c = a;
	while (a)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
	printf("before:b\n");
	t_stack	*d = b;
	while (b)
	{
		printf("%d\n", b->value);
		b = b->next;
	}
	printf("------------\n");
	push(&c, &d);
	printf("after:a\n");
	while (c)
	{
		printf("%d\n", c->value);
		c = c->next;
	}
	printf("after:b\n");
	while (d)
	{
		printf("%d\n", d->value);
		d = d->next;
	}
	return (0);
}
 */
