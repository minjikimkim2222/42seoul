#include "ft_printf.h"

int ft_printf_format_check(va_list *ap, const char format)
{
    int length = 0;

    if (format == 'c')
        length += ft_putchar(va_arg(*ap, int));
    else if (format == 's')
        length += ft_putstr(va_arg(*ap, char *));
    else if (format == 'p')
        length += ft_putptr(va_arg(*ap, unsigned long long));
    else if (format == 'd' || format == 'i')
        length += ft_putnbr(va_arg(*ap, int));
    else if (format == 'u')
        length += ft_putunbr(va_arg(*ap, unsigned int));
    else if (format == 'x' || format == 'X')
        length += ft_puthex(va_arg(*ap, unsigned int), format);
    else if (format == '%')
        length += write(1, "%", 1);
    if (length == -1) // write함수 에러 확인용
        return (-1);
    return (length); //write 에러 안 나면 길이 리턴
}


