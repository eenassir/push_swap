/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:13:20 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/22 20:38:41 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

void	cheek_spaces(char **av)
{
	int	l;
	int	j;
	int	i;

	l = 0;
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j] == ' ' && av[i][j])
			j++;
		if (!av[i][j])
			(ft_putstr(2, "Error\n"), exit(1));
		i++;
	}
}

void	chekarg(char **av)
{
	int	i;
	int	j;

	i = 1;
	cheek_spaces(av);
	while (av[i])
	{
		if (ft_strlen(av[i]) == 0)
			(ft_putstr(2, "Error\n"), exit(1));
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ' && av[i][j] != '-' && av[i][j] != '+'
				&& !(av[i][j] >= '0' && av[i][j] <= '9'))
				(ft_putstr(2, "Error\n"), exit(1));
			j++;
		}
		i++;
	}
}
