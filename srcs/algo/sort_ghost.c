/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ghost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 19:19:35 by wismith           #+#    #+#             */
/*   Updated: 2022/04/30 20:14:43 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/push_swap.h"

int	ghost_is_sorted(t_ghost *ghost, int len)
{
	int	i;

	if (len == -1)
		return (1);
	i = len - 1;
	while (i >= 0)
	{
		if (ghost->ghosted[i] < ghost->ghosted[i + 1])
			return (0);
		i--;
	}
	return (1);
}

void	sort_ghosted(t_ghost *ghost, int len)
{
	int	temp;
	int	i;
	int	j;

	j = len;
	while (j >= 0)
	{
		i = len;
		while (i > 0)
		{
			if (ghost->ghosted[i] > ghost->ghosted[i - 1])
			{
				temp = ghost->ghosted[i];
				ghost->ghosted[i] = ghost->ghosted[i - 1];
				ghost->ghosted[i - 1] = temp;
			}
			i--;
		}
		j--;
	}
}

void	set_ghosted(t_num *astack, t_ghost *ghost)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i <= astack->top)
		ghost->ghosted[++j] = astack->stack[i];
	sort_ghosted(ghost, astack->top);
}
