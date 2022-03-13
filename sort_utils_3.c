/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:55:47 by pjacoby           #+#    #+#             */
/*   Updated: 2022/03/11 02:54:31 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_2_b_by_median(t_stack **a, t_stack **b)
{
	int		a_size;
	int		median;
	t_stack	*sa;

	a_size = stack_get_size(*a);
	median = a_size / 2;
	while (a_size > 3 && !is_stack_sorted(*a))
	{
		sa = *a;
		push(b, a, "pb");
		if (sa->sorted_index > median)
			rotate(b, "rb");
		a_size--;
	}
}

void	sort_3_size_stack(t_stack **stack)
{
	t_stack	*st;

	st = *stack;
	if (st->value > st->next->value && st->value > st->next->next->value)
		rotate(stack, "ra");
	else if (st->next->value > st->value
		&& st->next->value > st->next->next->value)
		rotate_reverse(stack, "rra");
	st = *stack;
	if (st->value > st->next->value)
		swap(stack, "sa");
}

t_stack	*get_min_moves_node(t_stack *stack)
{
	int		min;
	t_stack	*temp;
	t_stack	*result;

	min = 2147483647;
	temp = stack;
	while (temp)
	{
		if (temp->total_moves_count < min)
		{
			min = temp->total_moves_count;
			result = temp;
		}
		temp = temp->next;
	}
	return (result);
}

void	push_all_back_2_a(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		b_size;

	b_size = stack_get_size(*b);
	while (b_size-- > 0)
	{
		stacks_set_order(*a, *b);
		set_rotate_scores(*a, *b);
		temp = get_min_moves_node(*b);
		do_n_double_rotates(a, b, temp->double_rotate_count);
		do_n_a_rotates(a, temp->a_rotate_count);
		do_n_b_rotates(b, temp->b_rotate_count);
		push(a, b, "pa");
	}
}

void	rotate_stack_2_begin(t_stack **stack)
{
	int		rotate_num;
	int		pos;
	int		size;
	t_stack	*cur;

	pos = 0;
	rotate_num = 0;
	size = stack_get_size(*stack);
	cur = *stack;
	while (cur)
	{
		if (cur->sorted_index == 0)
		{
			if (pos <= size / 2)
				rotate_num = pos;
			else
				rotate_num = pos - size;
			break ;
		}
		pos++;
		cur = cur->next;
	}
	do_n_a_rotates(stack, rotate_num);
}
