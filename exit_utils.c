/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjacoby <pjacoby@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:56:49 by pjacoby           #+#    #+#             */
/*   Updated: 2022/03/06 20:56:52 by pjacoby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_failure(char *str)
{
	if (*str)
		ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}
