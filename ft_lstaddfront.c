/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddfront.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:53:48 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/21 14:44:17 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstaddfront(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = (*lst);
	(*lst) = new;
}
