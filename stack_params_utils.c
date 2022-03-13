/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_params_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:38:39 by pjacoby           #+#    #+#             */
/*   Updated: 2022/03/07 14:38:50 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_set_sorted_index(t_stack *stack)
{
	int		index;
	t_stack	*begin;
	t_stack	*current;

	begin = stack;
	while (stack)
	{
		index = 0;
		current = begin;
		while (current)
		{
			if (stack->value > current->value)
				index++;
			current = current->next;
		}
		stack->sorted_index = index;
		stack = stack->next;
	}
}

void	stack_set_order_index(t_stack *stack)
{
	int		order;

	order = 0;
	while (stack)
	{
		stack->order_index = order;
		order++;
		stack = stack->next;
	}
}

void	stacks_set_order(t_stack *a, t_stack *b)
{
	stack_set_order_index(a);
	stack_set_order_index(b);
}
