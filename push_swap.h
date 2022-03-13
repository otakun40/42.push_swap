/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:01:04 by pjacoby           #+#    #+#             */
/*   Updated: 2022/03/11 01:15:46 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				order_index;
	int				sorted_index;
	int				a_rotate_count;
	int				b_rotate_count;
	int				double_rotate_count;
	int				total_moves_count;
	struct s_stack	*next;
}	t_stack;

t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_add_front(t_stack **stack, t_stack *new);
t_stack	*stack_get_last(t_stack *stack);
int		push(t_stack **dest, t_stack **source, char *str);
void	rotate(t_stack **stack, char *str);
void	rotate_reverse(t_stack **stack, char *str);
void	swap(t_stack **stack, char *str);
void	stack_delete_first(t_stack **stack);
void	exit_failure(char *str);
void	args_2_stack_a(int argc, char **argv, t_stack **stack);
void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
int		stack_get_size(t_stack *stack);
void	stack_set_order_index(t_stack *stack);
void	stack_set_sorted_index(t_stack *stack);
void	push_2_b_by_median(t_stack **a, t_stack **b);
int		is_stack_sorted(t_stack *stack);
void	sort_3_size_stack(t_stack **stack);
void	stacks_set_order(t_stack *a, t_stack *b);
void	set_rotate_scores(t_stack *a, t_stack *b);
int		get_abs(int num);
int		get_min(int a, int b);
int		double_rotate_score(int ra, int rb);
int		single_rotate_score(int rotate_count, int double_rotate_count);
void	stack_delete(t_stack **stack);
void	has_stack_repeat_value(t_stack *stack);
void	push_all_back_2_a(t_stack **a, t_stack **b);
void	rotate_stack_2_begin(t_stack **stack);
int		is_number(char *str);
int		count_strings(char **arr);
void	do_n_double_rotates(t_stack **a, t_stack **b, int dr_num);
void	do_n_a_rotates(t_stack **stack, int rotate_num);
void	do_n_b_rotates(t_stack **stack, int rotate_num);
int		get_rotate_num(int order, int stack_size);
int		find_a_order(t_stack *a, int sorted_index);

#endif
