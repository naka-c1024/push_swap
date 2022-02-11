/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:44:00 by ynakashi          #+#    #+#             */
/*   Updated: 2022/02/11 20:57:01 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	my_lstsize(t_stack *lst)
{
	int	cnt;

	if (!lst)
		return (0);
	cnt = 0;
	while (lst)
	{
		lst = lst->next;
		cnt++;
	}
	return (cnt);
}

void	my_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

void	swap(t_stack **a)
{
	t_stack	*third_ptr;
	size_t	size;

	size = my_lstsize(*a);
	if (size <= 1)
		return ;
	if (size == 2)
		third_ptr = NULL;
	else
		third_ptr = (*a)->next->next;
	my_lstadd_front(a, (*a)->next);
	(*a)->next->next = third_ptr;
}

/*
// test
// push_swap.cのmainをコメントアウトすれば動く
int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*tmp;

	if (argc == 1)
		return (0);
	a = init_stack(argc, argv);
	b = NULL;
	tmp = a;
	printf("before\n");
	while (a)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
	swap(&tmp);
	printf("after\n");
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	return (0);
}
 */
