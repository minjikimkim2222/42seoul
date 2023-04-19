/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:38:19 by minjiki2          #+#    #+#             */
/*   Updated: 2023/04/11 13:38:21 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	idx;

	idx = 0;
	if (!s || !f)
		return ;
	while (s[idx])
	{
		f(idx, &s[idx]);
		idx++;
	}
	return ;
}
