/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 23:14:21 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/11 00:45:35 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sb(int *stack_b, int len)
{
	int i;
	
	i = 0;
	while (i < len)
		printf ("%d\n", stack_b[i]);
}

void rra(int *stack_a, int len)
{
	int i;
	int c;

	i = 0;
	while (i < len / 2)
	{
		c = stack_a[len - 1 - i];
		stack_a[len - 1 - i] = stack_a[i];
		stack_a[i] = c;
		i++;
	}
}
void pb(int *stack_a, int* stack_b, int len, t_list *sort)
{
	(void)len;
	int c;
	
	if (sort->index == 0)
	{
		printf ("|%d|\n", sort->index);
		stack_b[sort->index] = stack_a[sort->index];
		c = stack_b[sort->index];
		stack_b[sort->index] = stack_b[sort->index + 1];
		stack_b[sort->index + 1] = c;
	}
	sort->index++;
}

void ra(int *stack_a, int len)
{
	int i;
	int c;

	i = 0;
	while (i < len / 2)
	{
		c = stack_a[i];
		stack_a[i] = stack_a[len - 1 - i];
		stack_a[len - 1 - i] = c;
		i++;
	}
}

void sa(int *stack_a, int len)
{
	int c;
	
	if (len <= 1)
		return ;
	c = stack_a[1];
	stack_a[1] = stack_a[0];
	stack_a[0] = c;
}

void three(int *tab, int len)
{
	int i;

	i = 0;
	if (tab[0] > tab[1] && tab[1] < tab[2] && tab[0] < tab[2])
	{
		sa(tab, len);
	}
	while (i < len)
		printf ("%d\n", tab[i++]);
}

void swap_el(int *tab, int len)
{
	int i;
	int *stack_b;
	t_list sort;
	
	i = 0;
	stack_b = (int *)malloc(len);
	if (!stack_b)
		return ;
	stack_b[0] = '\0';
	stack_b[1] = '\0';
	stack_b[2] = '\0';
	stack_b[3] = '\0';
	stack_b[4] = '\0';
	stack_b[5] = '\0';
	sa(tab, len);
	sort.index = 0;
	pb(tab, stack_b, len, &sort);
	pb(tab, stack_b, len, &sort);
	pb(tab, stack_b, len, &sort);
	while (i < len)
	{
		printf("%d %d\n", tab[i], stack_b[i]);
		i++;
	}
	printf ("- -\na b");
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
				ft_putstr("Error\n"), exit(1);
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
				ft_putstr("Error\n"), exit(1);
			j++;
		}
		if (av[i] != NULL)
			s[cpt++] = ' ';
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

void duplicate(int *tab, int len)
{
	int *tab1;
	int i;
	int j;

	i = 0;
	tab1 = tab;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (tab[i] == tab1[j])
			{
				if (i != j)
				{
					ft_putstr("Error\n"), exit(1);
				}
			}
			j++;
		}
		i++;
	}
}

int *sorttab(char **p)
{
	int i;
	int j;
	int *tab;
	int l;

	i = 0;
	j = 0;
	l = ft_count(p);
	tab = (int *)malloc((l + 1) * sizeof (int));
	if (!tab)
		return (NULL);
	while (p[i])
		tab[j++] = ft_atoi(p[i++]);
	duplicate(tab, l);
	swap_el(tab, l);
	return (tab);
}

void f()
{
	system("leaks push_swap");
}

int main(int ac, char **av)
{
	// atexit(f);
	char **p;
	int *tab;
	
	if (ac >= 2)
	{
		chekarg(av);
		p = collectarg(av);
		tab = sorttab(p);
		ft_exit(p);
	}
}