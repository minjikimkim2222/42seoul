/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:18:50 by minjiki2          #+#    #+#             */
/*   Updated: 2023/06/21 15:21:34 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf(const char	*format, ...)
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

int	ft_printf_format(const char	*format, va_list ap)
{
	int	length;

	length = 0;
	if ((*format) == 's')
		length = length + ft_printf_s(ap);
	else if ((*format) == 'c')
		length = length + ft_putchar(va_arg(ap, int));
	else if ((*format) == 'd' || *(format) == 'i')
		length = length + ft_printf_d_i(ap);
	else if (*(format) == 'p')
		length = length + ft_printf_p(ap);
	else if (*(format) == 'u')
		length = length + ft_printf_u(ap);
	else if ((*format) == 'x' || *(format) == 'X')
		length = length + ft_printf_x(ap, *(format));
	else if (*(format) == '%')
	{
		write(1, "%", 1);
		length++;
	}
	return (length);
}

int	ft_printf_x(va_list ap, char c)
{
	int	num;
	int	length;

	length = 0;
	num = va_arg(ap, int);
	length = printf_x((unsigned int)num, &length, c);
	return (length);
}

int	ft_printf_s(va_list	ap)
{
	char	*str;
	int		length;
	char	*p;

	str = va_arg(ap, char *);
	length = 0;
	if (str == NULL)
	{
		p = "(null)";
		while (p[length])
			length += ft_putchar(p[length]);
		return (length);
	}
	while (*str)
	{
		length = length + ft_putchar(*str);
		str++;
	}
	return (length);
}
