/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:52:33 by wismith           #+#    #+#             */
/*   Updated: 2022/04/20 15:50:21 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../assets/includes/push_swap.h"

void	printer(t_num *num1, t_num *num2, int size1, int size2)
{
	int	i;
	int	j;

	i = size1;
	j = size2;
	while (i >= 0 || j >= 0)
	{
		if (i < j)
		{
			ft_printf("\t%d\n", num2->stack[j]);
			j--;
		}
		else if (i > j)
		{
			ft_printf("%d\n", num1->stack[i]);
			i--;
		}
		else if (i == j)
		{
			ft_printf("%d\t%d\n", num1->stack[i], num2->stack[j]);
			i--;
			j--;
		}
	}
	ft_printf("-\t-\nA\tB\n");
}
