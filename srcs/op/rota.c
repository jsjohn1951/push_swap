/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rota.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:01:07 by wismith           #+#    #+#             */
/*   Updated: 2022/04/23 18:35:18 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/push_swap.h"

void	ra(t_num *astack)
{
	int	tmp;
	int	i;

	if (astack->top > 0)
	{
		i = astack->top;
		tmp = astack->stack[i];
		while (i > 0)
		{
			astack->stack[i] = astack->stack[i - 1];
			i--;
		}
		astack->stack[i] = tmp;
		ft_putstr("ra\n");
	}
}

void	rra(t_num *astack)
{
	int	tmp;
	int	i;

	if (astack-> top > 0)
	{
		i = 0;
		tmp = astack->stack[0];
		while (i < astack->top)
		{
			astack->stack[i] = astack->stack[i + 1];
			i++;
		}
		astack->stack[i] = tmp;
		ft_putstr("rra\n");
	}
}
