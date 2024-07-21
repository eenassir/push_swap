/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:09:05 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/20 23:07:03 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	int c;
	int i;
	struct s_list *next;
} t_list;

typedef struct s_move
{
	int ra;
	int rb;
	int rra;
	int rrb;
} move;

int ft_strlen(char *s);
int ft_atoi(char *s);
char **ft_split(char *s, char c);
void ft_exit(char **p, t_list *lst);
void ft_putstr(int i, char *s);
int ft_lstsize(t_list *lst);

void pa(t_list **lst_a, t_list **lst_b);
void pb(t_list **lst_b, t_list **lst_a);
void rra(t_list **lst, int print);
void sa(t_list *lst);
void rrb(t_list **lst, int print);
void ra(t_list **lst, int print);
void rb(t_list **lst, int print);
void sb(t_list *lst);
void	ft_sort_more_than_five(t_list **lst_a, t_list **lst_b);
void show(t_list *lst);
#endif