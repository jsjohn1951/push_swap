/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:30:27 by wismith           #+#    #+#             */
/*   Updated: 2022/04/23 21:36:57 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/push_swap.h"

void	rb(t_num *bstack)
{
	int	tmp;
	int	i;

	if (bstack->top > 0)
	{
		i = bstack->top;
		tmp = bstack->stack[i];
		while (i > 0)
		{
			bstack->stack[i] = bstack->stack[i - 1];
			i--;
		}
		bstack->stack[i] = tmp;
		ft_putstr("rb\n");
	}
}

void	rrb(t_num *bstack)
{
	int	tmp;
	int	i;

	if (bstack-> top > 0)
	{
		i = 0;
		tmp = bstack->stack[0];
		while (i < bstack->top)
		{
			bstack->stack[i] = bstack->stack[i + 1];
			i++;
		}
		bstack->stack[i] = tmp;
		ft_putstr("rrb\n");
	}
}
