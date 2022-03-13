/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utills2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:41:18 by pjacoby           #+#    #+#             */
/*   Updated: 2022/03/07 12:41:26 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_get_size(t_stack *stack)
{
	int		size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	stack_delete(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*cur;

	cur = *stack;
	while (cur)
	{
		temp = cur;
		cur = cur->next;
		free(temp);
	}
}

int	single_rotate_score(int rotate_count, int double_rotate_count)
{
	if (double_rotate_count == 0)
		return (rotate_count);
	return (rotate_count - double_rotate_count);
}

int	double_rotate_score(int ra, int rb)
{
	if ((ra == 0 || rb == 0) || (ra < 0 && rb > 0) || (ra > 0 && rb < 0))
		return (0);
	if (ra < 0)
		return (get_min(get_abs(ra), get_abs(rb)) * -1);
	else
		return (get_min(ra, rb));
}

void	set_rotate_scores(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;
	int	a_r_score;
	int	b_r_score;

	size_a = stack_get_size(a);
	size_b = stack_get_size(b);
	while (b)
	{
		a_r_score = get_rotate_num(find_a_order(a, b->sorted_index), size_a);
		b_r_score = get_rotate_num(b->order_index, size_b);
		b->double_rotate_count = double_rotate_score(a_r_score,
				b_r_score);
		b->a_rotate_count = single_rotate_score(a_r_score,
				b->double_rotate_count);
		b->b_rotate_count = single_rotate_score(b_r_score,
				b->double_rotate_count);
		b->total_moves_count = get_abs(b->double_rotate_count)
			+ get_abs(b->a_rotate_count) + get_abs(b->b_rotate_count);
		b = b->next;
	}
}
