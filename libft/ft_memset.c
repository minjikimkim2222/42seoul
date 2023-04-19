/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:36:02 by minjiki2          #+#    #+#             */
/*   Updated: 2023/04/11 13:36:09 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t size)
{	
	size_t			index;
	unsigned char	*str;

	index = 0;
	str = (unsigned char *)ptr;
	while (index < size)
	{
		str[index] = value;
		++index;
	}
	return (str);
}
