/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:43:35 by wismith           #+#    #+#             */
/*   Updated: 2022/05/02 23:15:39 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/push_swap.h"

int	errmsg(t_num *astack, t_num *bstack)
{
	write(2, "Error\n", 6);
	free(astack->stack);
	astack->stack = NULL;
	free(bstack->stack);
	bstack->stack = NULL;
	exit (1);
}

void	check_num_arg(int argc)
{
	if (argc < 2)
		exit(0);
}

void	duplicatecheck(t_num *astack, t_num *bstack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i <= size)
	{
		j = i + 1;
		while (j <= size)
		{
			if (astack->stack[j] == astack->stack[i])
				errmsg(astack, bstack);
			j++;
		}
		i++;
	}
}

int	emptycheck(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] >= '0' && s[i] <= '9')
			return (1);
	return (0);
}
