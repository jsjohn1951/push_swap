/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 18:13:57 by wismith           #+#    #+#             */
/*   Updated: 2022/04/24 18:44:39 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/push_swap.h"

int	ft_atoi_mod(const char *nptr, t_flags *flag)
{
	size_t	res;
	int		i;
	int		ncounter;

	res = 0;
	i = 0;
	ncounter = 0;
	while ((nptr[i] >= 7 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			ncounter++;
	while (nptr[i] && (nptr[i] >= 48 && nptr[i] <= 57))
	{
		res *= 10;
		res += nptr[i++] - '0';
	}
	if (res >= INT_MAX && ncounter == 0)
		flag->max = 1;
	if ((long)((res * -1) + 1) <= INT_MIN)
		flag->min = 1;
	if (ncounter > 0)
		res *= -1;
	return (res);
}
