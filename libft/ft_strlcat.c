/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:38:51 by minjiki2          #+#    #+#             */
/*   Updated: 2023/04/11 13:38:54 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	src_len;
	unsigned int	dest_len;
	unsigned int	d_len;
	unsigned int	index;

	src_len = my_strlen(src);
	dest_len = my_strlen(dest);
	d_len = dest_len;
	index = 0;
	if (dest_len < size)
	{
		while (src[index] && index + 1 < size - dest_len)
		{
			dest[d_len] = src[index];
			index++;
			d_len++;
		}
		dest[d_len] = '\0';
	}
	if (dest_len > size)
		return (src_len + size);
	else
		return (src_len + dest_len);
}
