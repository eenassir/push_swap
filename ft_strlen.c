/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:13:20 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/21 23:31:54 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	chekarg(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		if (ft_strlen(av[i]) == 0)
			(ft_putstr(2, "Error\n"));
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ' && av[i][j] != '-' && av[i][j] != '+'
				&& !(av[i][j] >= '0' && av[i][j] <= '9'))
				(ft_putstr(2, "Error\n"));
			j++;
		}
		i++;
	}
}

void	cheek_spaces(char **av)
{
	int	l;
	int	j;
	int	i;

	l = 0;
	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (av[i][j] == ' ')
				l++;
		}
		if (l == ft_strlen(av[i]))
			(ft_putstr(2, "Error\n"));
	}
}

int	sizearg(char **av)
{
	int	i;
	int	l;

	i = 0;
	l = 0;
	cheek_spaces(av);
	while (av[++i])
	{
		l += ft_strlen(av[i]);
		if (av[i + 1] != NULL)
			l += 1;
	}
	return (l);
}
