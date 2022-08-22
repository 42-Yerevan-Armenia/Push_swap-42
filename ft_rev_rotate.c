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

static void	ft_for_rev_rotate(t_all **stk)
{
	t_all	*temp;
	t_all	*first;

	first = *stk;
	temp = *stk;
	if (stk)
	{
		while (temp -> next -> next)
			temp = temp -> next;
		temp -> next -> next = first;
		*stk = temp -> next;
		temp -> next = NULL;
	}
}

void	rra(t_all **a, int t)
{
	ft_for_rev_rotate(a);
	if (t == 1)
		ft_printf("rra\n");
}

void	rrb(t_all **b, int t)
{
	ft_for_rev_rotate(b);
	if (t == 1)
		ft_printf("rrb\n");
}

void	rrr(t_all **a, t_all **b, int t)
{
	ft_for_rev_rotate(a);
	ft_for_rev_rotate(b);
	if (t == 1)
		ft_printf("rrr\n");
}

void	ft_for_push(t_all **a, t_all **b)
{
	t_all	*i;

	i = *a;
	*a = (*a)->next;
	if (i == NULL)
		return ;
	i->next = *a;
	*a = i;
}
