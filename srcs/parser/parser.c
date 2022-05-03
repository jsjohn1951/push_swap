/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:30:48 by wismith           #+#    #+#             */
/*   Updated: 2022/05/02 23:11:52 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/includes/push_swap.h"

int	mal(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (str[0] && str[0] != ' ')
		num++;
	while (str[i])
	{
		if (str[i - 1] == ' ' && str[i] != ' ')
			num++;
		i++;
	}
	return (num);
}

void	add_el(t_num *astack, t_num *bstack, char *s)
{
	t_flags		flag;
	int			i;
	static int	j;
	char		**matrix;

	i = 0;
	matrix = ft_split_mod(s, ' ');
	flag.max = 0;
	flag.min = 0;
	while (matrix[i])
	{
		astack->stack[j] = ft_atoi_mod(matrix[i], &flag);
		if (non_num(matrix[i]))
			flag.max = 1;
		free(matrix[i]);
		i++;
		j++;
	}
	free (matrix);
	if (flag.max || flag.min)
		errmsg(astack, bstack);
}

void	add_els(t_num *num, t_num *num2, char **s)
{
	int	i;

	i = 0;
	while (s[++i])
		add_el(num, num2, s[i]);
}

void	ft_int_lst_rev(t_num *stack)
{
	int		*s;
	int		*d;
	int		temp;

	s = (int *) stack->stack;
	d = stack->stack + stack->top;
	while (s < d)
	{
		temp = *s;
		*s = *d;
		*d = temp;
		s++;
		d--;
	}
}

void	parser(t_num *astack, t_num *bstack, char **argv)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (argv[++i])
		size += mal(argv[i]);
	astack->top = size - 1;
	bstack->top = -1;
	astack->bottom = 0;
	bstack->bottom = 0;
	astack->stack = (int *)ft_calloc(size, sizeof(int));
	bstack->stack = (int *)ft_calloc(size, sizeof(int));
	add_els(astack, bstack, argv);
	ft_int_lst_rev(astack);
}
