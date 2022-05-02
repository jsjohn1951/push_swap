/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:23:19 by wismith           #+#    #+#             */
/*   Updated: 2022/05/02 18:09:04 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../assets/includes/push_swap.h"

void	push_swap(t_num *astack, t_num *bstack)
{
	sort_three(astack, bstack);
	sort_five(astack, bstack);
	sort(astack, bstack);
	// ft_printf("\n");
	// printer(astack, bstack, astack->top, bstack->top);
	// if (is_sorted(astack))
	// 	ft_printf("\t%sis sorted\n%s", KGRN, KNRM);
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
