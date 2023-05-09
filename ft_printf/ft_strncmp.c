/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:11:51 by minjiki2          #+#    #+#             */
/*   Updated: 2023/05/09 20:11:53 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{	
	unsigned int	index;

	index = 0;
	if (n == 0)
		return (0);
	else
	{	
		while ((str1[index] == str2[index]) && str1[index] && index < n - 1)
			index++;
	}
	return ((unsigned char)str1[index] - (unsigned char)str2[index]);
}
