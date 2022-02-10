/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_seven_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:36:01 by ynakashi          #+#    #+#             */
/*   Updated: 2022/02/09 13:36:31 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_min_ptr_nth(t_stack *a)
{
	t_stack	*min_ptr;
	int		nth;
	int		i;

	min_ptr = a;
	nth = 0;
	i = 0;
	while (a)
	{
		if (min_ptr->value > a->value)
		{
			min_ptr = a;
			nth = i;
		}
		a = a->next;
		i++;
	}
	return (nth);
}

void	pb_min(t_stack **a, t_stack **b)
{
	int		nth;
	size_t	a_size;

	a_size = my_lstsize(*a);
	nth = get_min_ptr_nth(*a);
	if (nth < a_size / 2)
	{
		while (nth--)
			exe_cmd(a, b, RA);
	}
	else
	{
		nth = a_size - nth;
		while (nth--)
			exe_cmd(a, b, RRA);
	}
	exe_cmd(a, b, PB);
}

void	under_seven_sort(t_stack **a, t_stack **b, size_t a_size)
{
	int	i;

	i = 0;
	while (i < a_size - 3)
	{
		pb_min(a, b);
		i++;
	}
	three_sort(a, b);
	i = 0;
	while (i < a_size - 3)
	{
		exe_cmd(a, b, PA);
		i++;
	}
}
