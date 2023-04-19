/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:35:10 by minjiki2          #+#    #+#             */
/*   Updated: 2023/04/11 13:35:16 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	int				idx;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	idx = 0;
	while (n > 0)
	{
		if (p1[idx] != p2[idx])
			return (p1[idx] - p2[idx]);
		n--;
		idx++;
	}
	return (0);
}
