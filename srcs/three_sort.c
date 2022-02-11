/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:23:47 by ynakashi          #+#    #+#             */
/*   Updated: 2022/02/11 21:02:21 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	case_three_sort(t_stack **a, t_stack **b)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && first > third)
	{
		if (second > third)
			return (1);
		else if (second < third)
			return (2);
	}
	else if (first < second && first < third)
		return (3);
	else
	{
		if (second > third)
			return (4);
		else if (second < third)
			return (5);
	}
	return (0);
}

bool	is_sort(t_stack *a)
{
	while (a->next)
	{
		if (a->value > a->next->value)
		{
			return (false);
		}
		a = a->next;
	}
	return (true);
}

void	three_sort(t_stack **a, t_stack **b)
{
	int	case_num;

	if (is_sort(*a))
		return ;
	case_num = case_three_sort(a, b);
	if (case_num == 1)
	{
		exe_cmd(a, b, SA);
		exe_cmd(a, b, RRA);
	}
	else if (case_num == 2)
		exe_cmd(a, b, RA);
	else if (case_num == 3)
	{
		exe_cmd(a, b, SA);
		exe_cmd(a, b, RA);
	}
	else if (case_num == 4)
		exe_cmd(a, b, RRA);
	else if (case_num == 5)
		exe_cmd(a, b, SA);
	else if (case_num == 0)
		err_to_exit();
}
