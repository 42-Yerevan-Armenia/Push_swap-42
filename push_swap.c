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

void	ft_free_stack(t_all **stk)
{
	t_all	*front;
	t_all	*tmp;

	tmp = *stk;
	while (tmp)
	{
		front = tmp;
		tmp = tmp -> next;
		free(front);
	}
	free(stk);
}

int	main(int ac, char **av)
{
	t_all	**a;
	t_all	*fill;
	char	**split;

	if (ac < 2)
		ft_error("❌ No Valid Argument❗️ \n➡️ ./push_swap 1 2 ...");
	split = join_and_split(av);
	a = (t_all **)malloc(sizeof(t_all *));
	*a = NULL;
	fill = fill_stack_a(ac, av);
	while (fill)
	{
		ft_printf("%d\n", fill->content);
		fill = fill->next;
	}
	return (0);
}
