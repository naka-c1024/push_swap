/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakashi <ynakashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:56:57 by ynakashi          #+#    #+#             */
/*   Updated: 2022/02/11 20:51:54 by ynakashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h> // write, read
# include <stdlib.h> // malloc, free, exit
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef enum e_cmd
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_cmd;

// error.c
void	err_to_exit(void);

// check_arguments.c
int		read_sign(char c);
int		isint_atoi(char *str);
void	check_argv(int argc, char *argv[]);
void	issame_num(int argc, int *value);

// init_stack.c
t_stack	*my_lstnew(int value);
void	my_lstclear(t_stack **lst);
t_stack	*my_lstlast(t_stack *lst);
void	my_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*init_stack(int argc, char *argv[]);

// swap.c
size_t	my_lstsize(t_stack *lst);
void	my_lstadd_front(t_stack **lst, t_stack *new);
void	swap(t_stack **a);

// push.c
void	push(t_stack **passive, t_stack **active);

// rotate.c
void	rotate(t_stack *a);

// reverse_rotate.c
void	reverse_rotate(t_stack *a);

// cmd.c
void	exe_cmd(t_stack **a, t_stack **b, int cmd);
void	print_cmd(int cmd);

// main.c
void	should_sort(t_stack *a);

// sort_main.c
void	sort(t_stack **a, t_stack **b);

// three_sort.c
int		case_three_sort(t_stack **a, t_stack **b);
void	three_sort(t_stack **a, t_stack **b);
bool	is_sort(t_stack *a);

// under_seven_sort.c
int		get_min_ptr_nth(t_stack *a);
void	pb_min(t_stack **a, t_stack **b);
void	under_seven_sort(t_stack **a, t_stack **b, size_t a_size);

// quicksort.c
void	quicksort(t_stack **a, t_stack **b);
void	under_three_sort_a(t_stack **a, t_stack **b, int unsorted_size);
void	under_three_sort_b(t_stack **a, t_stack **b, int unsorted_size);
void	b_to_a(t_stack **a, t_stack **b, int pb_times);
void	a_to_b(t_stack **a, t_stack **b, int unsorted_size);

// median.c
int		*bubble_sort(int *array, size_t size);
int		get_median(t_stack *a, size_t unsorted_size);

#endif