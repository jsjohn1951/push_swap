/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:24:28 by wismith           #+#    #+#             */
/*   Updated: 2022/05/02 12:26:18 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/push_swap.h"

int	has_less_than(t_num *stack, int num)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		if (stack->stack[i] <= num)
			return (1);
		i--;
	}
	return (0);
}

int	has_greater_than(t_num *stack, int num)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		if (stack->stack[i] >= num)
			return (1);
		i--;
	}
	return (0);
}
