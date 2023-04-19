/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:37:10 by minjiki2          #+#    #+#             */
/*   Updated: 2023/04/11 13:37:13 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	idx;

	idx = 0;
	if (fd < 0 || !s)
		return ;
	while (s[idx])
	{
		write(fd, &s[idx], 1);
		idx++;
	}
}
