/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakhurs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:29:30 by arakhurs          #+#    #+#             */
/*   Updated: 2022/09/02 19:29:32 by arakhurs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	iszero(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] && (s[i] == '-' || s[i] == '+'))
		i++;
	while (s[i])
	{
		if (s[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

static char	*one_zero_str(char *s)
{
	s[0] = '0';
	s[1] = '\0';
	return (s);
}

static int	numlen(char *s)
{
	int	i;
	int	len;

	if (!s)
		return (0);
	if (iszero(s))
		return (1);
	i = 0;
	len = 0;
	if (s[i] && s[i] == '+')
		i++;
	else if (s[i] && s[i] == '-')
	{
		len++;
		i++;
	}
	while (s[i] == '0')
		i++;
	while (s[i++])
		len++;
	return (len);
}

static char	*numstr(char *str)
{
	char	*s;
	int		i;
	int		j;

	s = malloc(numlen(str) + 1);
	if (!s)
		return (NULL);
	if (iszero(str))
		return (one_zero_str(s));
	i = 0;
	j = 0;
	if (str[i] && str[i] == '+')
		i++;
	else if (str[i] && str[i] == '-')
	{
		s[j++] = '-';
		i++;
	}
	while (str[i] == '0')
		i++;
	while (str[i])
		s[j++] = str[i++];
	s[j] = '\0';
	return (s);
}

char	**checks(char **split)
{
	int		i;
	char	*s1;
	char	*s2;

	while_1(split);
	i = -1;
	while (split[++i])
	{	
		s1 = numstr(split[i]);
		s2 = ft_itoa(ft_atoi(split[i]));
		if (ft_strcmp(s1, s2))
		{
			free(s1);
			free(s2);
			ft_free_1(split);
			return (NULL);
		}
		free(s1);
		free(s2);
	}
	return (split);
}
