/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 17:46:47 by pjacoby           #+#    #+#             */
/*   Updated: 2022/03/06 17:46:52 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	swap(a, "");
	swap(b, "");
	ft_printf("ss\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, "");
	rotate(b, "");
	ft_printf("rr\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rotate_reverse(a, "");
	rotate_reverse(b, "");
	ft_printf("rrr\n");
}
