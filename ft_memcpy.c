/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:35:29 by minjiki2          #+#    #+#             */
/*   Updated: 2023/04/11 13:35:34 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t size)
{
	size_t			index;
	unsigned char	*dst;
	unsigned char	*src;

	dst = (unsigned char *)dest;
	src = (unsigned char *)source;
	if (dst == src)
		return (dst);
	index = 0;
	while (index < size)
	{
		dst[index] = src[index];
		index++;
	}
	return (dest);
}
