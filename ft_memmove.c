/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:35:43 by minjiki2          #+#    #+#             */
/*   Updated: 2023/04/11 13:35:52 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t size)
{
	size_t			index;
	unsigned char	*dst;
	unsigned char	*src;

	dst = (unsigned char *)dest;
	src = (unsigned char *)source;
	if (dst > src)
	{
		index = 0;
		while (index < size)
		{
			dst[size - index - 1] = src[size - index - 1];
			index++;
		}
	}
	else if (dst < src)
	{
		index = 0;
		while (index < size)
		{
			dst[index] = src[index];
			index++;
		}
	}
	return (dst);
}
