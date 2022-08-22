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

int	check(char *str)
{
	char			**array;
	int				i;
	long long int	num;

	i = 0;
	array = ft_split(str, ' ');
	while (array[i])
	{
		num = ft_atoi(array[i]);
		if (!alpha(array[i]) || !doubles(array, array[i], i) || !min_max(num))
			ft_error("❌ Atoi Error❗️");
		i++;
	}
	return (1);
}

char	**join_and_split(char **av)
{
	int		i;
	char	*args;
	char	**split;

	i = 1;
	args = NULL;
	while (av[i])
	{
		if (!args)
			args = ft_strdup(av[i++]);
		else
		{
			args = ft_strjoin(args, " ");
			args = ft_strjoin(args, av[i]);
			i++;
		}
	}
	if (ft_strlen(args) > 10)
		ft_error("❌ MAX LONG LONG Error❗️");
	if (check(args) == 1)
	{
		split = ft_split(args, ' ');
		free(args);
		return (split);
	}
	return (0);
}
