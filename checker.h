/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 01:57:16 by pjacoby           #+#    #+#             */
/*   Updated: 2022/03/13 01:57:23 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

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

void	exit_failure(char *str);
void	swap(t_stack **stack, char *str);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
int		push(t_stack **dest, t_stack **source, char *str);
void	rotate(t_stack **stack, char *str);
void	rotate_reverse(t_stack **stack, char *str);
void	ss(t_stack **a, t_stack **b);
t_stack	*stack_get_last(t_stack *stack);
void	has_stack_repeat_value(t_stack *stack);
int		stack_get_size(t_stack *stack);
int		is_stack_sorted(t_stack *stack);
void	free_str_arr(char **arr);
void	args_2_stack_a(int argc, char **argv, t_stack **stack);
void	execute_command(t_stack **a, t_stack **b, char *command);
void	stack_add_front(t_stack **stack, t_stack *new);
int		count_strings(char **arr);
int		is_number(char *str);
t_stack	*stack_new(int value);

#endif
