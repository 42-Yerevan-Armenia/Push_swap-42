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

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

static int	doubles(char **av, int i)//Repair it
{
	int	n;

	i++;
	while (av[i])
	{
		n = ft_atoi(av[i]);
		if (ft_atoi(av[i]) == n)
			return (1);
		i++;
	}
	return (0);
}

int	alpha(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	checks(char **args, int i)
{
//	if (doubles(args, i))
//		ft_error("❌ Doubles❗️");
	if (!alpha(*args))
		ft_error("❌ Not Digit❗️");
	if (ft_strlen(*args) > 10)
		ft_error("❌ MAX LONG LONG Error❗️");
}

char	**check_args(int ac, char **av)
{
	int		i;
	int		n;
	char	*args;
	char	**split;

	i = 1;
	while (av[i])
	{
		if (!args)
			args = ft_strdup(av[i]);
		else
		{
			args = ft_strjoin(args, " ");
			args = ft_strjoin(args, av[i]);
		}
		i++;
	}
	i = -1;
	split = ft_split(args, ' ');
	while (split[++i])
		checks(&split[i], i);
	free(args);
	while (split[i])
	{
		n = ft_atoi(split[i]);
		i++;
	}
	return (split);
}
