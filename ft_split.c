/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eenassir <eenassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:17:27 by eenassir          #+#    #+#             */
/*   Updated: 2024/07/21 20:26:55 by eenassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_word(char *s, int c)
{
	int	i;
	int	cpt;

	i = 0;
	cpt = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			cpt++;
		i++;
	}
	return (cpt);
}

int	ft_strlenc(char *s, int c)
{
	int	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*p;
	int		l;

	i = 0;
	l = ft_strlen(s);
	if (len > l - start)
		len = l - start;
	if (start > l)
		len = 0;
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	while (s[start] && i < len)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}

char	**ft_free(char **p, int j)
{
	while (j > 0)
	{
		free(p[j]);
		j--;
	}
	free(p[j]);
	free(p);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	char	**p;
	int		cpt;
	int		len;

	i = 0;
	j = 0;
	cpt = ft_count_word(s, c);
	p = (char **)malloc((cpt + 1) * sizeof (char *));
	if (!p)
		return (NULL);
	while (j < cpt)
	{
		while (s[i] == c)
			i++;
		p[j] = ft_substr(s, i, len = ft_strlenc(s + i, c));
		if (!p[j++])
			return (ft_free(p, j - 1));
		i += len;
	}
	p[j] = NULL;
	return (p);
}
