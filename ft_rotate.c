/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 16:02:16 by arakhurs          #+#    #+#             */
/*   Updated: 2022/08/19 16:02:18 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// queue top of stack - shift remaining values up the stack
static void	rot_stk_top_to_botm(t_val *stk, size_t top)
{
	t_val	upper;

	upper = stk[top];
	while (top > 0)
	{
		stk[top] = stk[top - 1];
		top--;
	}
	stk[0] = upper;
}

void	ra(t_all *all)
{
	if (all->a.load >= 2)
		rot_stk_top_to_botm(all->a.stk, TOP_A);
}

void	rb(t_all *all)
{
	if (all->b.load >= 2)
		rot_stk_top_to_botm(all->b.stk, TOP_B);
}

void	rr(t_all *all)
{
	ra(all);
	rb(all);
}

void	ft_swap(t_val *a, t_val *b)
{
	t_val	i;

	i = *a;
	*a = *b;
	*b = i;
}
