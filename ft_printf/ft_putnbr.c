#include "ft_printf.h"
#include <stdio.h> // <<<<<<<<<  나중에 수정

int	ft_printf_d_i(va_list ap)
{
	int	n;
	int	length;

	n = va_arg(ap, int);
	length = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		length = 11;
	}
	else
	{
		length = length + ft_putnbr(n, &length); 
	}
	return (length);
}

int	ft_putnbr(int n, int* length)
{
	char	share;
	char	remainder;

	if (n < 0)
	{
		write(1, "-", 1);
		(*length)++;
		n = n * (-1);
	}
	if (n >= 0 && (n / 10) == 0)
	{
		n = n + '0';
		write(1, &n, 1);
		(*length)++;
	}
	else
	{
		share = (n / 10) + '0';
		remainder = (n % 10) + '0';
		n = n / 10;
		ft_putnbr(n, length);
		write(1, &remainder, 1);
		(*length)++;
	}
	return (int)(*length);
}

int	ft_printf_u(va_list ap)
{
	unsigned int	num;
	int				length;

	num = va_arg(ap, int);
	length = ft_putnbr_u(num, &length);
	return (length);
}

int	ft_putnbr_u(unsigned int n, int* length)
{
	char	c;

	printf("\nft_putnbr_u : %d, %u\n", n,n);
	if (n == 0)
	{
		return (0);
	}
	else
	{
		ft_putnbr_u(n / 10, length);
		c = (n % 10) + '0';
		write(1, &c, 1);
		(*length)++;
	}
	return (*length);
}