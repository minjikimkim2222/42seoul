#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		idx;
	int		length;
	va_list	ap;

	idx = 0;
	length = 0;
	va_start(ap, str);
	while (str[idx] != '\0')
	{
		if (str[idx] == '%')
		{
			length += ft_printf_format(&ap, str[idx + 1]);
			idx++;
		}
		else
			length += ft_putchar(str[idx]);
		idx++;
	}
	va_end(ap);
	return (length);
}
