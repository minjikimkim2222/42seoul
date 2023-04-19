/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:40:36 by minjiki2          #+#    #+#             */
/*   Updated: 2023/04/11 13:40:38 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	my_str_len(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strrchr(const char *str, int ch)
{
	int	len;

	len = my_str_len(str);
	if ((char)ch == '\0')
		return ((char *)(str + len));
	while (len > 0)
	{
		if (str[len - 1] == (unsigned char)ch)
			return ((char *)str + (len - 1));
		len--;
	}
	return (NULL);
}
