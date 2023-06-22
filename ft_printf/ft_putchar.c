#include "ft_printf.h"

int	ft_putchar(char c)
{
	int write_ret;

	write_ret = write(1, &c, 1);
	return (write_ret);
}
