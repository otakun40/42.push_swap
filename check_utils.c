/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:11:11 by pjacoby           #+#    #+#             */
/*   Updated: 2022/03/07 17:11:14 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->next->value < stack->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	has_stack_repeat_value(t_stack *stack)
{
	t_stack	*temp;

	while (stack->next)
	{
		temp = stack->next;
		while (temp)
		{
			if (stack->value == temp->value)
				exit_failure("Error");
			temp = temp->next;
		}
		stack = stack->next;
	}
}

int	count_strings(char **arr)
{
	int		count;

	count = 0;
	while (arr[count])
		count++;
	return (count);
}

int	is_number(char *str)
{
	if (*str == '-')
		str++;
	if (*str < '0' || *str > '9')
		return (0);
	while (ft_isdigit(*str))
		str++;
	if (*str != 0)
		return (0);
	return (1);
}
