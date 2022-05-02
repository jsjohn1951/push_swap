/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:23:19 by wismith           #+#    #+#             */
/*   Updated: 2022/05/02 16:26:35 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../assets/includes/push_swap.h"

void	push_swap(t_num *astack, t_num *bstack)
{
	while (!is_sorted(astack) && astack->top <= 4)
	{
		sort_three(astack, bstack);
		sort_five(astack, bstack);
	}
	sort_hundred(astack, bstack);
}

int	main(int argc, char **argv)
{
	t_num	astack;
	t_num	bstack;

	check_num_arg(argc);
	unidentifiedchar(argv);
	parser(&astack, &bstack, argv);
	duplicatecheck(&astack, &bstack, astack.top);
	push_swap(&astack, &bstack);
	free(astack.stack);
	free(bstack.stack);
	return (0);
}
