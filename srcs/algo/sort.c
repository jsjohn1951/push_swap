/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:10:53 by wismith           #+#    #+#             */
/*   Updated: 2022/05/06 19:04:58 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/push_swap.h"

void	sort_three(t_num *astack, t_num *bstack)
{
	if (!is_sorted(astack) && astack->top <= 2)
	{
		if (astack->stack[astack->top] < astack->stack[astack->top - 1]
			&& astack->stack[astack->top] < astack->stack[bstack->bottom]
			&& astack->stack[astack->top - 1] > astack->stack[bstack->bottom])
			pb(astack, bstack);
		if (astack->stack[astack->top] > astack->stack[astack->top - 1])
			sa(astack);
		if (astack->stack[astack->top - 1] > astack->stack[bstack->bottom])
			rra(astack);
		if (bstack->top == bstack->bottom)
			pa(astack, bstack);
	}
}

void	sort_five(t_num *astack, t_num *bstack)
{
	t_ghost	ghost;

	if (!is_sorted(astack) && astack->top <= 4)
	{
		ghost.ghosted = (int *)ft_calloc(astack->top + 2, sizeof(int));
		set_ghosted(astack, &ghost);
		while (astack->top >= 3)
		{
			if (astack->stack[astack->top] <= ghost.ghosted[3])
				pb(astack, bstack);
			if (nearest_small(astack, ghost.ghosted[3]))
				ra(astack);
			else
				rra(astack);
		}
		bstack_rem(astack, bstack);
		free(ghost.ghosted);
	}
}

void	algo_a(t_num *astack, t_num *bstack, t_ghost *ghost, int min_index)
{
	int	min;
	int	top;

	min = 0;
	top = astack->top;
	while (astack->top >= 5)
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

void	sort(t_num *astack, t_num *bstack)
{
	t_ghost	ghost;
	int		min_index;
	int		max_index;

	if (!is_sorted(astack))
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
