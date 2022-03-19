/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 01:56:09 by pjacoby           #+#    #+#             */
/*   Updated: 2022/03/13 16:04:36 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_failure(char *str)
{
	if (*str)
		ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	execute_command_2(t_stack **a, t_stack **b, char *command, int length)
{
	if (!ft_strncmp(command, "ra", length))
		rotate(a, "");
	else if (!ft_strncmp(command, "rb", length))
		rotate(b, "");
	else if (!ft_strncmp(command, "rr", length))
		rr(a, b);
	else if (!ft_strncmp(command, "rrr", length))
		rrr(a, b);
	else if (!ft_strncmp(command, "rra", length))
		rotate_reverse(a, "");
	else if (!ft_strncmp(command, "rrb", length))
		rotate_reverse(b, "");
	else
		exit_failure("Error");
}

void	execute_command(t_stack **a, t_stack **b, char *command)
{
	int	length;

	length = ft_strlen(command) - 1;
	if (length < 2)
		exit_failure("Error");
	if (!ft_strncmp(command, "pa", length))
		push(a, b, "");
	else if (!ft_strncmp(command, "pb", length))
		push(b, a, "");
	else if (!ft_strncmp(command, "sa", length))
		swap(a, "");
	else if (!ft_strncmp(command, "sb", length))
		swap(b, "");
	else if (!ft_strncmp(command, "ss", length))
		ss(a, b);
	else
		execute_command_2(a, b, command, length);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*command;

	a = 0;
	b = 0;
	if (argc < 2)
		exit(EXIT_SUCCESS);
	args_2_stack_a(argc, argv, &a);
	has_stack_repeat_value(a);
	command = ft_strdup(" ");
	while (command)
	{
		free(command);
		command = get_next_line(0);
		if (command == NULL)
			break ;
		execute_command(&a, &b, command);
	}
	if (!is_stack_sorted(a) || stack_get_size(b) != 0)
		exit_failure("KO");
	ft_printf("OK\n");
	exit(EXIT_SUCCESS);
}
