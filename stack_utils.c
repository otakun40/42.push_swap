/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:30:00 by pjacoby           #+#    #+#             */
/*   Updated: 2022/03/10 23:27:28 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	stack_delete_first(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	*stack = temp->next;
	free(temp);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*current;

	if (*stack == NULL)
		*stack = new;
	else if (new)
	{
		current = *stack;
		while (current->next)
			current = current->next;
		current->next = new;
	}
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
