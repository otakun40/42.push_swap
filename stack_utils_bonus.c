/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:40:48 by pjacoby           #+#    #+#             */
/*   Updated: 2022/03/13 15:40:50 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (new);
	new->value = value;
	new->order_index = 0;
	new->sorted_index = 0;
	new->a_rotate_count = 0;
	new->b_rotate_count = 0;
	new->next = NULL;
	return (new);
}

void	stack_add_front(t_stack **stack, t_stack *new)
{
	if (new)
	{
		new->next = *stack;
		*stack = new;
	}
}

t_stack	*stack_get_last(t_stack *stack)
{
	if (stack)
		while (stack->next)
			stack = stack->next;
	return (stack);
}

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
