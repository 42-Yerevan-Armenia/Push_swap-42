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

void	sa(t_all **a, int t)
{
	ft_for_swap(a);
	if (t == 1)
		ft_printf("sa\n");
}

void	sb(t_all **b, int t)
{
	ft_for_swap(b);
	if (t == 1)
		ft_printf("sb\n");
}

void	ss(t_all **a, t_all **b, int t)
{
	ft_for_swap(a);
	ft_for_swap(b);
	if (t == 1)
		ft_printf("ss\n");
}

void	pa(t_all **a, t_all **b, int t)
{
	if (b == NULL)
		return ;
	ft_for_push(b, a);
	if (t == 1)
		ft_printf("pa\n");
}

void	pb(t_all **a, t_all **b, int t)
{
	if (a == NULL)
		return ;
	ft_for_push(a, b);
	if (t == 1)
		ft_printf("pb\n");
}
