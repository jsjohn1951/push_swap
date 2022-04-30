/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:16:34 by wismith           #+#    #+#             */
/*   Updated: 2022/04/30 00:29:07 by wismith          ###   ########.fr       */
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

int	has_greater_than(t_num *stack, int num)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		if (stack->stack[i] > num)
			return (1);
		i--;
	}
	return (0);
}

int	close_to_mid(t_num *stack, int mid)
{
	int	res;
	int	i;

	i = stack->top + 1;
	res = stack->stack[stack->top];
	while (--i)
		if (abs_value(stack->stack[i], mid) < abs_value(mid, res))
			res = stack->stack[i];
	return (res);
}
