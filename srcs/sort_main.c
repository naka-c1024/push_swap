/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 08:58:23 by ynakashi          #+#    #+#             */
/*   Updated: 2022/02/11 17:49:07 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// void	a_to_b(t_stack **a, t_stack **b, size_t unsorted_size)
// {
// 	int	ra_times;
// 	int	pb_times;
// 	int	pivot;
// 	int	i;

// 	if (unsorted_size == 1)
// 	{
// 		return ;
// 	}
// 	pivot = get_median(*a, unsorted_size);
// 	ra_times = 0;
// 	pb_times = 0;
// 	i = 0;
// 	while (i < unsorted_size && *a)
// 	{
// 		if ((*a)->value > pivot)
// 		{
// 			exe_cmd(a, b, RA);
// 			ra_times++;
// 		}
// 		else
// 		{
// 			exe_cmd(a, b, PB);
// 			pb_times++;
// 		}
// 		*a = (*a)->next;
// 		i++;
// 	}
// 	i = ra_times;
// 	while (ra_times--)
// 	{
// 		exe_cmd(a, b, RRA);
// 	}
// 	a_to_b(a, b, i);
// 	b_to_a(a, b, pb_times);
// }

// void	b_to_a(t_stack **a, t_stack **b, size_t unsorted_size)
// {
// 	int	rb_times;
// 	int	pa_times; // これ本当に必要?
// 	int	pivot;
// 	int	i;

// 	if (unsorted_size == 1)
// 	{
// 		return ; // pa
// 	}
// 	pivot = get_median(*b, unsorted_size);
// 	rb_times = 0;
// 	pa_times = 0;
// 	i = 0;
// 	while (i < unsorted_size && *b)
// 	{
// 		// if ((*b)->value > pivot) // ここが逆
// 		if ((*b)->value < pivot) // ここが逆
// 		{
// 			exe_cmd(a, b, RB);
// 			rb_times++;
// 		}
// 		else
// 		{
// 			exe_cmd(a, b, PA);
// 			pa_times++;
// 		}
// 		*b = (*b)->next;
// 		i++;
// 	}
// 	i = rb_times;
// 	while (rb_times--)
// 	{
// 		exe_cmd(a, b, RRB);
// 	}
// 	a_to_b(a, b, pa_times);
// 	b_to_a(a, b, i);
// }

void	sort(t_stack **a, t_stack **b)
{
	size_t	a_size;

	a_size = my_lstsize(*a); // 0と1は既に省いてある
	if (a_size == 2)
		exe_cmd(a, b, SA); // should_sortでsortできないやつは省いているからここではsaを実行する
	else if (a_size == 3)
		three_sort(a, b);
	else if (a_size < 7)
	{
		under_seven_sort(a, b, a_size);
	}
	else
	{
		quicksort(a, b);
	}
}
