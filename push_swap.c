/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:14:21 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/21 10:42:17 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_indexing(t_list *lst)
{
	t_list	*tmp1;
	t_list	*tmp2;
	
	tmp1 = lst;
	while(tmp1)
	{
		tmp1 -> i = 0;
		tmp2 = lst;
		while(tmp2)
		{
			if (tmp1->c > tmp2->c)
				tmp1 -> i += 1;
			tmp2 = tmp2 -> next;
		}
		tmp1 = tmp1-> next;
	}
}
// void show(t_list *lst)
// {
// 	t_list	*tmp;
	
// 	tmp = lst;
// 	while (tmp)
// 	{
// 		printf ("content = %d _ index = %d \n", tmp->c, tmp->i);
// 		tmp = tmp->next;
// 	}
// }

// void	ft_lstdelone(t_list **lst, void (*del)(void*))
// {
// 	t_list *tmp;

// 	tmp = (*lst)->next;
// 	if (!lst)
// 		return ;
// 	free((*lst));
// 	(*lst) = tmp;
// }

void ft_lstaddfront(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = (*lst);
	(*lst) = new;
}

void ft_lstaddback(t_list *lst, t_list *new)
{
	t_list *tmp;

	tmp = lst;
	if (!lst || !new || !tmp)
		return ;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
	lst = tmp;
}

t_list *ft_lstnew(void)
{
	t_list* new;

	new = (t_list *)malloc(sizeof (t_list));
	if (!new)
		return (NULL);
	new->c = 0;
	new->next = NULL;
	return (new);
}

// void pa(t_list **lst_a, t_list **lst_b)
// {
// 	t_list *tmp;
	
// 	if (!lst_b || !*lst_b)
// 		return ;
// 	tmp = (*lst_b);
// 	(*lst_b) = (*lst_b)->next;
// 	ft_lstaddfront(lst_a, tmp);
// 	ft_indexing(*lst_a);
// 	ft_indexing(*lst_b);
// 	ft_putstr(1, "pa\n");
// }

void pb(t_list **lst_b, t_list **lst_a)
{
	t_list	*node;

	if (!lst_a || !(*lst_a))
		return ;

	node = *lst_a;
	(*lst_a) = (*lst_a)->next;
	node->next = (*lst_b);
	(*lst_b) = node;
	ft_indexing(*lst_a);
	ft_indexing(*lst_b);
	ft_putstr(1, "pb\n");
}
void pa(t_list **lst_a, t_list **lst_b)
{
	t_list	*node;

	if (!lst_b || !(*lst_b))
		return ;

	node = *lst_b;
	(*lst_b) = (*lst_b)->next;
	node->next = (*lst_a);
	(*lst_a) = node;
	ft_indexing(*lst_a);
	ft_indexing(*lst_b);
	ft_putstr(1, "pa\n");
}
// void pb(t_list **lst_b, t_list **lst_a)
// {
// 	t_list *tmp;

// 	if (!lst_a || !*lst_a)
// 		return ;
// 	tmp = (*lst_a);
// 	(*lst_a) = (*lst_a)->next;
// 	tmp->next = NULL;
// 	ft_lstaddfront(lst_b, tmp);
// 	ft_indexing(*lst_a);
// 	ft_indexing(*lst_b);
// 	ft_putstr(1, "pb\n");
// }

void rra(t_list **lst, int print)
{
	t_list *second_last;
	t_list *last;
	
    if (!lst || !*lst || !(*lst)->next)
        return;

    second_last = NULL;
    last = *lst;
    while (last->next) {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *lst;
    *lst = last;
	if (print)
   		ft_putstr(1, "rra\n");
}
void sa(t_list *lst)
{
	int tab[4];

	tab[0] = lst->c;
	tab[1] = lst->i;
	tab[2] = lst->next->c;
	tab[3] = lst->next->i;
	lst->c = tab[2];
	lst->i = tab[3];
	lst->next->c = tab[0];
	lst->next->i = tab[1];
	ft_putstr(1, "sa\n");
}

void rrb(t_list **lst, int print) 
{
	t_list *second_last;
	t_list *last;
	
    if (!lst || !*lst || !(*lst)->next)
        return;

    second_last = NULL;
    last = *lst;
    while (last->next) {
        second_last = last;
        last = last->next;
    }
    second_last->next = NULL;
    last->next = *lst;
    *lst = last;
	if (print)
    	ft_putstr(1, "rrb\n");
}

void ra(t_list **lst, int print)
{
	t_list	*last_node;
	t_list	*first;

	if (!lst || !*lst || !(*lst)->next)
		return;
	first = *lst;
	last_node = *lst;
	while (last_node->next)
		last_node = last_node->next;
	(*lst) = (*lst)->next;
	last_node->next = first;
	first->next = NULL;
	if (print)
 		ft_putstr(1, "ra\n");
}

void rb(t_list **lst, int print)
{
	t_list	*last_node;
	t_list	*first;

	if (!lst || !*lst || !(*lst)->next)
		return;
	first = *lst;
	last_node = *lst;
	while (last_node->next)
		last_node = last_node->next;
	(*lst) = (*lst)->next;
	last_node->next = first;
	first->next = NULL;
	if (print)
 		ft_putstr(1, "rb\n");
}

// void rb(t_list *lst)
// {
// 	t_list *new;
// 	t_list *tmp;
// 	t_list *tmp1;

// 	tmp = lst;
// 	new = (t_list *)malloc(sizeof (t_list));
// 	if (!new)
// 		return ;
// 	new->c = lst->c;
// 	new->i = lst->i;
// 	lst->c = lst->next->c;
// 	lst->i = lst->next->i;
// 	free (lst->next);
// 	lst->next = lst->next->next;
// 	tmp1 = lst;
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	tmp->next = new;
// 	lst = tmp1;
//  	ft_putstr(1, "rb\n");
// }


void sb(t_list *lst)
{
	int tab[4];

	tab[0] = lst->c;
	tab[1] = lst->i;
	tab[2] = lst->next->c;
	tab[3] = lst->next->i;
	lst->c = tab[2];
	lst->i = tab[3];
	lst->next->c = tab[0];
	lst->next->i = tab[1];
	ft_putstr(1, "sb\n");
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

void duplicate(t_list *lst)
{
	t_list *tmp1;
	t_list *tmp2;
	int i;
	int j;

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
				{
					ft_putstr(2, "Error\n"), exit(1);
				}
			}
			tmp2 = tmp2->next;
			j++;
		}
		tmp1 = tmp1->next;
		i++;
	}
}


void three(t_list *lst)
{
	int a;
	int b;
	int c;

	a = lst->i;
	b = lst->next->i;
	c = lst->next->next->i;
	if (a > b && b > c && a > c)
		(sa(lst), rra(&lst, 1));
	else if (a < b && b > c && a < c)
		(rra(&lst, 1), sa(lst));
	else if (a < b && b > c && a > c)
		rra(&lst, 1);
	else if (a > b && b < c && a < c)
		sa(lst);
	else if (a > b && b < c && a > c)
		ra(&lst, 1);
}

void four(t_list **lst_a, t_list **lst_b)
{
	while ((*lst_a)->i != 0)
		rra(lst_a, 1);
	pb(lst_b, lst_a);
	three (*lst_a);
	pa(lst_a, lst_b);
}

void five(t_list **lst_a, t_list **lst_b)
{
	if ((*lst_a)->i == 0)
		pb(lst_b, lst_a);
	else if ((*lst_a)->next->i == 0)
		(ra(lst_a, 1), pb(lst_b, lst_a));
	else if ((*lst_a)->next->next->i == 0)
		(ra(lst_a, 1), ra(lst_a, 1), pb(lst_b, lst_a));
	else if ((*lst_a)->next->next->next->i == 0)
		(rra(lst_a, 1), rra(lst_a, 1), pb(lst_b, lst_a));
	else if ((*lst_a)->next->next->next->next->i == 0)
		(rra(lst_a, 1), pb(lst_b, lst_a));
	four(lst_a, lst_b);
	pa(lst_a, lst_b);
}

t_list *sorttab(char **p)
{
	int i;
	t_list *lst;
	t_list *new;

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
	if (ft_lstsize(lst) == 3)
		three (lst);
	return (lst);
}

void f()
{
	system("leaks push_swap");
}
// void ft_more_than_5(t_list **lst_a, t_list **lst_b)
// {
// 	while (ft_lstsize((*lst_a)) > 0)
// 		pb(lst_b, lst_a);
// 	// three ((*lst_a));
// 	while (ft_lstsize((*lst_b)) && (*lst_b)->i != 0)
// 		rra(lst_b);
// 	while ((*lst_b))
// 		pa(lst_b, lst_a);
// }

void ft_rest(move *best)
{
	best->ra = 0;
	best->rb = 0;
	best->rra = 0;
	best->rrb = 0;
}

int main(int ac, char **av)
{
	// atexit(f);
	char **p;
	t_list *lst_a;
	t_list *lst_b;

	if (!av[1])
		ft_putstr(1, "Error\n"), exit(1);
	if (ac > 1)
	{
		chekarg(av);
		p = collectarg(av);
		lst_a = sorttab(p);
		if (ft_lstsize(lst_a) == 2)
		{
			if (lst_a->i > lst_a->next->i)
				sa(lst_a);
		}
		else if (ft_lstsize(lst_a) == 3)
			three(lst_a);
		else if (ft_lstsize(lst_a) == 4)
			four(&lst_a, &lst_b);
		else if (ft_lstsize(lst_a) == 5)
			five(&lst_a, &lst_b);
		else if (ft_lstsize (lst_a) > 5)
			ft_sort_more_than_five(&lst_a, &lst_b);
		// ft_exit(p, lst_a);
	}
}
