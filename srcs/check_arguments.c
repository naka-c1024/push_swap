/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 10:38:06 by ynakashi          #+#    #+#             */
/*   Updated: 2022/02/12 09:03:45 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	read_sign(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

int	isint_atoi(char *str)
{
	size_t	i;
	size_t	len;
	int		sign;
	long	ans;

	ans = 0;
	i = 0;
	len = ft_strlen(str);
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		sign = read_sign(str[i++]);
	while (ft_isdigit(str[i]))
	{
		if (sign == 1 && ans > (INT_MAX - (str[i] - '0')) / 10)
			err_to_exit();
		if (sign == -1 && (-1 * ans) < (INT_MIN + (str[i] - '0')) / 10)
			err_to_exit();
		ans *= 10;
		ans += str[i] - '0';
		i++;
	}
	if (len != i)
		err_to_exit();
	return (ans * sign);
}

void	issame_num(int argc, int *value)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 1)
	{
		j = i + 1;
		while (value[j])
		{
			if (value[i] == value[j])
			{
				free(value);
				err_to_exit();
			}
			j++;
		}
		i++;
	}
}

void	check_argv(int argc, char *argv[])
{
	int	i;
	int	j;
	int	*value;

	i = 1;
	j = 0;
	value = (int *)malloc(sizeof(int) * (argc - 1));
	if (!value)
		err_to_exit();
	while (i < argc)
	{
		value[j] = isint_atoi(argv[i]);
		i++;
		j++;
	}
	issame_num(argc, value);
	free(value);
}
