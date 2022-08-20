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

int	check(char *str)
{
	char		**array;
	int			i;
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

int	main(int ac, char **av)
{
	t_all	**a;
	t_all	**b;
	char	 **split;

	if (ac < 2)
		ft_error("❌ No Valid Argument❗️ \n➡️ ./push_swap 1 2 ...");
	split = join_and_split(av);
	a = (t_all **)malloc(sizeof(t_all *));
	b = (t_all **)malloc(sizeof(t_all *));
	*a = NULL;
	*b = NULL;

	//ALGORITM

	while (*split)
		printf("%s\n", *split++);
	return (0);
}
