/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:59:46 by arakhurs          #+#    #+#             */
/*   Updated: 2022/08/22 19:59:48 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_all	*get_next_min(t_all **stack)
{
	t_all	*head;
	t_all	*min;
	int		head_min;

	min = NULL;
	head_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!head_min \
				|| head->content < min->content))
			{
				min = head;
				head_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_stack(t_all **stack)
{
	t_all	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

void	ft_fill_stack(t_all **a, int ac, char **split)
{
	t_all	*new;
	int		i;

	i = 0;
	while (split[i])
	{
		new = ft_lstnew(ft_atoi(split[i]));
		ft_lstadd_back(a, new);
		i++;
	}
	index_stack(a);
	if (ac == 2)
		ft_free(split);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}
