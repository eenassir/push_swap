/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 14:17:43 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/21 14:50:34 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	calculate_cost(t_move mv)
{
	return (ft_max(mv.ra, mv.rb) + ft_max(mv.rra, mv.rrb));
}

int	ft_get_index_min(t_list *lst)
{
	int	min;
	int	index_min;
	int	index_cur;

	if (!lst || !(lst->next))
		return (0);
	index_min = 0;
	index_cur = 1;
	min = lst->c;
	lst = lst->next;
	while (lst)
	{
		if (lst->c < min)
		{
			min = lst->c;
			index_min = index_cur;
		}
		lst = lst->next;
		index_cur++;
	}
	return (index_min);
}

void	fix_stack_a(t_list **lst_a)
{
	int	index_min;

	index_min = ft_get_index_min(*lst_a);
	if (index_min < ft_lstsize(*lst_a) / 2)
	{
		while (index_min > 0)
		{
			ra(lst_a, 1);
			index_min--;
		}
	}
	else
	{
		index_min = ft_lstsize(*lst_a) - index_min;
		while (index_min > 0)
		{
			rra(lst_a, 1);
			index_min--;
		}
	}
}
