/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:14:21 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/15 09:11:24 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_list **lst, int len)
{
	t_list *new;

	new = (t_list *)malloc(sizeof (t_list));
	if (!new)
		return ;
	new = lst[0];
	lst[0] = lst[len - 1];
	new->next = lst[1];
	lst[0]->next = new;
	lst[len - 2]->next = NULL;
	ft_putstr(1, "rra\n");
}

void ra(t_list **lst, int len)
{
	t_list *new;
	
	new = (t_list *)malloc(sizeof (t_list));
	if (!new)
		return ;
	new = lst[0];
	lst[0] = lst[0]->next;
	new->next = NULL;
	lst[len - 1]->next = new;
	ft_putstr(1, "ra\n");
}

void sa(t_list **lst)
{
	int c;

	c = lst[0]->k;
	lst[0]->k = lst[1]->k;
	lst[1]->k = c;
	ft_putstr(1, "sa\n");
}

void pa(t_list **lst, t_list **lst1, int len)
{
	(void)len;
	t_list *new;

	new = (t_list *)malloc(sizeof (t_list));
	if (!new)
		return ;
	new->k = lst1[0]->k;
	new->next = lst1[0]->next;
	lst1[0]->next = new;
	lst1[0]->k = lst[0]->k;
	lst[0] = lst[0]->next;
	ft_putstr(1, "pa\n");
}
void three(t_list **lst, int len)
{
	if (lst[0]->k < lst[1]->k && lst[1]->k < lst[2]->k && lst[0]->k < lst[2]->k)
		exit(0);
	else if (lst[0]->k > lst[1]->k && lst[1]->k > lst[2]->k && lst[0]->k > lst[2]->k)
		(sa(lst), rra(lst, len));
	else if (lst[0]->k > lst[1]->k && lst[1]->k < lst[2]->k && lst[0]->k < lst[2]->k)
		sa(lst);
	else if (lst[0]->k > lst[1]->k && lst[1]->k < lst[2]->k && lst[0]->k > lst[2]->k)
		ra(lst, len);
	else if (lst[0]->k < lst[1]->k && lst[1]->k > lst[2]->k && lst[0]->k > lst[2]->k)
		rra(lst, len);
	else if (lst[0]->k < lst[1]->k && lst[1]->k > lst[2]->k && lst[0]->k < lst[2]->k)
		sa(lst), ra(lst, len);
}

void swap_el(t_list **lst, t_list **lst1, int len)
{
	(void)len;
	(void)lst1;
	if (len == 3)
		three  (lst, len);
	while (lst[0] != NULL)
	{
		printf ("%d\n", lst[0]->k);
		lst[0] = lst[0]->next;
	}
}

void chekarg(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ' && av[i][j] != '-' && av[i][j] != '+' && !(av[i][j] >= '0' && av[i][j] <= '9'))
				ft_putstr(2, "Error\n"), exit(1);
			j++;
		}
		i++;
	}
}
int sizearg(char **av)
{
	int l;
	int i;
	
	l = 0;
	i = 1;
	while (av[i])
	{
		l += ft_strlen(av[i]);
		if (av[i + 1] != NULL)
			l += 1;
		i++;
	}
	return (l);
}

char **collectarg(char **av)
{
	int i;
	int j;
	int cpt;
	char *s;
	char **p;

	i = 1;
	cpt = 0;
	s = (char *)malloc(sizearg(av) + 1);
	if (!s)
		return (NULL);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			s[cpt++] = av[i][j];
			if ((av[i][j] == '+' || av[i][j] == '-') && (av[i][j + 1] == ' ' || av[i][j + 1] == '\0'))
				ft_putstr(2, "Error\n"), exit(1);
			j++;
		}
		if (av[i] != NULL)
			s[cpt++] = ' ';
		i++;
	}
	i = 0;
	
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9') && (s[i + 1] != ' ' && !(s[i + 1] >= '0' && s[i + 1] <= '9')))
		{
			ft_putstr(2, "Error\n"), exit(1);
		}
		i++;
	}
	p = ft_split(s, ' ');
	i = 0;
	while (p[i])
	{
		j = 0;
		while (p[i][j])
		{
			j++;
		}
		i++;
	}
	free (s);
	return (p);	
}

int ft_count(char **p)
{
	int i;

	i = 0;
	while (p[i])
		i++;
	return (i);
}

void duplicate(t_list **lst, int len)
{
	t_list **lst1;
	int i;
	int j;

	if (len == 2)
		exit(1);
	i = 0;
	lst1 = lst;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (lst[i]->k == lst1[j]->k)
			{
				if (i != j)
				{
					ft_putstr(2, "Error\n"), exit(1);
				}
			}
			j++;
		}
		i++;
	}
}

t_list **sorttab(char **p)
{
	int i;
	t_list **lst;
	t_list **lst1;
	int l;

	i = 0;
	l = ft_count(p);
	lst = (t_list **)malloc(l * sizeof (t_list *));
	if (!lst)
		return (NULL);
	lst1 = (t_list **)malloc(l * sizeof (t_list *));
	if (!lst1)
		return (NULL);
	while (i < l)
	{
		lst[i] = (t_list *)malloc(sizeof(t_list));
		if (!lst[i])
			return (NULL);
		lst1[i] = (t_list *)malloc(sizeof(t_list));
		if (!lst1[i])
			return (NULL);
		i++;
	}
	i = 0;
	while (i < l)
	{
		if (i + 1 < l)
		{
			lst[i]->next = lst[i + 1];
			lst1[i]->next = lst1[i + 1];
		}
		else
		{
			lst[i]->next = NULL;
			lst1[i]->next = NULL;
		}
		i++;
	}
	i = 0;
	while (p[i])
	{
		lst[i]->k = ft_atoi(p[i]);
		i++;
	}
	duplicate(lst, l);
	swap_el(lst, lst1, l);
	return (lst);
}

void f()
{
	system("leaks push_swap");
}

int main(int ac, char **av)
{
	char **p;
	t_list **lst;
	
	if (ac > 1)
	{
		chekarg(av);
		p = collectarg(av);
		lst = sorttab(p);
		ft_exit(0);
	}
}