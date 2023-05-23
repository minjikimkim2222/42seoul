#include "ft_printf.h"

int	ft_printf_p(va_list ap)
{
	char*	str;
	int		length;

	str = (char*)va_arg(ap, void *);
	write(1, "0x", 2);
	length = 2;
	length = ptr_int_hex((unsigned long long)str, &length);
	return (length);
}

int	ptr_int_hex(unsigned long long int n, int* length)
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
		write(1, hex + (n%16), 1);
		(*length)++;
	}
	return ((*length));
}

int	printf_x_X(unsigned int n, int* length, char c)
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
		printf_x_X(n / 16, length, c);
		write(1, hex + (n%16), 1);
		(*length)++;
	}
	return ((*length));
}