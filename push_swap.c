/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:14:21 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/22 10:15:38 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**collectarg_util(char **av, int ac)
{
	int		i;
	char	**p;
	char	*s;

	s = collectarg(av, ac);
	i = 0;
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9') && (s[i + 1] != ' '
			&& !(s[i + 1] >= '0' && s[i + 1] <= '9') && s[i + 1] != '\0'))
			(ft_putstr(2, "Error\n"));
		i++;
	}
	p = ft_split(s, ' ');
	free (s);
	return (p);
}

void	duplicate(t_list *lst)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		i;
	int		j;

	i = 0;
	tmp1 = lst;
	while (tmp1)
	{
		j = 0;
		tmp2 = lst;
		while (tmp2)
		{
			if (tmp1->c == tmp2->c)
			{
				if (i != j)
					(ft_putstr(2, "Error\n"), ft_lst_free(&lst), exit(0));
			}
			tmp2 = tmp2->next;
			j++;
		}
		tmp1 = tmp1->next;
		i++;
	}
}

t_list	*sorttab(char **p)
{
	int		i;
	t_list	*lst;
	t_list	*new;

	i = 0;
	lst = ft_lstnew();
	lst->c = ft_atoi(p[i]);
	lst->i = 0;
	i++;
	while (p[i])
	{
		new = ft_lstnew();
		ft_lstaddback(lst, new);
		new->c = ft_atoi(p[i]);
		new->i = 0;
		i++;
	}
	ft_indexing(lst);
	duplicate(lst);
	ft_free2(p);
	return (lst);
}

void	cheek_sort(t_list *lst_a, char **p)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = lst_a;
	while (tmp->next != NULL)
	{
		if (tmp->c > tmp->next->c)
			i++;
		tmp = tmp->next;
	}
	if (i == 0)
		ft_free2(p);
}
void f()
{
	system ("leaks push_swap");
}

int	main(int ac, char **av)
{
	atexit(f);
	char	**p;
	t_list	*lst_a;
	t_list	*lst_b;
	int		i;

	i = 0;
	if (ac > 1)
	{
		chekarg(av);
		p = collectarg_util(av, ac);
		lst_a = sorttab(p);
		// cheek_sort(lst_a, p);
		if (ft_lstsize(lst_a) == 2 && lst_a->i > lst_a->next->i)
			sa(lst_a);
		else if (ft_lstsize(lst_a) == 3)
			three(lst_a);
		else if (ft_lstsize(lst_a) == 4)
			four(&lst_a, &lst_b);
		else if (ft_lstsize(lst_a) == 5)
			five(&lst_a, &lst_b);
		else if (ft_lstsize (lst_a) > 5)
			ft_sort_more_than_five(&lst_a, &lst_b);
		ft_lst_free(&lst_a);
		ft_lst_free(&lst_b);
	}
}
