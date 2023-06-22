#include "ft_printf.h"

static int	ft_putnbr_u(unsigned int n, int *length)
{
	char	c;

	if (n <= 9)
	{
		c = n + '0';
		(*length)++;
		return (write(1, &c, 1));
	}
	else
	{
		if (ft_putnbr_u(n / 10, length) == -1)
			return (-1);
		if (ft_putnbr_u(n % 10, length) == -1)
			return (-1);
	}
	return (*length);
}

int	ft_putunbr(unsigned int num)
{
	int	length;

	length = 0;
	length = ft_putnbr_u(num, &length);
	return (length);
}
