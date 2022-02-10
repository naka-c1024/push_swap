/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 08:58:23 by ynakashi          #+#    #+#             */
/*   Updated: 2022/02/10 10:27:13 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// void	selection_sort(t_stack **a, t_stack **b, size_t a_size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < a_size)
// 	{
// 		pb_min(a, b);
// 		i++;
// 	}
// 	while (i--)
// 	{
// 		exe_cmd(a, b, PA);
// 	}
// }

void	b_to_a(t_stack **a, t_stack **b, size_t unsorted_size); // 後でこれ消す

int	*bubble_sort(int *array, size_t size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (array);
}

int	get_median(t_stack *a)
{
	size_t	size;
	int	*num_array;
	int	i;
	int	median;

	size = my_lstsize(a);
	num_array = (int *)malloc(sizeof(int) * size);
	if (!num_array)
		err_to_exit();
	i = 0;
	while (a)
	{
		num_array[i] = a->value;
		a = a->next;
		i++;
	}
	num_array = bubble_sort(num_array, size);
	median = num_array[size / 2];
	free(num_array);
	return (median);
}

t_stack	* create_unsorted_stack(t_stack **a, size_t unsorted_size)
{

}

void	a_to_b(t_stack **a, t_stack **b, size_t unsorted_size)
{
	int	ra_times;
	int	pb_times; // これ本当に必要?
	int	pivot;
	int	i;
	t_stack	*unsorted_stack;

	if (unsorted_size == 1)
	{
		return ;
	}

	unsorted_stack = create_unsorted_stack(a, unsorted_size);

	pivot = get_median(unsorted_stack);
	ra_times = 0;
	pb_times = 0;
	i = 0;
	while (i < unsorted_size)
	{
		if ((*a)->value > pivot)
		{
			exe_cmd(a, b, RA);
			ra_times++;
		}
		else
		{
			exe_cmd(a, b, PB);
			pb_times++;
		}
		*a = (*a)->next;
		i++;
	}
	while (ra_times--)
	{
		exe_cmd(a, b, RRA);
	}
	// a_to_b(a, b);
	// b_to_a(a, b);
}

void	b_to_a(t_stack **a, t_stack **b, size_t unsorted_size)
{
	int	rb_times;
	int	pa_times; // これ本当に必要?
	int	pivot;
	int	i;

	if (my_lstsize(*b) == 1)
	{
		return ;
	}
	pivot = get_median(*b);
	rb_times = 0;
	pa_times = 0;
	i = 0;
	while (i < unsorted_size)
	{
		if ((*b)->value > pivot)
		{
			exe_cmd(a, b, RB);
			rb_times++;
		}
		else
		{
			exe_cmd(a, b, PA);
			pa_times++;
		}
		*b = (*b)->next;
		i++;
	}
	while (rb_times--)
	{
		exe_cmd(a, b, RRB);
	}
	// a_to_b(a, b,);
	// b_to_a(a, b);
}

void	quicksort(t_stack **a, t_stack **b)
{
	a_to_b(a, b, my_lstsize(*a));
}

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
		// selection_sort(a, b, a_size); // これではダメだった
		quicksort(a, b);
	}
}
