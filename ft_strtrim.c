/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:40:46 by minjiki2          #+#    #+#             */
/*   Updated: 2023/04/11 13:40:48 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		last;
	char	*p;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	last = ft_strlen(s1);
	while (last > 0 && ft_strchr(set, s1[last - 1]))
		--last;
	p = ft_substr(s1, 0, last);
	return (p);
}
