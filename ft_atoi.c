/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 10:02:26 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/15 08:17:06 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi(char *s)
{
	if (!s)
		return (0);
	int i;
	int signe;
	int result;

	i = 0;
	signe = 1;
	result = 0;
	while (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			signe *= -1;
		i++;
	}
	if (i > 1)
		ft_putstr(2, "Error"), exit(1);
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 - 48 + s[i++];
		if ((result < 0 && signe > 0) || (result * -1 > 0 && signe < 0))
			(ft_putstr (2, "Error\n"), exit(1));
	}
	return (signe  * result);
}
