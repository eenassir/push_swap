/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 18:40:50 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/22 08:41:19 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp_;

	i = 0;
	tmp_ = lst;
	while (tmp_ != NULL)
	{
		i++;
		tmp_ = tmp_->next;
	}
	return (i);
}
