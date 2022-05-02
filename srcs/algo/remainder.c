/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remainder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:26:22 by wismith           #+#    #+#             */
/*   Updated: 2022/05/02 14:32:36 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/push_swap.h"

void	astack_rem(t_num *astack, t_num *bstack)
{
	while (astack->top >= 1)
	{
		if (astack->stack[astack->top] > astack->stack[0]
			&& !(astack->stack[astack->top - 1] < astack->stack[0]))
			rra(astack);
		else if (astack->stack[astack->top] > astack->stack[astack->top - 1])
			sa(astack);
		else
			ra(astack);
		pb(astack, bstack);
	}
	if (astack->stack[astack->top] > astack->stack[0])
		sa(astack);
}

void	bstack_rem(t_num *astack, t_num *bstack)
{
	while (bstack->top >= 0)
	{
		if (bstack->stack[bstack->top] < bstack->stack[0])
			sb(bstack);
		pa(astack, bstack);
	}
}
