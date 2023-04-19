/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:37:26 by minjiki2          #+#    #+#             */
/*   Updated: 2023/04/11 13:37:41 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*my_free(char **p, int i)
{
	while (i >= 0)
	{
		free(p[i]);
		i--;
	}
	free(p);
	return (0);
}

static int	word_count(const char *s, char c)
{
	int	w_c;

	w_c = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			w_c++;
		while (*s && *s != c)
			s++;
	}
	return (w_c);
}

static char	*word_malloc(const char *s, char c)
{
	int		idx;
	char	*p;

	idx = 0;
	while (s[idx] && s[idx] != c)
		idx++;
	p = (char *)malloc(sizeof(char) * (idx + 1));
	if (!p)
		return (0);
	idx = 0;
	while (s[idx] && s[idx] != c)
	{
		p[idx] = s[idx];
		idx++;
	}
	p[idx] = 0;
	return (p);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**p;

	i = 0;
	j = 0;
	p = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!p)
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			p[j] = word_malloc(s + i, c);
			if (!p[j++])
				return (my_free(p, j - 2));
		}
		while (s[i] && s[i] != c)
			i++;
	}
	p[j] = 0;
	return (p);
}
