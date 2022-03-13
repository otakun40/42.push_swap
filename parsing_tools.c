/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:03:52 by pjacoby           #+#    #+#             */
/*   Updated: 2022/03/10 21:07:21 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
