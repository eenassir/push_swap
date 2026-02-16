/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:50:26 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/22 20:13:34 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_list **lst_a, t_list **lst_b)
{
	(rra(lst_a, 0), rrb(lst_b, 0));
	ft_putstr(1, "rrr\n");
}

void	sa(t_list *lst)
{
	int	tab[4];

	tab[0] = lst->c;
	tab[1] = lst->i;
	tab[2] = lst->next->c;
	tab[3] = lst->next->i;
	lst->c = tab[2];
	lst->i = tab[3];
	lst->next->c = tab[0];
	lst->next->i = tab[1];
	ft_putstr(1, "sa\n");
}

void	pa(t_list **lst_a, t_list **lst_b)
{
	t_list	*node;

	if (!lst_b || !(*lst_b))
		return ;
	node = *lst_b;
	(*lst_b) = (*lst_b)->next;
	node->next = (*lst_a);
	(*lst_a) = node;
	ft_indexing(*lst_a);
	ft_indexing(*lst_b);
	ft_putstr(1, "pa\n");
}

void	ra(t_list **lst, int print)
{
	t_list	*last_node;
	t_list	*first;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	first = *lst;
	last_node = *lst;
	while (last_node->next)
		last_node = last_node->next;
	(*lst) = (*lst)->next;
	first->next = NULL;
	last_node->next = first;
	if (print)
		ft_putstr(1, "ra\n");
}

void	rra(t_list **lst, int print)
{
	t_list	*second_last;
	t_list	*last;
	t_list	*tmp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	second_last = NULL;
	last = *lst;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	tmp = second_last->next;
	tmp->next = NULL;
	second_last->next = NULL;
	last->next = *lst;
	*lst = last;
	if (print)
		ft_putstr(1, "rra\n");
}
