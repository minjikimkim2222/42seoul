#include "ft_printf.h"

static int	ft_putnbr_recursive(int n, int *length)
{
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
		remainder = (n % 10) + '0';
		n = n / 10;
		ft_putnbr_recursive(n, length);
		write(1, &remainder, 1);
		(*length)++;
	}
	return ((int)(*length));
}

int	ft_putnbr(int n)
{
	int	length;

	length = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		length = 11;
	}
	else
	{
		length = length + ft_putnbr_recursive(n, &length);
	}
	return (length);
}
