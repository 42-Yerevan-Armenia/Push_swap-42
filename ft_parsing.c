/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:27:07 by arakhurs          #+#    #+#             */
/*   Updated: 2022/08/22 16:27:08 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	doubles(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_free_1(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
	ft_error("❌ Error");
}

void	while_1(char **split)
{
	int	i;

	i = 0;
	while (split[++i])
		if (ft_strlen(split[i]) == 1 && (split[i][0] == '+' || split[i][0] == '-'))
			ft_free_1(split);
	if (doubles(split))
		ft_error("❌ Error");
}

char	**check_args(int ac, char **av)
{
	int		i;
	int		n;
	char	*args;
	char	**split;

	i = 0;
	while (av[++i])
	{
		if (!args)//for first av
			args = ft_strdup(av[i]);
		else
		{//join ospace and next av
			args = ft_strjoin(args, " ");
			args = ft_strjoin(args, av[i]);
		}
	}
	split = ft_split(args, ' ');
	free(args);
	i = -1;
	while (split[++i])
		checks(split);
	i = -1;
	while (split[++i])
		ft_atoi(split[i]);
	return (split);
}

void	ft_fill_stack(t_all **a, int ac, char **split)
{
	t_all	*new;
	int		i;

	i = 0;
	while (split[i])
	{//each av add to list
		new = ft_lstnew(ft_atoi(split[i]));
		ft_lstadd_back(a, new);
		i++;
	}
	if (ac == 2)
		ft_free(split);
}

