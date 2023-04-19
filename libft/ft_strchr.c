/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:37:54 by minjiki2          #+#    #+#             */
/*   Updated: 2023/04/11 13:37:57 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		idx;

	idx = 0;
	while (str[idx])
	{	
		if (str[idx] == (unsigned char)c)
			return ((char *)(str + idx));
		idx++;
	}
	if (str[idx] == (unsigned char)c)
		return ((char *)(str + idx));
	return (NULL);
}
