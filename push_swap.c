/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:30:39 by arakhurs          #+#    #+#             */
/*   Updated: 2022/08/28 16:51:48 by arakhurs         ###   ########.fr       */
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
	t_all	*head;
	t_all	*tmp;

	tmp = *stk;
	while (tmp)
	{
		head = tmp;
		tmp = tmp->next;
		free(head);
	}
	free(stk);
}

int	is_sorted(t_all **a)
{
	t_all	*head;

	head = *a;
	while (head && head->next)//if node and next exist
	{//check if node_1 > node_2, node_2 > node_3 ... till end
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

static void	sort_stack(t_all **a, t_all **b)
{
	if (ft_lstsize(*a) <= 5)
		simple_sort(a, b);//sorter till 5 av
	else
		radix_sort(a, b);
}

int	main(int ac, char **av)
{
	t_all	**a;
	t_all	**b;
	char	**split;

	if (ac < 2)
		return (-1);
	split = check_args(ac, av);
	a = (t_all **)malloc(sizeof(t_all *));//new space
	b = (t_all **)malloc(sizeof(t_all *));//new space
	*a = NULL;
	*b = NULL;
	ft_fill_stack(a, ac, split);
	if (is_sorted(a))//check if stack A is sorted
	{
		ft_free_stack(a);
		ft_free_stack(b);
		return (0);//Exit
	}
	sort_stack(a, b);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}
