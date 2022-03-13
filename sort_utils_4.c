/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 00:08:10 by pjacoby           #+#    #+#             */
/*   Updated: 2022/03/13 00:08:17 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_n_double_rotates(t_stack **a, t_stack **b, int dr_num)
{
	if (dr_num > 0)
		while (dr_num--)
			rr(a, b);
	else
		while (dr_num++)
			rrr(a, b);
}

void	do_n_a_rotates(t_stack **stack, int rotate_num)
{
	if (rotate_num != 0)
	{
		if (rotate_num > 0)
			while (rotate_num--)
				rotate(stack, "ra");
		else
			while (rotate_num++)
				rotate_reverse(stack, "rra");
	}
}

void	do_n_b_rotates(t_stack **stack, int rotate_num)
{
	if (rotate_num != 0)
	{
		if (rotate_num > 0)
			while (rotate_num--)
				rotate(stack, "rb");
		else
			while (rotate_num++)
				rotate_reverse(stack, "rrb");
	}
}
