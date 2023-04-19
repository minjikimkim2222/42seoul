/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:34:33 by minjiki2          #+#    #+#             */
/*   Updated: 2023/04/11 13:34:39 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	int_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*p;
	long	nb;

	len = int_len(n);
	nb = n;
	p = malloc(sizeof(char) * len + 1);
	if (!p)
		return (NULL);
	if (nb < 0)
	{
		p[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		p[0] = '0';
	p[len] = '\0';
	while (nb)
	{
		p[len - 1] = nb % 10 + '0';
		len--;
		nb = nb / 10;
	}
	return (p);
}
