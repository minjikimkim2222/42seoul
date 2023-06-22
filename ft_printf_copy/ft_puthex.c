#include "ft_printf.h"

int	ft_puthex(unsigned int num, char c)
{
	int	length;

	length = 0;
	length = printf_x((unsigned int)num, &length, c);
	return (length);
}

int	printf_x(unsigned int n, int	*length, char c)
{
	char	*hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n < 16)
	{
		write(1, hex + n, 1);
		(*length)++;
	}
	else
	{
		printf_x(n / 16, length, c);
		write(1, hex + (n % 16), 1);
		(*length)++;
	}
	return ((*length));
}