/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:37:39 by pjacoby           #+#    #+#             */
/*   Updated: 2022/03/13 15:37:41 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_number(char *str)
{
	if (*str == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str != 0)
		return (0);
	return (1);
}

int	count_strings(char **arr)
{
	int		count;

	count = 0;
	while (arr[count])
		count++;
	return (count);
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
