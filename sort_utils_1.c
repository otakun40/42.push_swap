/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_push_swap_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:05:46 by pjacoby           #+#    #+#             */
/*   Updated: 2022/03/11 02:20:55 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **dest, t_stack **source, char *str)
{
	t_stack	*s;
	t_stack	*source_second;

	if (*source)
	{
		s = *source;
		source_second = s->next;
		stack_add_front(dest, s);
		*source = source_second;
		if (*str)
			ft_printf("%s\n", str);
		return (1);
	}
	return (0);
}

void	rotate(t_stack **stack, char *str)
{
	t_stack	*temp;

	if (!stack)
		return ;
	temp = *stack;
	if (temp->next)
	{
		*stack = temp->next;
		stack_get_last(*stack)->next = temp;
		temp->next = NULL;
		if (*str)
			ft_printf("%s\n", str);
	}
}

void	rotate_reverse(t_stack **stack, char *str)
{
	t_stack	*begin;
	t_stack	*temp;

	if (!stack)
		return ;
	begin = *stack;
	if (begin->next)
	{
		if (*str)
			ft_printf("%s\n", str);
		temp = *stack;
		begin = stack_get_last(begin);
		begin->next = temp;
		*stack = begin;
		while (temp != begin)
		{
			if (temp->next == begin)
			{
				temp->next = NULL;
				return ;
			}
			temp = temp->next;
		}
	}
}

void	swap(t_stack **stack, char *str)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	first = *stack;
	if (first && first->next)
	{
		second = first->next;
		third = first->next->next;
		*stack = second;
		second->next = first;
		first->next = third;
		if (*str)
			ft_printf("%s\n", str);
	}
}
