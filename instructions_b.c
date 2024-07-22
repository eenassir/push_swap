/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 10:55:14 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/22 09:47:10 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_list **lst_a, t_list **lst_b)
{
	ra(lst_a, 0);
	rb(lst_b, 0);
	ft_putstr(1, "rr\n");
}

void	sb(t_list *lst)
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
	ft_putstr(1, "sb\n");
}

void	pb(t_list **lst_b, t_list **lst_a)
{
	t_list	*node;

	if (!lst_a || !(*lst_a))
		return ;
	node = *lst_a;
	(*lst_a) = (*lst_a)->next;
	node->next = NULL;
	node->next = (*lst_b);
	(*lst_b) = node;
	ft_indexing(*lst_a);
	ft_indexing(*lst_b);
	ft_putstr(1, "pb\n");
}

void	rb(t_list **lst, int print)
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
	last_node->next = first;
	first->next = NULL;
	if (print)
		ft_putstr(1, "rb\n");
}

void	rrb(t_list **lst, int print)
{
	t_list	*second_last;
	t_list	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	second_last = NULL;
	last = *lst;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *lst;
	*lst = last;
	if (print)
		ft_putstr(1, "rrb\n");
}
