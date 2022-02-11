/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:46:12 by ynakashi          #+#    #+#             */
/*   Updated: 2022/02/12 08:23:15 by ynakashi         ###   ########.fr       */
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

void	a_to_b(t_stack **a, t_stack **b, int unsorted_size)
{
	int	pb_times;
	int	ra_times;
	int	pivot;
	int	tmp;

	if (unsorted_size <= 2)
		return (under_three_sort_a(a, b, unsorted_size));
	pivot = get_median(*a, unsorted_size);
	pb_times = 0;
	ra_times = 0;
	tmp = unsorted_size;
	while (tmp--)
	{
		if ((*a)->value < pivot && pb_times++ < INT_MAX)
			exe_cmd(a, b, PB);
		else
		{
			exe_cmd(a, b, RA);
			ra_times++;
		}
	}
	while (ra_times--)
		exe_cmd(a, b, RRA);
	a_to_b(a, b, unsorted_size - pb_times);
	b_to_a(a, b, pb_times);
}
