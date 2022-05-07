/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:23:19 by wismith           #+#    #+#             */
/*   Updated: 2022/05/07 20:24:00 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../assets/includes/push_swap.h"

void	push_swap(t_num *astack, t_num *bstack)
{
	sort_two(astack);
	sort_three(astack);
	sort_five(astack, bstack);
	sort(astack, bstack);
	// ft_printf("\n%s", KRED);
	// printer(astack, bstack, astack->top, bstack->top);
	// ft_printf("%s", KNRM);
	// if (is_sorted(astack))
	// 	ft_printf("\n\t%sis_sorted (astack) : true%s\n", KGRN, KNRM);
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
