#include "ft_printf.h"

int	ft_printf_format(va_list *ap, const char format)
{
	int length;

	length = 0;
	if (format == 'c')
		length += ft_putchar(va_arg(*ap, int));
	if (format == 's')
		length += ft_putstr(va_arg(*ap, char *));
	if (format == 'p')
		length += ft_putptr(va_arg(*ap, unsigned long long));
	if (format == 'd' || format == 'i')
		length += ft_putnbr(va_arg(*ap, int));
	if (format == 'u')
		length += ft_putunbr(va_arg(*ap, unsigned int));
	if (format == 'x' || format == 'X')
		length += ft_puthex(va_arg(*ap, unsigned int), format);
	if (format == '%')
		length += write(1, "%", 1);
	return (length);
}
