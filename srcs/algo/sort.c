/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:10:53 by wismith           #+#    #+#             */
/*   Updated: 2022/04/30 20:15:32 by wismith          ###   ########.fr       */
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

	flag = 0;
	if (!is_sorted(astack))
	{
		while (astack->top > 2)
		{
			small = find_small(astack);
			if (find_pos(astack, small) < astack->top / 2)
				flag = 1;
			while (astack->stack[astack->top] != small && flag == 1)
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

void	printer2(t_ghost *ghost, int i)
{
	while (i >= 0)
	{
		ft_printf("%d\n", ghost->ghosted[i]);
		i--;
	}
}

void	sort_hundred(t_num *astack, t_num *bstack)
{
	t_ghost	ghost;

	ghost.ghosted = (int *)ft_calloc(astack->top + 2, sizeof(int));
	(void) bstack;
	set_ghosted(astack, &ghost);
	printer2(&ghost, astack->top);
	free(ghost.ghosted);
}

// void	algo_a(t_num *astack, t_num *bstack)
// {
// 	int	mid;

// 	mid = (astack->top + 1) / 2;
// 	while (has_less_than(astack, mid))
// 	{
// 		while (has_less_than(astack, mid) && astack->top > 0)
// 		{
// 			if (astack->stack[astack->top] < mid)
// 				pb(astack, bstack);
// 			else if (astack->stack[astack->top - 1] < mid)
// 				sa(astack);
// 			else if (astack->stack[0] < mid)
// 				rra(astack);
// 			else
// 				ra(astack);
// 		}
// 		if (!has_less_than(astack, mid) && astack->top > 0)
// 		{
// 			while (astack->stack[astack->top] != close_to_mid(astack, mid))
// 				ra(astack);
// 			pb(astack, bstack);
// 		}
// 		mid = close_to_mid(astack, find_mid(astack));
// 	}
// }

// void	algo_b(t_num *astack, t_num *bstack)
// {
// 	while (bstack->top >= 0)
// 	{
// 		if (find_pos(bstack, find_big(bstack)) >= bstack->top / 2
// 			&& find_pos(bstack, find_big(bstack)) != bstack->top)
// 			rb(bstack);
// 		else if (find_pos(bstack, find_big(bstack)) < bstack->top / 2
// 			&& find_pos(bstack, find_big(bstack)) != bstack->top)
// 			rrb(bstack);
// 		else
// 			pa(astack, bstack);
// 		if (astack->top >= 1)
// 			if (astack->stack[astack->top] > astack->stack[astack->top - 1])
// 				sa(astack);
// 	}
// }

// void	sort_hundred(t_num *astack, t_num *bstack)
// {
// 	if (!is_sorted(astack) && astack->top <= 99)
// 	{
// 		algo_a(astack, bstack);
// 		algo_b(astack, bstack);
// 	}
// }

// void	sort_hundred(t_num *astack, t_num *bstack)
// {
// 	int	small;

// 	if (astack->top <= 9 && !is_sorted(astack))
// 	{
// 		int	i;
// 		int	mid;

// 		i = 6;
// 		mid = close_to_mid(astack, find_mid(astack));
// 		while (--i)
// 		{
// 			if (astack->stack[astack->top] <= mid)
// 				pb(astack, bstack);
// 			if (astack->stack[astack->top] > mid)
// 				ra(astack);
// 		}
// 		bstack->bottom = bstack->top + 1;
// 		astack->bottom = astack->top + 1;
// 		sort_five(astack, bstack);
// 		sort_five(bstack, astack);
// 		while (bstack->top >= 0)
// 		{
// 			while (astack->stack[astack->top] < bstack->stack[bstack->top])
// 				ra(astack);
// 			pa(astack, bstack);
// 		}
// 		small = find_small(astack);
// 		while (astack->stack[astack->top] != small)
// 			ra(astack);
// 	}
// }
