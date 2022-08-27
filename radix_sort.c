/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:30:39 by arakhurs          #+#    #+#             */
/*   Updated: 2022/08/10 20:30:42 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lenght_of_max(t_all **a)
{
	int	max;
	int	i;
	int	tmp;

	i = 1;
	tmp = 2;
	max = ft_lstsize(*a) - 1;
	while (tmp <= max)
	{
		tmp *= 2;
		i++;
	}
	return (i);
}

t_all	*next_min(t_all *a)
{
	int		head;
	t_all	*node;
	t_all	*min_node;

	min_node = NULL;
	head = 0;
	node = a;
	while (node)
	{//if not exist
		if (node->index == -1 && (head == 0
				|| node->content < min_node->content))
		{
			head = 1;
			min_node = node;
		}
		node = node->next;
	}
	return (min_node);
}

void	indexing(t_all **a)
{
	t_all	*top;
	int		index;

	index = 0;
	top = next_min(*a);
	while (top)
	{
		top -> index = index;
		index++;
		top = next_min(*a);
	}
}

void	radix_sort(t_all **a, t_all **b)
{
	int		i;
	int		size;
	int		j;
	int		max_index_lenght;

	i = 0;
	size = ft_lstsize(*a);
	indexing(a);
	max_index_lenght = lenght_of_max(a);
	while (i < max_index_lenght)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a, 1);
			else
				pb(a, b);
			j++;
		}
		while (ft_lstsize(*b))
			pa(a, b);
		i++;
	}
}
