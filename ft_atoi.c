/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:29:00 by minjiki2          #+#    #+#             */
/*   Updated: 2023/04/11 13:29:09 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			idx;
	long long	minus;
	long long	num;

	idx = 0;
	minus = 1;
	num = 0;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '+')
		idx++;
	else if (str[idx] == '-')
	{
		minus = -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		num = num * 10 + (str[idx] - '0');
		idx++;
	}
	return ((int)(minus * num));
}
