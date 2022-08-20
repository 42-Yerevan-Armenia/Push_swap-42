/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:02:24 by arakhurs          #+#    #+#             */
/*   Updated: 2022/08/19 16:02:26 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//push bottom up the top of the stack - shift remaining values down the stack
static void	rot_stk_botm_to_top(t_val *stk, size_t top)
{
	t_val	botm;
	size_t	i;

	botm = stk[0];
	i = 0;
	while (i < top)
	{
		stk[i] = stk[i + 1];
		i++;
	}
	stk[top] = botm;
}

void	rra(t_all *all)
{
	if (all->a.load >= 2)
		rot_stk_botm_to_top(all->a.stk, TOP_A);
}

void	rrb(t_all *all)
{
	if (all->b.load >= 2)
		rot_stk_botm_to_top(all->b.stk, TOP_B);
}

void	rrr(t_all *all)
{
	rra(all);
	rrb(all);
}
