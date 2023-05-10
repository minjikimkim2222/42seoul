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

//최종적으로 makefile 실행되는지 점검
#include "ft_printf.h"
#include <stdio.h>

int	ft_printf_s(va_list	ap, const char*	format);
int	ft_putchar(char c);
int		ft_printf_format(const char* format, va_list ap);

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf(const char*	format, ...) //리턴값 : 출력 성공 -> 문자열의 길이, 실패 : -1
{
	va_list	ap;
	int		length;

	va_start(ap, format);
	length = 0;
	while (*format)
	{
		if ((*format) == '%')
		{
				length = length + ft_printf_format(format + 1, ap);
				format = format + 2;
		}
		else
		{
			length += ft_putchar(*format);
			format++;
		}
	}
	va_end(ap);
	return (length);
}

int		ft_printf_format(const char* format, va_list ap)
{
	int length;

	length = 0;
	if ((*format) == 's')
		length = length + ft_printf_s(ap, format);
	else if ((*format) == 'c')
		length = length + ft_putchar(va_arg(ap, int));
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
	return (length);
}

int	ft_printf_s(va_list	ap, const char*	format)
{
	char*	str;
	int length;

	str = va_arg(ap, char*);
	length = 0;
	while (*str)
	{
		length = length + ft_putchar(*str);
		str++;
	}
	return (length);
}

///#include <stdio.h>
int	main(void)
{
	int ret1 = 0, ret2 = 0;
	ret1 = ft_printf("character = %c\n", 'a');
	ret2 = printf("character = %c\n", 'a');
	printf("ret1 : %d\n", ret1);
	printf("ret2 : %d\n", ret2);
	//printf(" number : %d\n", 1);
	return (0);
}