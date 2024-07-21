/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:09:05 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/21 19:57:05 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				c;
	int				i;
	struct s_list	*next;
}	t_list;

typedef struct s_move
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}	t_move;

int		ft_strlen(char *s);
int		ft_atoi(char *s);
char	**ft_split(char *s, char c);
void	ft_exit(char **p);
void	ft_putstr(int i, char *s);
int		ft_lstsize(t_list *lst);
void	pa(t_list **lst_a, t_list **lst_b);
void	pb(t_list **lst_b, t_list **lst_a);
void	rra(t_list **lst, int print);
void	sa(t_list *lst);
void	rrb(t_list **lst, int print);
void	ra(t_list **lst, int print);
void	rb(t_list **lst, int print);
void	sb(t_list *lst);
void	ft_sort_more_than_five(t_list **lst_a, t_list **lst_b);
void	ft_indexing(t_list *lst);
void	ft_rest(t_move *best);
void	ft_lstaddfront(t_list **lst, t_list *new);
void	ft_lstaddback(t_list *lst, t_list *new);
t_list	*ft_lstnew(void);
void	three(t_list *lst);
void	four(t_list **lst_a, t_list **lst_b);
void	five(t_list **lst_a, t_list **lst_b);
int		sizearg(char **av);
void	chekarg(char **av);
void	rrr(t_list **lst_a, t_list **lst_b);
void	rr(t_list **lst_a, t_list **lst_b);
int		calculate_cost(t_move mv);
void	fix_stack_a(t_list **lst_a);
int		get_min(t_list *lst);
int		get_max(t_list *lst);
void	reset_moves(t_move *mv);
int		get_small_begger_than(t_list *lst_a, int b);
void	ft_free2(char **p);
char	*collectarg(char **av);
void ft_lst_free(t_list **lst_a);

#endif