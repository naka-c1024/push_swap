/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 08:58:23 by ynakashi          #+#    #+#             */
/*   Updated: 2022/02/11 20:56:16 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	size_t	a_size;

	a_size = my_lstsize(*a);
	if (a_size == 2)
		exe_cmd(a, b, SA);
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
