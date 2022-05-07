/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:20:20 by wismith           #+#    #+#             */
/*   Updated: 2022/05/07 17:57:00 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# define KCLR  "\e[1;1H\e[2J"

# include <stdlib.h>
# include <limits.h>
# include "../libft/include/ft_printf.h"
# include "../libft/include/libft.h"

typedef struct s_spooky
{
	int	*ghosted;
}	t_ghost;

typedef struct s_flags
{
	int	max;
	int	min;
}	t_flags;

typedef struct s_num
{
	int	*stack;
	int	top;
	int	bottom;
	int	small;
}	t_num;

// Parser
void	parser(t_num *astack, t_num *bstack, char **argv);

// Errors
void	unidentifiedchar(char **argv);
void	check_num_arg(int argc);
void	duplicatecheck(t_num *astack, t_num *bstack, int size);
int		non_num(char *s);
int		errmsg(t_num *astack, t_num *bstack);
int		emptycheck(char *s);

// Op
void	sa(t_num *astack);
void	sb(t_num *bstack);
void	ss(t_num *astack, t_num *bstack);
void	pa(t_num *astack, t_num *bstack);
void	pb(t_num *astack, t_num *bstack);
void	ra(t_num *astack);
void	rra(t_num *astack);
void	rb(t_num *bstack);
void	rrb(t_num *bstack);

// algo
void	sort_three(t_num *astack, t_num *bstack);
void	sort_five(t_num *astack, t_num *bstack);
void	sort_ten(t_num *astack, t_num *bstack);
void	sort(t_num *astack, t_num *bstack);
void	set_ghosted(t_num *astack, t_ghost *ghost);

// remainder
void	astack_rem(t_num *astack, t_num *bstack);
void	bstack_rem(t_num *astack, t_num *bstack);
void	sort_five_bstack_rem(t_num *astack, t_num *bstack);

// tools
int		find_small(t_num *stack);
int		find_big(t_num *stack);
int		find_pos(t_num *stack, int small);
int		is_sorted(t_num *stack);
int		ft_atoi_mod(const char *nptr, t_flags *flag);
int		has_less_than(t_num *stack, int num);
int		has_greater_than(t_num *stack, int num);
int		nearest_small(t_num *stack, int min);
int		nearest_max(t_num *stack, int max);
int		rtn_index(int top, int i, int index);

#endif
