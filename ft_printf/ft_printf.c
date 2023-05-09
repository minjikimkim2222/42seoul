/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:18:50 by minjiki2          #+#    #+#             */
/*   Updated: 2023/04/22 20:18:51 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char*	ft_printf_s(va_list	ap, const char*	format);
int		compare_format(const char* format);

int	ft_printf(const char*	format, ...) //printf로 출력하다가 안되면 -1 출력
{
	va_list	ap;

	va_start(ap, format);
	while (*format)
	{
		if (compare_format(format))
		{
			if (*(format + 1) == 's')
				format = ft_printf_s(ap, format);

		}
		else
		{
			write(1, format, 1);
			format++;
		}
	}
	va_end(ap);

	return (0);
}

int		compare_format(const char* format)
{
	if (ft_strncmp(format, "%s", 2) == 0)
		return (1);
	else if (ft_strncmp(format, "%c", 2) == 0)
		return (1);
	else if (ft_strncmp(format, "%p", 2) == 0)
		return (1);
	else if (ft_strncmp(format, "%d", 2) == 0)
		return (1);
	else if (ft_strncmp(format, "%i", 2) == 0)
		return (1);
	else if (ft_strncmp(format, "%u", 2) == 0)
		return (1);
	else if (ft_strncmp(format, "%x", 2) == 0)
		return (1);
	else if (ft_strncmp(format, "%X", 2) == 0)
		return (1);
	else if (ft_strncmp(format, "%%", 2) == 0)
		return (1);
	else
		return (0);
}

const char*	ft_printf_s(va_list	ap, const char*	format)
{
	char*	str;
	
	str = va_arg(ap, char*);
	while (*str)
	{
		write(1, &str, 1);
		str++;
	}
	format = format + 2;
	return (format);
}

#include <stdio.h>
int	main(void)
{
	ft_printf("name = %s\n", "tom");
	printf("name = %s\n", "tom");
	//printf(" number : %d\n", 1);
	return (0);
}