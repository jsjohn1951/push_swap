/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:16:34 by wismith           #+#    #+#             */
/*   Updated: 2022/05/01 23:25:07 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/push_swap.h"

int	abs_value(int num1, int num2)
{
	int	res;

	res = 0;
	if (num1 < num2)
	{
		while (num1 < num2)
		{
			res++;
			num1++;
		}
	}
	else if (num2 < num1)
	{
		while (num2 < num1)
		{
			res++;
			num2++;
		}
	}
	return (res);
}

int	rtn_index(int top, int i, int index)
{
	if (top - i < index)
		return (1);
	else
		return (0);
}

int	nearest_small(t_num *stack, int min)
{
	int	i;
	int	index;

	i = stack->top;
	index = 0;
	while (i >= 0 && stack->stack[i] > min)
		i--;
	while (index <= stack->top && stack->stack[index] > min)
		index++;
	return (rtn_index(stack->top, i, index));
}

int	has_less_than(t_num *stack, int num)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		if (stack->stack[i] < num)
			return (1);
		i--;
	}
	return (0);
}
