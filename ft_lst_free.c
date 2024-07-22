/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 19:52:48 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/22 20:11:59 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_free(t_list **lst_a)
{
	t_list	*tmp;

	while (*lst_a != NULL)
	{
		tmp = (*lst_a);
		*lst_a = (*lst_a)->next;
		free(tmp);
	}
}
