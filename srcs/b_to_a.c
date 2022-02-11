/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:50:35 by ynakashi          #+#    #+#             */
/*   Updated: 2022/02/12 08:24:09 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	int	pa_times;
	int	rb_times;
	int	pivot;
	int	tmp;

	if (pb_times <= 2)
		return (under_three_sort_b(a, b, pb_times));
	pivot = get_median(*b, pb_times);
	pa_times = 0;
	rb_times = 0;
	tmp = pb_times;
	while (tmp--)
	{
		if ((*b)->value > pivot && pa_times++ < INT_MAX)
			exe_cmd(a, b, PA);
		else
		{
			exe_cmd(a, b, RB);
			rb_times++;
		}
	}
	while (rb_times--)
		exe_cmd(a, b, RRB);
	a_to_b(a, b, pa_times);
	b_to_a(a, b, pb_times - pa_times);
}
