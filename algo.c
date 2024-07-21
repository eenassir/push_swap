/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:47:15 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/20 23:46:01 by eenassir         ###   ########.fr       */
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

void	rr(t_list **lst_a, t_list **lst_b)
{
	ra(lst_a, 0);
	rb(lst_b, 0);
	ft_putstr(1, "rr\n");
}
void	rrr(t_list **lst_a, t_list **lst_b)
{
	rra(lst_a, 0);
	rrb(lst_b, 0);
	ft_putstr(1, "rrr\n");
}

int	get_min(t_list *lst)
{
	int min;

	if (!lst)
		return (0);
	if (!(lst->next))
		return (lst->c);
	min = lst->c;
	lst = lst->next;
	while (lst)
	{
		if (lst->c < min)
			min = lst->c;
		lst = lst->next;
	}
	return (min);
}

int	get_max(t_list *lst)
{
	int max;

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


void	all_to_stack_b(t_list **lst_a, t_list **lst_b)
{
	int	mid;
	int	max;

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
}

void	print_moves(move mv)
{
	printf("ra = %d\n", mv.ra);
	printf("rb = %d\n", mv.rb);
	printf("rra = %d\n", mv.rra);
	printf("rrb = %d\n", mv.rrb);
}

void	reset_moves(move *mv)
{
	mv->ra = 0;
	mv->rb = 0;
	mv->rra = 0;
	mv->rrb = 0;
}

int	calculate_cost(move mv)
{
	return (ft_max(mv.ra, mv.rb) + ft_max(mv.rra, mv.rrb));
}

int	get_asrer_wahd_kabr_mno(t_list *lst_a, int b)
{
	int	best_val;
	int	best_index;
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

void	moves_copy(move from, move *to)
{
	to->ra = from.ra;
	to->rra = from.rra;
	to->rb = from.rb;
	to->rrb = from.rrb;
}

void	calculate_best_moves(move *best, t_list *lst_a, t_list *lst_b)
{
	move	temp;
	t_list	*node;
	int		a_index;
	int		b_index;

	b_index = 0;
	node = lst_b;
	while (node)
	{
		reset_moves(&temp);
		a_index = get_asrer_wahd_kabr_mno(lst_a, node->c);
		if (a_index < ft_lstsize(lst_a) / 2)
			temp.ra = a_index;
		else
			temp.rra = ft_lstsize(lst_a) - a_index;
		if (b_index < ft_lstsize(lst_b) / 2)
			temp.rb = b_index;
		else
			temp.rrb = ft_lstsize(lst_b) - b_index;
		// temp.ra = a_index;
		// temp.rb = b_index;
		// temp.rra = ft_lstsize(lst_a) - a_index;
		// temp.rrb = ft_lstsize(lst_b) - b_index;
		if (b_index == 0 || calculate_cost(temp) < calculate_cost(*best))
			moves_copy(temp, best);
		node = node->next;
		b_index++;
	}
}

void	do_best_moves(move *best, t_list **lst_a, t_list **lst_b)
{
	while (best->ra > 0 && best->rb > 0)
	{
		rr(lst_a, lst_b);
		(best->ra)--;
		(best->rb)--;
	}
	while (best->ra > 0)
	{
		ra(lst_a, 1);
		(best->ra)--;
	}
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

int	ft_get_index_min(t_list *lst)
{
	int min;
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

void	ft_sort_more_than_five(t_list **lst_a, t_list **lst_b)
{
	move	best;

	all_to_stack_b(lst_a, lst_b);
	while (*lst_b)
	{
		reset_moves(&best);
		calculate_best_moves(&best, *lst_a, *lst_b);
		do_best_moves(&best, lst_a, lst_b);
		pa(lst_a, lst_b);
	}
	fix_stack_a(lst_a);
}
