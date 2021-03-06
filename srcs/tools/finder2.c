/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 16:16:34 by wismith           #+#    #+#             */
/*   Updated: 2022/05/02 16:21:07 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/push_swap.h"

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

int	nearest_max(t_num *stack, int max)
{
	int	i;
	int	index;

	i = stack->top;
	index = 0;
	while (i >= 0 && stack->stack[i] < max)
		i--;
	while (index <= stack->top && stack->stack[index] < max)
		index++;
	return (rtn_index(stack->top, i, index));
}
