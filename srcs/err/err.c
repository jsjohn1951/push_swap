/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:43:35 by wismith           #+#    #+#             */
/*   Updated: 2022/04/24 18:06:33 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/push_swap.h"

int	errmsg(t_num *astack, t_num *bstack)
{
	ft_putstr_fd("Error\n", 2);
	free(astack->stack);
	free(bstack->stack);
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

void	unidentifiedchar(char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
	while (argv[++i])
	{
		j = -1;
		if (!ft_strlen(argv[i]) || !emptycheck(argv[i]))
			flag = 1;
		while (argv[i][++j])
		{
			if ((argv[i][j] == '-'
				&& (argv[i][j + 1] < '0' || argv[i][j + 1] > '9'))
				|| ((argv[i][j] >= '0' && argv[i][j] <= '9')
				&& argv[i][j + 1] == '-'))
				flag = 1;
		}
	}
	if (flag)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}
