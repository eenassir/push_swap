/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:47:15 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/21 14:51:35 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moves_copy(t_move from, t_move *to)
{
	to->ra = from.ra;
	to->rra = from.rra;
	to->rb = from.rb;
	to->rrb = from.rrb;
}

void	calculate_best_moves(t_move *best, t_list *lst_a, t_list *lst_b)
{
	t_move	temp;
	t_list	*node;
	int		a_index;
	int		b_index;

	b_index = 0;
	node = lst_b;
	while (node)
	{
		reset_moves(&temp);
		a_index = get_small_begger_than(lst_a, node->c);
		if (a_index < ft_lstsize(lst_a) / 2)
			temp.ra = a_index;
		else
			temp.rra = ft_lstsize(lst_a) - a_index;
		if (b_index < ft_lstsize(lst_b) / 2)
			temp.rb = b_index;
		else
			temp.rrb = ft_lstsize(lst_b) - b_index;
		if (b_index == 0 || calculate_cost(temp) < calculate_cost(*best))
			moves_copy(temp, best);
		node = node->next;
		b_index++;
	}
}

void	do_best_moves(t_move *best, t_list **lst_a, t_list **lst_b)
{
	while (best->ra > 0 && best->rb > 0)
		(rr(lst_a, lst_b), (best->ra)--, (best->rb)--);
	while (best->ra > 0)
		(ra(lst_a, 1), (best->ra)--);
	while (best->rb > 0)
	{
		rb(lst_b, 1);
		(best->rb)--;
	}
	while (best->rra > 0 && best->rrb > 0)
	{
		rrr(lst_a, lst_b);
		(best->rra)--;
		(best->rrb)--;
	}
	while (best->rra > 0)
	{
		rra(lst_a, 1);
		(best->rra)--;
	}
	while (best->rrb > 0)
	{
		rrb(lst_b, 1);
		(best->rrb)--;
	}
}

void	ft_sort_more_than_five(t_list **lst_a, t_list **lst_b)
{
	t_move	best;
	int		mid;
	int		max;

	mid = (get_max(*lst_a) + get_min(*lst_a)) / 2;
	max = get_max(*lst_a);
	while (ft_lstsize((*lst_a)) > 1)
	{
		if ((*lst_a)->c == max)
			ra(lst_a, 1);
		else
		{
			pb(lst_b, lst_a);
			if ((*lst_b)->c > mid)
				rb(lst_b, 1);
		}
	}
	while (*lst_b)
	{
		reset_moves(&best);
		calculate_best_moves(&best, *lst_a, *lst_b);
		do_best_moves(&best, lst_a, lst_b);
		pa(lst_a, lst_b);
	}
	fix_stack_a(lst_a);
}
