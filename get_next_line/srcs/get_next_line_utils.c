/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 09:00:07 by minjiki2          #+#    #+#             */
/*   Updated: 2023/07/28 09:00:11 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *s)
{
	char			*p;
	unsigned int	idx;
	unsigned int	len;

	idx = 0;
	len = ft_strlen(s);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (s[idx])
	{
		p[idx] = s[idx];
		idx++;
	}
	p[idx] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc((s1_len + s2_len + 1) * (sizeof(char)));
	if (!str)
		return (NULL);
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < s2_len)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == (unsigned char)c)
			return ((char *)(str + idx));
		idx++;
	}
	if (str[idx] == (unsigned char)c)
		return ((char *)(str + idx));
	return (NULL);
}

char	*append_string(char *backup, char *buf)
{
	char	*p;

	p = ft_strjoin(backup, buf);
	free(backup);
	return (p);
}
