/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:02:04 by pjacoby           #+#    #+#             */
/*   Updated: 2022/03/13 16:01:10 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_nodes_stack(t_stack **stack)
{
	t_stack	*st;

	st = *stack;
	if (st->value > st->next->value)
	{
		swap(stack, "sa");
		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = 0;
	b = 0;
	if (argc < 2)
		exit(EXIT_SUCCESS);
	args_2_stack_a(argc, argv, &a);
	has_stack_repeat_value(a);
	if (is_stack_sorted(a))
		exit(EXIT_SUCCESS);
	stack_set_sorted_index(a);
	if (stack_get_size(a) == 2)
		sort_2_nodes_stack(&a);
	if (stack_get_size(a) == 3)
	{
		sort_3_size_stack(&a);
		exit(EXIT_SUCCESS);
	}
	push_2_b_by_median(&a, &b);
	sort_3_size_stack(&a);
	push_all_back_2_a(&a, &b);
	rotate_stack_2_begin(&a);
	stack_delete(&a);
	stack_delete(&b);
}
