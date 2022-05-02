/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:10:53 by wismith           #+#    #+#             */
/*   Updated: 2022/05/02 13:23:06 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/push_swap.h"

void	sort_three(t_num *astack, t_num *bstack)
{
	if (astack->top <= 2)
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
	int	small;
	int	flag;

	if (!is_sorted(astack))
	{
		while (astack->top > 2)
		{
			flag = 0;
			small = find_small(astack);
			if (find_pos(astack, small) < astack->top / 2)
				flag = 1;
			while (astack->stack[astack->top] != small && flag)
				rra(astack);
			while (astack->stack[astack->top] != small && !flag)
				ra(astack);
			pb(astack, bstack);
		}
		sort_three(astack, bstack);
	}
	while (bstack->top >= bstack->bottom)
		pa(astack, bstack);
}

void	algo_a(t_num *astack, t_num *bstack, t_ghost *ghost, int min_index)
{
	int	min;
	int	top;

	min = min_index;
	top = astack->top;
	while (astack->top >= 5)
	{
		while (has_less_than(astack, ghost->ghosted[top - min]) && min <= top)
		{
			if (astack->stack[astack->top - 1] <= ghost->ghosted[top - min]
				&& bstack->stack[bstack->top] < bstack->stack[bstack->top - 1])
				ss(astack, bstack);
			else if (astack->stack[astack->top - 1] <= ghost->ghosted[top - min]
				&& !(astack->stack[astack->top] <= ghost->ghosted[top - min]))
				sa(astack);
			else if (nearest_small(astack, ghost->ghosted[top - min])
				&& !(astack->stack[astack->top] <= ghost->ghosted[top - min]))
				ra(astack);
			else if (!(astack->stack[astack->top] <= ghost->ghosted[top - min]))
				rra(astack);
			if (astack->stack[astack->top] <= ghost->ghosted[top - min])
				pb(astack, bstack);
		}
		min += min_index;
	}
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
			if (astack->top >= 1 && astack->stack[astack->top] > astack->stack[astack->top - 1])
				sa(astack);
		}
		max += max_index;
	}
	while (bstack->top >= 0)
	{
		if (bstack->stack[bstack->top] < bstack->stack[0])
			sb(bstack);
		pa(astack, bstack);
	}
}

// void	algo_b(t_num *astack, t_num *bstack)
// {
// 	while (bstack->top >= 0)
// 	{
// 		if (find_pos(bstack, find_big(bstack)) == bstack->top - 1)
// 			sb(bstack);
// 		else if (find_pos(bstack, find_big(bstack)) > bstack->top / 2
// 			&& find_pos(bstack, find_big(bstack)) != bstack->top)
// 			rb(bstack);
// 		else if (find_pos(bstack, find_big(bstack)) <= bstack->top / 2
// 			&& find_pos(bstack, find_big(bstack)) != bstack->top)
// 			rrb(bstack);
// 		else
// 			pa(astack, bstack);
// 		if (astack->top >= 1)
// 		{
// 			if (astack->stack[astack->top] > astack->stack[astack->top - 1])
// 				sa(astack);
// 		}
// 	}
// }

void	sort_hundred(t_num *astack, t_num *bstack)
{
	t_ghost	ghost;
	int		min_index;
	int		max_index;

	if (!is_sorted(astack))
	{
		ghost.ghosted = (int *)ft_calloc(astack->top + 2, sizeof(int));
		if (astack->top < 100)
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
