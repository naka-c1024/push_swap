/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 13:48:30 by ynakashi          #+#    #+#             */
/*   Updated: 2022/02/11 20:52:07 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*my_lstnew(int value)
{
	t_stack	*new_element;

	new_element = (t_stack *)malloc(sizeof(t_stack));
	if (!new_element)
		return (NULL);
	new_element->value = value;
	new_element->next = NULL;
	return (new_element);
}

void	my_lstclear(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

t_stack	*my_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	my_lstadd_back(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		(my_lstlast(*lst))->next = new;
}

t_stack	*init_stack(int argc, char *argv[])
{
	t_stack	*new_list;
	t_stack	*a;
	int		i;

	i = 1;
	a = NULL;
	while (i < argc)
	{
		new_list = my_lstnew(ft_atoi(argv[i]));
		if (new_list == NULL)
		{
			my_lstclear(&a);
			err_to_exit();
		}
		my_lstadd_back(&a, new_list);
		i++;
	}
	return (a);
}

/*
// test
// gcc srcs/init_stack.c srcs/error.c libft/libft.a
int	main(int argc, char *argv[])
{
	t_stack	*a;

	if (argc == 1)
		return (0);
	a = init_stack(argc, argv);
	while (a)
	{
		printf("%d\n", a->value);
		a = a->next;
	}
	return (0);
}
 */
