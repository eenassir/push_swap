/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:28:52 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/21 14:51:00 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list *list)
{
	int	min;

	if (!list)
		return (0);
	if (!(list->next))
		return (list->c);
	min = list->c;
	list = list->next;
	while (list)
	{
		if (list->c < min)
			min = list->c;
		list = list->next;
	}
	return (min);
}

int	get_max(t_list *lst)
{
	int	max;

	if (!lst)
		return (0);
	if (!(lst->next))
		return (lst->c);
	max = lst->c;
	lst = lst->next;
	while (lst)
	{
		if (lst->c > max)
			max = lst->c;
		lst = lst->next;
	}
	return (max);
}

void	reset_moves(t_move *mv)
{
	mv->ra = 0;
	mv->rb = 0;
	mv->rra = 0;
	mv->rrb = 0;
}

int	get_small_begger_than(t_list *lst_a, int b)
{
	int		best_val;
	int		best_index;
	t_list	*node;
	int		a_index;

	a_index = 0;
	best_index = -1;
	node = lst_a;
	while (node)
	{
		if (node->c > b)
		{
			if (best_index == -1 || node->c < best_val)
			{
				best_index = a_index;
				best_val = node->c;
			}
		}
		node = node->next;
		a_index++;
	}
	return (best_index);
}
