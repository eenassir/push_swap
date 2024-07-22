/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_3_4_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 12:02:10 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/22 18:20:13 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three(t_list **lst)
{
	int	a;
	int	b;
	int	c;

	a = (*lst)->i;
	b = (*lst)->next->i;
	c = (*lst)->next->next->i;
	if (a > b && b > c && a > c)
		(sa((*lst)), rra(lst, 1));
	else if (a < b && b > c && a < c)
		(rra(lst, 1), sa(*lst));
	else if (a < b && b > c && a > c)
		rra(lst, 1);
	else if (a > b && b < c && a < c)
		sa(*lst);
	else if (a > b && b < c && a > c)
		ra(lst, 1);
}

void	four(t_list **lst_a, t_list **lst_b)
{
	while ((*lst_a)->i != 0)
		rra(lst_a, 1);
	pb(lst_b, lst_a);
	three (lst_a);
	pa(lst_a, lst_b);
}

void	five(t_list **lst_a, t_list **lst_b)
{
	if ((*lst_a)->i == 0)
		pb(lst_b, lst_a);
	else if ((*lst_a)->next->i == 0)
		(ra(lst_a, 1), pb(lst_b, lst_a));
	else if ((*lst_a)->next->next->i == 0)
		(ra(lst_a, 1), ra(lst_a, 1), pb(lst_b, lst_a));
	else if ((*lst_a)->next->next->next->i == 0)
		(rra(lst_a, 1), rra(lst_a, 1), pb(lst_b, lst_a));
	else if ((*lst_a)->next->next->next->next->i == 0)
		(rra(lst_a, 1), pb(lst_b, lst_a));
	four(lst_a, lst_b);
	pa(lst_a, lst_b);
}
