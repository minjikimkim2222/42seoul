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
#include <stdio.h> // <--------- 나중에 뺄 것

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
		length = length + ft_printf_s(ap);
	else if ((*format) == 'c')
		length = length + ft_putchar(va_arg(ap, int));
	else if ((*format) == 'd' || *(format) == 'i')
		length = length + ft_printf_d_i(ap);
	else if (*(format) == 'p')
		length = length + ft_printf_p(ap);
	else if (*(format) == 'u')
		length = length + ft_printf_u(ap);
	// else if (ft_strncmp(format, "%x", 2) == 0)
	// 	return (1);
	// else if (ft_strncmp(format, "%X", 2) == 0)
	// 	return (1);
	else if (*(format) == '%')
	{
		write(1, "%", 1);
		length++;
	}
	return (length);
}

int	ft_printf_s(va_list	ap)
{
	char*	str;
	int length;
	char*	p;

	str = va_arg(ap, char*);
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
// ///#include <stdio.h>
int	main(void)
{
	/*
	1. %s, %c 테스트 예제.
	*/
	// int ret1 = 0;
	// int ret2 = 0;
	// char *s1 = NULL;


	// ret1 = ft_printf("is it right? => %s %s\n", s1, s1);
	// ret2 = printf("is it rigth? => %s %s\n", s1, s1); //(null)\n <- 이렇게 7개 리턴값
	// printf("ret1 : %d, ret2 : %d\n", ret1, ret2);


	/*
	2. %d, %i 테스트 예제.
	n = 123, -123, -2147483648, ... test 필요
	*/
	// int num1 = 122222;
	// printf("num1 : %d\n", num1);
	// ft_printf("num1 : %d\n", num1);

	// int ret1 = printf("isit_num1 : %d\n", num1);
	// int ret2 = ft_printf("isit_num1 : %d\n", num1);
	// printf("리턴값 비교 : printf : %d, ft_printf : %d\n", ret1, ret2);

	//int num = 4294967295; <- unsigned int 최대값, 
	// ->>>>>>>>>>>%u -> ft_putnbr_u 부분에서 최대 최소 + 재귀 부분 조건 수정 need

	// printf %p 시험
	// int i = 10;
	// printf("main1 : %p\n", &i);
	// ft_printf("main2 : %p\n", &i);

	/*
	printf -> %u 예제
	unsigned int num2 = 4294967296;
	
	int ret1 = printf("printf : %u\n", num2);
	int ret2 = ft_printf("ft_printf : %u\n", num2);

	printf("printf ret1 : %d, ft_printf ret2 : %d\n", ret1, ret2);

	*/

	// printf -> %x 예제 <<<<<<<<<<< 이거 할 차례


	
	

	/*
	출력
	*/
	// int* ptr_l = &i;
	// printf("<2> percept p : %p\n", ptr_l);
	// ft_printf("ft_<2> percept p : %p\n", ptr_l);

	// print a number in 16진수, with lowercase
	// print  a number in 16진수, with lowercase

	
	return (0);
}