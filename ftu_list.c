/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftu_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:59:46 by arakhurs          #+#    #+#             */
/*   Updated: 2022/08/22 19:59:48 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all	*ft_lstnew(int content)
{
	t_all	*head;

	head = (t_all *)malloc(sizeof(t_all));
	if (head == NULL)
		return (0);
	head->content = content;
	head->next = NULL;
	return (head);
}

t_all	*ft_lstlast(t_all *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_all	*ft_lstadd_back(t_all *lst, t_all *new)
{
	t_all	*current;

	if (!lst)
	{
		lst = new;
		return (lst);
	}
	current = ft_lstlast(lst);
	current->next = new;
	return (lst);
}

int	ft_lstsize(t_all *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

//void	list()

t_all	*fill_stack_a(int ac, char **av)
{
	t_all	*a;
	t_all	*new;
	int		i;
	int		j;
	int		found;

	i = 1;
	a = 0;
	new = 0;
	while (i < ac)
	{
		j = 0;
		found = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ' && found == 0)
			{
				new = ft_lstnew(ft_atoi(&av[i][j]));
				a = ft_lstadd_back(a, new);
				found = 1;
			}
			else if (av[i][j] == ' ' )
				found = 0;
			j++;
		}
		i++;
	}
	return (a);
}
