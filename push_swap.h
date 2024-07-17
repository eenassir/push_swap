/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:09:05 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/15 08:15:43 by eenassir         ###   ########.fr       */
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
void ft_putstr(int i, char *s);

typedef struct s_list
{
	int k;
	struct s_list *next;
} t_list;


#endif