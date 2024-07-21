/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:55:37 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/21 14:44:05 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstaddback(t_list *lst, t_list *new)
{
	t_list	*tmp;

	tmp = lst;
	if (!lst || !new || !tmp)
		return ;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
	lst = tmp;
}
