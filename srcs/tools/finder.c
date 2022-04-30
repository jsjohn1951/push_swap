/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 10:52:16 by wismith           #+#    #+#             */
/*   Updated: 2022/04/30 17:35:30 by wismith          ###   ########.fr       */
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
	int	res;

	i = stack->top;
	res = stack->stack[i];
	while (i >= 0)
	{
		if (stack->stack[i] < res)
			res = stack->stack[i];
		i--;
	}
	return (res);
}

int	find_big(t_num *stack)
{
	int	i;
	int	res;

	i = stack->top;
	res = stack->stack[i];
	while (i >= 0)
	{
		if (stack->stack[i] > res)
			res = stack->stack[i];
		i--;
	}
	return (res);
}

int	find_mid(t_num *stack)
{
	int	i;
	int	res;

	i = stack->top;
	res = 0;
	if (stack->top >= 0)
	{
		while (i >= 0)
		{
			res += stack->stack[i];
			i--;
		}
		return (res / (stack->top + 1));
	}
	return (0);
}
