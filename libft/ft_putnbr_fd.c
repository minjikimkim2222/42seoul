/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:36:52 by minjiki2          #+#    #+#             */
/*   Updated: 2023/04/11 13:36:59 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	int_to_str(int num, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n == 0)
		write(fd, "0", 1);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	if (n > 0)
	{
		int_to_str(n, fd);
	}
	return ;
}

static void	int_to_str(int num, int fd)
{
	char	remainder;

	if (num == 0)
		return ;
	else
	{
		remainder = (num % 10) + '0';
		num = num / 10;
		int_to_str(num, fd);
		write(fd, &remainder, 1);
	}
}
