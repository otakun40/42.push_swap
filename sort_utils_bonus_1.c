/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_bonus_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 12:05:46 by pjacoby           #+#    #+#             */
/*   Updated: 2022/03/11 02:20:55 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, char *str)
{
	t_stack	*temp;

	if (stack && *stack)
	{
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
}

void	rotate_reverse(t_stack **stack, char *str)
{
	t_stack	*begin;
	t_stack	*temp;

	if (stack && *stack)
	{
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
}

void	free_str_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	args_2_stack_a(int argc, char **argv, t_stack **stack)
{
	int		args;
	long	num;
	char	**arr;

	while (--argc >= 1)
	{
		arr = ft_split(argv[argc], ' ');
		args = count_strings(arr);
		while (--args >= 0)
		{
			if (!is_number(arr[args]))
				exit_failure("Error");
			num = ft_atoi(arr[args]);
			if (num < -2147483648 || num > 2147483647)
				exit_failure("Error");
			stack_add_front(stack, stack_new((int)num));
		}
		free_str_arr(arr);
	}
}
