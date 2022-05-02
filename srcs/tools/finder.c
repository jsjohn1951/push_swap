/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:52:16 by wismith           #+#    #+#             */
/*   Updated: 2022/05/02 16:51:41 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/push_swap.h"

int	find_pos(t_num *stack, int small)
{
	int	i;

	i = stack->top;
	while (stack->stack[i] != small)
		i--;
	return (i);
}

int	is_sorted(t_num *stack)
{
	int	i;

	if (stack->top == -1)
		return (1);
	i = stack->top - 1;
	while (i >= 0)
	{
		if (stack->stack[i] < stack->stack[i + 1])
			return (0);
		i--;
	}
	return (1);
}

int	find_small(t_num *stack)
{
	int	i;
	int	index;
	int	res;

	i = stack->top;
	res = stack->stack[i];
	index = 0;
	while (i >= 0 && !(stack->stack[i] < res))
		i--;
	while (index <= stack->top && !(stack->stack[i] < res))
		index++;
	if (rtn_index(stack->top, i, index))
		stack->small = stack->stack[i];
	else
		stack->small = stack->stack[index];
	return (rtn_index(stack->top, i, index));
}
