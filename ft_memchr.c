/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:34:51 by minjiki2          #+#    #+#             */
/*   Updated: 2023/04/11 13:35:01 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned int	idx;

	ptr = (unsigned char *)src;
	idx = 0;
	while (idx < n)
	{
		if (ptr[idx] == (unsigned char)c)
			return (ptr + idx);
		idx++;
	}
	return (NULL);
}
