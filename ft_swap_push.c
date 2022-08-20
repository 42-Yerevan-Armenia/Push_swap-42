/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:43:11 by arakhurs          #+#    #+#             */
/*   Updated: 2022/08/19 15:43:13 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_all *all)// swap top of stack a
{
	if (all->a.load >= 2)
		ft_swap(&all->a.stk[TOP_A], &all->a.stk[TOP_A - 1]);
}

void	sb(t_all *all)// swap top of stack b
{
	if (all->b.load >= 2)
		ft_swap(&all->b.stk[TOP_B], &all->b.stk[TOP_B - 1]);
}

void	ss(t_all *all)// swap both stacks tops
{
	sa(all);
	sb(all);
}

void	pa(t_all *all)// push top of b to a
{
	if (!all->b.load)
		return ;
	all->a.load++;
	all->a.stk[TOP_A] = all->b.stk[TOP_B];
	all->b.load--;
}

void	pb(t_all *all)// push a summit on top of b
{
	if (!all->a.load)
		return ;
	all->b.load++;
	all->b.stk[TOP_B] = all->a.stk[TOP_A];
	all->a.load--;
}
