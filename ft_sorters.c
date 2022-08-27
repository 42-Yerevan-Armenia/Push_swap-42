/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:30:39 by arakhurs          #+#    #+#             */
/*   Updated: 2022/08/10 20:30:42 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	index_of_min(t_all *a)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	index = 0;
	min = a->content;
	while (a)
	{
		if (a->content < min)
		{
			min = a->content;
			index = i;
		}
		i++;
		a = a->next;
	}
	return (index);
}

void	sort_3(t_all **a)
{//if 1 2 0 -> 1<2
	if ((*a)->content < (*a)->next->content)
	{
		rra(a, 1);//0 1 2
		if (is_sorted(a) == 0)
			sa(a, 1);
	}//if 2 1 3 -> 2 > 1 || 2 1 0 -> 2 > 0
	else if ((*a)->content > (*a)->next->content)
	{//if 2 1 3 -> 2 < 3 || 2 1 0 -> 2 < 0
		if ((*a)->content < (*a)->next->next->content)
			sa(a, 1);// 1 2 3
		else
		{
			ra(a, 1);//1 0 2
			if (!is_sorted(a))
				sa(a, 1);//0 1 2
		}
	}
}

void	sort_4(t_all **a, t_all **b)
{
	int	i;
//search min index in array of av
	i = index_of_min(*a);
	if (i == 1)//1 0 2 3
		sa(a, 1);//0 1 2 3
	else if (i == 2)//3 2 0 1
	{
		rra(a, 1);//2 0 1 3
		rra(a, 1);//0 1 2 3
	}
	else if (i == 3)//1 2 3 0 || 3 2 1 0
		rra(a, 1);//0 1 2 3
	if (is_sorted(a))
		return ;
	pb(a, b);//2 1 0 --> 3
	sort_3(a);//0 1 2
	pa(a, b);//0 1 2 3
}

void	sort_5(t_all **a, t_all **b)
{
	int	i;

	i = index_of_min(*a);
	if (i == 1)//1 0 2 3 4
		sa(a, 1);//0 1 2 3 4
	else if (i == 2)//3 4 0 1 2 
	{
		ra(a, 1);//4 0 1 2 3
		ra(a, 1);//0 1 2 3 4
	}
	else if (i == 3)//2 3 4 0 1
	{
		rra(a, 1);//1 2 3 4 0
		rra(a, 1);//0 1 2 3 4
	}
	else if (i == 4)//1 2 3 4 0
		rra(a, 1);//0 1 2 3 4
	if (is_sorted(a))
		return ;
	pb(a, b);//3 2 1 0 --> 4
	sort_4(a, b);//0 1 2 3
	pa(a, b);//0 1 2 3 4
}

void	simple_sort(t_all **a, t_all **b)
{
	int	size;

	if (is_sorted(a) || ft_lstsize(*a) == 0
		|| ft_lstsize(*a) == 1)
		return ;
	size = ft_lstsize(*a);
	if (size == 2)
		sa(a, 1);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
}
