/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 19:53:30 by wismith           #+#    #+#             */
/*   Updated: 2022/05/07 22:16:09 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/push_swap.h"

void	algo_a(t_num *astack, t_num *bstack, t_ghost *ghost, int min_index)
{
	int	min;
	int	top;
	int	div;

	min = 0;
	top = astack->top;
	if (astack->top < 100)
		div = 5;
	else
		div = 11;
	while (astack->top >= div)
	{
		while (has_less_than(astack, ghost->ghosted[top - min]) && min <= top)
		{
			if (nearest_small(astack, ghost->ghosted[top - min])
				&& !(astack->stack[astack->top] <= ghost->ghosted[top - min]))
				ra(astack);
			else if (!(nearest_small(astack, ghost->ghosted[top - min]))
				&& !(astack->stack[astack->top] <= ghost->ghosted[top - min]))
				rra(astack);
			if (astack->stack[astack->top] <= ghost->ghosted[top - min])
				pb(astack, bstack);
		}
		min += min_index;
	}
	astack_rem(astack, bstack);
}

void	algo_b(t_num *astack, t_num *bstack, t_ghost *ghost, int max_index)
{
	int	max;

	max = 0;
	while (bstack->top >= 1)
	{
		while (has_greater_than(bstack, ghost->ghosted[max]))
		{
			if (bstack->stack[bstack->top] < ghost->ghosted[max]
				&& bstack->stack[bstack->top - 1] >= ghost->ghosted[max])
				sb(bstack);
			else if (bstack->stack[bstack->top] < ghost->ghosted[max]
				&& nearest_max(bstack, ghost->ghosted[max]))
				rb(bstack);
			else if (!(bstack->stack[bstack->top] >= ghost->ghosted[max])
				&& !nearest_max(bstack, ghost->ghosted[max]))
				rrb(bstack);
			if (bstack->stack[bstack->top] >= ghost->ghosted[max])
				pa(astack, bstack);
			if (astack->top >= 1
				&& astack->stack[astack->top] > astack->stack[astack->top - 1])
				sa(astack);
		}
		max += max_index;
	}
	bstack_rem(astack, bstack);
}
