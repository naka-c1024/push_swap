/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:46:28 by ynakashi          #+#    #+#             */
/*   Updated: 2022/02/11 20:55:21 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_stack *a)
{
	size_t	size;
	int		i;
	int		*tmp;

	if (!a)
		return ;
	size = my_lstsize(a);
	tmp = (int *)malloc(size * sizeof(int));
	if (!tmp)
		return ;
	tmp[0] = a->value;
	a->value = (my_lstlast(a))->value;
	a = a->next;
	i = 0;
	while (i < size - 1)
	{
		tmp[i + 1] = a->value;
		a->value = tmp[i];
		i++;
		a = a->next;
	}
	free(tmp);
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
	reverse_rotate(c);
	printf("after:a\n");
	while (c)
	{
		printf("%d\n", c->value);
		c = c->next;
	}
	return (0);
}
 */
