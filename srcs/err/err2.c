/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 23:08:03 by wismith           #+#    #+#             */
/*   Updated: 2022/05/09 14:50:36 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/push_swap.h"

int	flagged(char **argv, int i, int j, int flag)
{
	if ((argv[i][j] == '-'
		&& (argv[i][j + 1] < '0' || argv[i][j + 1] > '9'))
		|| ((argv[i][j] >= '0' && argv[i][j] <= '9')
		&& argv[i][j + 1] == '-'))
		flag = 1;
	if ((argv[i][j] == '+'
		&& (argv[i][j + 1] < '0' || argv[i][j + 1] > '9'))
		|| ((argv[i][j] >= '0' && argv[i][j] <= '9')
		&& argv[i][j + 1] == '+'))
		flag = 1;
	return (flag);
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
			flag = flagged(argv, i, j, flag);
	}
	if (flag)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

int	non_num(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!(s[i] >= '0' && s[i] <= '9') && s[i] != '-' && s[i] != '+')
			return (1);
	return (0);
}
