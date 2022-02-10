/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 08:56:45 by ynakashi          #+#    #+#             */
/*   Updated: 2022/02/09 08:57:11 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	exe_cmd(t_stack **a, t_stack **b, int cmd)
{
	if (cmd == SA || cmd == SS)
		swap(a);
	if (cmd == SB || cmd == SS)
		swap(b);
	if (cmd == PA)
		push(a, b);
	if (cmd == PB)
		push(b, a);
	if (cmd == RA || cmd == RR)
		rotate(*a);
	if (cmd == RB || cmd == RR)
		rotate(*b);
	if (cmd == RRA || cmd == RRR)
		reverse_rotate(*a);
	if (cmd == RRB || cmd == RRR)
		reverse_rotate(*b);
	print_cmd(cmd);
}

void	print_cmd(int cmd)
{
	if (cmd == SA)
		ft_putendl_fd("sa", STDOUT_FILENO);
	else if (cmd == SB)
		ft_putendl_fd("sb", STDOUT_FILENO);
	else if (cmd == SS)
		ft_putendl_fd("ss", STDOUT_FILENO);
	else if (cmd == PA)
		ft_putendl_fd("pa", STDOUT_FILENO);
	else if (cmd == PB)
		ft_putendl_fd("pb", STDOUT_FILENO);
	else if (cmd == RA)
		ft_putendl_fd("ra", STDOUT_FILENO);
	else if (cmd == RB)
		ft_putendl_fd("rb", STDOUT_FILENO);
	else if (cmd == RR)
		ft_putendl_fd("rr", STDOUT_FILENO);
	else if (cmd == RRA)
		ft_putendl_fd("rra", STDOUT_FILENO);
	else if (cmd == RRB)
		ft_putendl_fd("rrb", STDOUT_FILENO);
	else if (cmd == RRR)
		ft_putendl_fd("rrr", STDOUT_FILENO);
	else
		err_to_exit();
}
