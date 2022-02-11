/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:52:28 by ynakashi          #+#    #+#             */
/*   Updated: 2022/02/11 17:40:09 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	under_three_sort_a(t_stack **a, t_stack **b, int unsorted_size)
{
	if (unsorted_size == 1)
		return ;
	if (unsorted_size == 2)
	{
		if ((*a)->value > (*a)->next->value)
		{
			exe_cmd(a, b, SA);
		}
	}
}

void	under_three_sort_b(t_stack **a, t_stack **b, int unsorted_size)
{
	if (unsorted_size == 1)
	{
		exe_cmd(a, b, PA);
	}
	if (unsorted_size == 2)
	{
		if ((*b)->value < (*b)->next->value)
		{
			exe_cmd(a, b, SB);
		}
		exe_cmd(a, b, PA);
		exe_cmd(a, b, PA);
	}
}

void	b_to_a(t_stack **a, t_stack **b, int pb_times)
{
	int		pa_times;
	int		rb_times;
	int		pivot;
	int		tmp;

	if (pb_times <= 2)
	{
		under_three_sort_b(a, b, pb_times);
		return ;
	}
	pivot = get_median(*b, pb_times);
	pa_times = 0;
	rb_times = 0;
	tmp = pb_times;
	while (tmp--)
	{
		if ((*b)->value > pivot)
		{
			exe_cmd(a, b, PA);
			pa_times++;
		}
		else
		{
			exe_cmd(a, b, RB);
			rb_times++;
		}
	}
	while (rb_times--)
	{
		exe_cmd(a, b, RRB);
	}
	a_to_b(a, b, pa_times);
	b_to_a(a, b, pb_times - pa_times);
}

void	a_to_b(t_stack **a, t_stack **b, int unsorted_size)
{
	int	pb_times;
	int	ra_times;
	int	pivot;
	int	tmp;

	if (unsorted_size <= 2)
	{
		under_three_sort_a(a, b, unsorted_size);
		return ;
	}
	pivot = get_median(*a, unsorted_size);
	pb_times = 0;
	ra_times = 0;
	tmp = unsorted_size;
	while (tmp--)
	{
		if ((*a)->value < pivot)
		{
			exe_cmd(a, b, PB);
			pb_times++;
		}
		else
		{
			exe_cmd(a, b, RA); // *a = (*a)->next;と同じ
			ra_times++;
		}
	}
	while (ra_times--)
	{
		exe_cmd(a, b, RRA);
	}
	a_to_b(a, b, unsorted_size - pb_times);
	b_to_a(a, b, pb_times);
}

void	quicksort(t_stack **a, t_stack **b)
{
	a_to_b(a, b, my_lstsize(*a));
}
