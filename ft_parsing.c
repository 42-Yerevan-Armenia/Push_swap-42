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

static int	ft_doubles(int num, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_atoi(av[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	alpha(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	checks(char **args)
{
	if (!alpha(*args))
		ft_error("❌ Not Digit");
	if (ft_strlen(*args) > 10)
		ft_error("❌ MAX LONG LONG Error❗️");
}

void	check_args(int ac, char **av)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		checks(&args[i]);
		if (ft_doubles(tmp, args, i))
			ft_error("❌ Doubles");
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error("❌ MAX int");
		i++;
	}
	if (ac == 2)
		ft_free(args);
}
