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
		tmp = tmp -> next;
		free(front);
	}
	free(stk);
}

int	is_sorted(t_all *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_all	**a;
	t_all	**b;
	t_all	*fill;

	if (ac < 2)
		return (-1);
	check_args(ac, av);
	a = (t_all **)malloc(sizeof(t_all *));
	b = (t_all **)malloc(sizeof(t_all *));
	*a = NULL;
	*b = NULL;
	fill = fill_stack_a(ac, av, a);
	if (is_sorted(*a))
	{
		return (0);
	}
	//ft_printf("%d\n", __LINE__);
	while (fill)
	{
		ft_printf("%d\n", fill->content);
		fill = fill->next;
	}
	return (0);
}
