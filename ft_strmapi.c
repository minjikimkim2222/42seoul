/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:39:31 by minjiki2          #+#    #+#             */
/*   Updated: 2023/04/11 13:39:33 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		idx;
	int		str_len;
	char	*p;

	idx = 0;
	str_len = 0;
	if (!s || !f)
		return (0);
	while (s[str_len])
		str_len++;
	p = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!p)
		return (NULL);
	while (idx < str_len)
	{
		p[idx] = f(idx, s[idx]);
		idx++;
	}
	p[idx] = '\0';
	return (p);
}
