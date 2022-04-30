/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:24:45 by wismith           #+#    #+#             */
/*   Updated: 2022/04/23 18:35:09 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/push_swap.h"

void	pb(t_num *astack, t_num *bstack)
{
	if (astack->top >= 0)
	{
		bstack->top++;
		bstack->stack[bstack->top] = astack->stack[astack->top];
		astack->top--;
		ft_putstr("pb\n");
	}
}

void	pa(t_num *astack, t_num *bstack)
{
	if (bstack->top >= 0)
	{
		astack->top++;
		astack->stack[astack->top] = bstack->stack[bstack->top];
		bstack->top--;
		ft_putstr("pa\n");
	}
}
