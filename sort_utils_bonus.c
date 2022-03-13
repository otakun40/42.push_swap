/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:05:46 by pjacoby           #+#    #+#             */
/*   Updated: 2022/03/11 02:20:55 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, "");
	rotate(b, "");
}

void	rrr(t_stack **a, t_stack **b)
{
	rotate_reverse(a, "");
	rotate_reverse(b, "");
}

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

void	ss(t_stack **a, t_stack **b)
{
	swap(a, "");
	swap(b, "");
}
