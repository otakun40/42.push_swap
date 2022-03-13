/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_params_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:27:51 by pjacoby           #+#    #+#             */
/*   Updated: 2022/03/10 22:21:29 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_pos_diff_result(t_stack *stack, int sorted_index)
{
	int	diff;
	int	pos_diff;
	int	pos_result;

	pos_result = -1;
	pos_diff = 2147483647;
	while (stack)
	{
		diff = stack->sorted_index - sorted_index;
		if (diff > 0 && diff < pos_diff)
		{
			pos_result = stack->order_index;
			pos_diff = diff;
		}
		stack = stack->next;
	}
	return (pos_result);
}

int	get_min_neg_diff_result(t_stack *stack, int sorted_index)
{
	int	diff;
	int	neg_diff;
	int	neg_result;

	neg_result = -1;
	neg_diff = 2147483647;
	while (stack)
	{
		diff = stack->sorted_index - sorted_index;
		if (diff < neg_diff)
		{
			neg_result = stack->order_index;
			neg_diff = diff;
		}
		stack = stack->next;
	}
	return (neg_result);
}

int	find_a_order(t_stack *a, int sorted_index)
{
	int	neg_result;
	int	pos_result;

	neg_result = get_min_neg_diff_result(a, sorted_index);
	pos_result = get_min_pos_diff_result(a, sorted_index);
	if (pos_result < 0)
		return (neg_result);
	return (pos_result);
}

int	get_rotate_num(int order, int stack_size)
{
	if (order <= stack_size / 2)
		return (order);
	return (order - stack_size);
}
