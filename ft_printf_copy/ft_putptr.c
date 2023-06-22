#include "ft_printf.h"

static int	ptr_int_hex(unsigned long long n, int	*length)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n < 16)
	{
		write(1, hex + n, 1);
		(*length)++;
	}
	else
	{
		ptr_int_hex(n / 16, length);
		write(1, hex + (n % 16), 1);
		(*length)++;
	}
	return ((*length));
}

int	ft_putptr(unsigned long long str)
{
	int		length;

	write(1, "0x", 2);
	length = 2;
	length = ptr_int_hex(str, &length);
	return (length);
}


