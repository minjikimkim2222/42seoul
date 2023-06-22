#include "ft_printf.h"

static int ft_putnbr_recursive(int n, int *length)
{
	char remainder;

    if (n < 0)
    {
        if (write(1, "-", 1) == -1)
            return (-1);
        (*length)++;
        n = -n;
    }
    if (n >= 10)
    {
        if (ft_putnbr_recursive(n / 10, length) == -1)
            return (-1);
    }
	remainder = (n % 10) + '0';
    if (write(1, &remainder, 1) == -1)
    	return (-1);
    (*length)++;
    return (*length);
}

int	ft_putnbr(int n)
{
	int	length;

	length = 0;
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		length = 11;
	}
	else
	{
		length = length + ft_putnbr_recursive(n, &length);
	}
	return (length);
}
