/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:56:50 by wismith           #+#    #+#             */
/*   Updated: 2022/04/23 21:10:36 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/push_swap.h"

void	sa(t_num *astack)
{
	int	temp;

	if (astack->top >= 1)
	{
		temp = astack->stack[astack->top];
		astack->stack[astack->top] = astack->stack[astack->top - 1];
		astack->stack[astack->top - 1] = temp;
		ft_putstr("sa\n");
	}
}

void	sb(t_num *bstack)
{
	int	temp;

	if (bstack->top >= 1)
	{
		temp = bstack->stack[bstack->top];
		bstack->stack[bstack->top] = bstack->stack[bstack->top - 1];
		bstack->stack[bstack->top - 1] = temp;
		ft_putstr("sb\n");
	}
}

void	ss(t_num *astack, t_num *bstack)
{
	int	temp;

	if (astack->top >= 1 && bstack->top >= 1)
		ft_putstr("ss\n");
	else
		return ;
	if (astack->top >= 1)
	{
		temp = astack->stack[astack->top];
		astack->stack[astack->top] = astack->stack[astack->top - 1];
		astack->stack[astack->top - 1] = temp;
	}
	if (bstack->top >= 1)
	{
		temp = bstack->stack[bstack->top];
		bstack->stack[bstack->top] = bstack->stack[bstack->top - 1];
		bstack->stack[bstack->top - 1] = temp;
	}
}
