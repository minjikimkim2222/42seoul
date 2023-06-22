#include "ft_printf.h"

static int ft_printf_process(const char *str, va_list *ap)
{
    int length;
	int	write_ret;

	length = 0;
    while (*str != '\0')
    {
        if (*str == '%')
        {
            write_ret = ft_printf_format_check(ap, *(str + 1));
            if (write_ret == -1)
                return (-1);
            length += write_ret;
            str += 2; // 형식 문자와 % 다음 문자 건너뛰기
        }
        else
        {
            write_ret = ft_putchar(*str);
            if (write_ret == -1)
                return (-1);
            length += write_ret;
            str++;
        }
    }
    return (length);
}

int ft_printf(const char *str, ...)
{
    int length;
    va_list ap;

    length = 0;
    va_start(ap, str);
    length = ft_printf_process(str, &ap);
    va_end(ap);
    return length;
}
