/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:30:39 by arakhurs          #+#    #+#             */
/*   Updated: 2022/08/10 20:30:42 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *str)
{
	if (str && *str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}
}

void	ft_free_stack(t_all **stk)
{
	t_all	*front;
	t_all	*tmp;

	tmp = *stk;
	while (tmp)
	{
		front = tmp;
		tmp = tmp->next;
		free(front);
	}
	free(stk);
}

int	is_sorted(t_all **a)
{
	t_all	*head;

	head = *a;
	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

static void	sort_stack(t_all **a, t_all **b)
{
	if (ft_lstsize(*a) <= 5)
		simple_sort(a, b);
	else
		radix_sort(a, b);
}

int	main(int ac, char **av)
{
	t_all	**a;
	t_all	**b;

	if (ac < 2)
		return (-1);
	check_args(ac, av);
	a = (t_all **)malloc(sizeof(t_all *));
	b = (t_all **)malloc(sizeof(t_all *));
	*a = NULL;
	*b = NULL;
	ft_fill_stack(a, ac, av);
	if (is_sorted(a))
	{
		ft_free_stack(a);
		ft_free_stack(b);
		return (0);
	}
	sort_stack(a, b);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}
