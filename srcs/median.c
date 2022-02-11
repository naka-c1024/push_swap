/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 09:59:42 by ynakashi          #+#    #+#             */
/*   Updated: 2022/02/11 20:53:14 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*bubble_sort(int *array, size_t size)
{
	int	i;
	int	j;
	int	tmp;

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

int	get_median(t_stack *a, size_t unsorted_size)
{
	int		*num_array;
	int		i;
	int		median;

	i = 0;
	num_array = (int *)malloc(sizeof(int) * unsorted_size);
	if (!num_array)
		err_to_exit();
	while (i < unsorted_size)
	{
		num_array[i] = (a)->value;
		(a) = (a)->next;
		i++;
	}
	num_array = bubble_sort(num_array, unsorted_size);
	median = num_array[unsorted_size / 2];
	free(num_array);
	return (median);
}
