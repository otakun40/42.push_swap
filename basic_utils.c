/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic__utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:28:27 by pjacoby           #+#    #+#             */
/*   Updated: 2022/03/10 20:28:39 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int	get_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
