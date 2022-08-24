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

int	pa(t_all **a, t_all **b)
{
	if (push(a, b) == -1)
		return (-1);
	ft_printf("pa\n");
	return (0);
}

int	pb(t_all **a, t_all **b)
{
	if (push(b, a) == -1)
		return (-1);
	ft_printf("pb\n");
	return (0);
}
