/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:02:26 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/21 19:49:17 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rest(t_move *best)
{
	best->ra = 0;
	best->rb = 0;
	best->rra = 0;
	best->rrb = 0;
}

int	ft_atoi(char *s)
{
	int	i;
	int	signe;
	int	result;

	if (!s)
		return (0);
	i = 0;
	signe = 1;
	result = 0;
	while (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			signe *= -1;
		i++;
	}
	if (i > 1)
		(ft_putstr(2, "Error\n"), free(s));
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 - 48 + s[i++];
		if ((result < 0 && signe == 1)
			|| (result * -1 > 0 && signe == -1))
			(ft_putstr (2, "Error\n"), free (s));
	}
	return (signe * result);
}

void	ft_indexing(t_list *lst)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = lst;
	while (tmp1)
	{
		tmp1 -> i = 0;
		tmp2 = lst;
		while (tmp2)
		{
			if (tmp1->c > tmp2->c)
				tmp1 -> i += 1;
			tmp2 = tmp2 -> next;
		}
		tmp1 = tmp1-> next;
	}
}

char	*collectarg(char **av)
{
	int		i;
	int		j;
	int		cpt;
	char	*s;

	i = 0;
	cpt = 0;
	s = (char *)malloc(sizearg(av) + 1);
	if (!s)
		return (NULL);
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			s[cpt++] = av[i][j];
			if ((av[i][j] == '+' || av[i][j] == '-')
				&& (av[i][j + 1] == ' ' || av[i][j + 1] == '\0'))
				(ft_putstr(2, "Error\n"), free (s));
			j++;
		}
		if (av[i] != NULL)
			s[cpt++] = ' ';
	}
	return (s);
}
