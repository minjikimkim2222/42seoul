/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 20:20:37 by minjiki2          #+#    #+#             */
/*   Updated: 2023/04/22 20:20:45 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int	ft_putnbr(int n, int *length);
int	ft_printf_s(va_list	ap);
int	ft_putchar(char c);
int	ft_printf_format(const char *format, va_list ap);
int	ft_printf_d_i(va_list ap);
int	ft_printf_p(va_list ap);
int	ptr_int_hex(unsigned long long int n, int	*length);
int	ft_printf_u(va_list ap);
int	ft_putnbr_u(unsigned int n, int	*length);
int	ft_printf_x(va_list ap, char c);
int	printf_x(unsigned int n, int *length, char c);

#endif