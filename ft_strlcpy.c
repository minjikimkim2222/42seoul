/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:39:12 by minjiki2          #+#    #+#             */
/*   Updated: 2023/04/11 13:39:13 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	len;
	unsigned int	index;

	len = 0;
	index = 0;
	while (src[len])
		len++;
	if (size == 0)
		return (len);
	while (src[index] && index + 1 < size)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (len);
}
