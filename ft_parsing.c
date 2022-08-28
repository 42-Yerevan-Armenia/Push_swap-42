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

int	alpha(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 1;
		if (ft_strcmp(str[i], "+") == 0 || ft_strcmp(str[i], "-") == 0)
			return (0);
		if (str[i][0] != '-' && str[i][0] != '+' &&
			!(str[i][0] >= '0' && str[i][0] <= '9'))
			return (0);
		while (str[i][j])
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	checks(char **split)
{
	if (doubles(split))
		ft_error("❌ Doubles❗️");
	if (!alpha(split))
		ft_error("❌ Not Digit❗️");
	if (ft_strlen(*split) > 10)
		ft_error("❌ MAX LONG LONG Error❗️");
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
		if (!args)
			args = ft_strdup(av[i]);
		else
		{
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
