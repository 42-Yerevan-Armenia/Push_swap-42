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

int	alpha(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 1;//check for - and + in front of number
		if (ft_strcmp(str[i], "-") == 0 || ft_strcmp(str[i], "+") == 0)
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

int	doubles(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{//check av[i] for all av cycling with av[j]
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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
		if (!args)//for first
			args = ft_strdup(av[i]);
		else
		{//join " " then av[i]
			args = ft_strjoin(args, " ");
			args = ft_strjoin(args, av[i]);
		}
	}//split all " "es
	split = ft_split(args, ' ');
	free(args);//free memory
	i = -1;
	while (split[++i])//check errors
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
	{//put in lists splited av
		new = ft_lstnew(ft_atoi(split[i]));
		ft_lstadd_back(a, new);
		i++;
	}
	if (ac == 2)
		ft_free(split);
}
