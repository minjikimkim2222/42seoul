/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:29:14 by minjiki2          #+#    #+#             */
/*   Updated: 2023/04/11 13:29:43 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t size)
{
	size_t			index;
	unsigned char	*ptr;

	index = 0;
	ptr = (unsigned char *)s;
	while (index < size)
	{	
		ptr[index] = 0;
		++index;
	}
}
