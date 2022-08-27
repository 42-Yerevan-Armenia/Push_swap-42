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

static void	ft_for_rotate(t_all **stk)
{
	t_all	*i;

	i = (*stk);
	if (stk)
	{
		ft_lstlast(*stk)->next = i;
		*stk = (*stk)->next;
		i->next = NULL;
	}
}

void	ra(t_all **a, int t)
{
	ft_for_rotate(a);
	if (t == 1)
		ft_printf("ra\n");
}

void	rb(t_all **b, int t)
{
	ft_for_rotate(b);
	if (t == 1)
		ft_printf("rb\n");
}

void	rr(t_all **a, t_all **b, int t)
{
	ft_for_rotate(a);
	ft_for_rotate(b);
	if (t == 1)
		ft_printf("rr\n");
}

void	ft_for_swap(t_all **stack)
{
	int	i;

	if (stack)
	{
		i = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = i;
	}
}
