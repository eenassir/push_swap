/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 11:57:49 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/21 14:44:35 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(void)
{
	t_list	*new_;

	new_ = (t_list *)malloc(sizeof (t_list));
	if (!new_)
		return (NULL);
	new_->c = 0;
	new_->next = NULL;
	return (new_);
}
