/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:10:53 by wismith           #+#    #+#             */
/*   Updated: 2022/05/07 20:09:34 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/push_swap.h"

void	sort_two(t_num *astack)
{
	if (!is_sorted(astack) && astack->top == 1)
		sa(astack);
}

void	sort_three(t_num *astack)
{
	if (!is_sorted(astack) && astack->top == 2)
	{
		if (astack->stack[astack->top] > astack->stack[astack->top - 1]
			&& astack->stack[astack->top] < astack->stack[0])
			sa(astack);
		else if (astack->stack[astack->top] < astack->stack[astack->top - 1]
			&& astack->stack[astack->top] > astack->stack[0])
			rra(astack);
		else if (astack->stack[astack->top] > astack->stack[astack->top - 1]
			&& astack->stack[astack->top - 1] > astack->stack[0])
		{
			ra(astack);
			sa(astack);
		}
		else if (astack->stack[astack->top] < astack->stack[astack->top - 1]
			&& astack->stack[astack->top - 1] > astack->stack[0])
		{
			rra(astack);
			sa(astack);
		}
		else if (astack->stack[astack->top] > astack->stack[astack->top - 1]
			&& astack->stack[astack->top - 1] < astack->stack[0])
			ra(astack);
	}
}

void	sort_five(t_num *astack, t_num *bstack)
{
	t_ghost	ghost;

	if (!is_sorted(astack) && astack->top <= 4 && astack->top > 2)
	{
		ghost.ghosted = (int *)ft_calloc(astack->top + 2, sizeof(int));
		set_ghosted(astack, &ghost);
		while (astack->top >= 2)
		{
			if (astack->stack[astack->top - 1] <= ghost.ghosted[2])
				sa(astack);
			if (astack->stack[astack->top] <= ghost.ghosted[2])
				pb(astack, bstack);
			if (nearest_small(astack, ghost.ghosted[2]))
				rra(astack);
			else
				ra(astack);
		}
		sort_five_bstack_rem(astack, bstack);
		free(ghost.ghosted);
	}
}

void	sort(t_num *astack, t_num *bstack)
{
	t_ghost	ghost;
	int		min_index;
	int		max_index;

	if (!is_sorted(astack) && astack->top >= 5)
	{
		ghost.ghosted = (int *)ft_calloc(astack->top + 2, sizeof(int));
		if (astack->top <= 4)
			min_index = 2;
		else if (astack->top < 100)
			min_index = (astack->top) / 5;
		else
			min_index = (astack->top) / 11;
		max_index = 2;
		set_ghosted(astack, &ghost);
		algo_a(astack, bstack, &ghost, min_index);
		algo_b(astack, bstack, &ghost, max_index);
		free(ghost.ghosted);
	}
}
