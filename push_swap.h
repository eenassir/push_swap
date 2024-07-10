/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:09:05 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/10 23:34:10 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int ft_strlen(char *s);
int ft_atoi(char *s);
char **ft_split(char *s, char c);
void ft_exit(char **p);
void ft_putstr(char *s);

typedef struct s_list
{
	int index;
} t_list;


#endif