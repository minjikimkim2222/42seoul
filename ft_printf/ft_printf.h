#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_putunbr(unsigned int nb);
int	ft_printf_format_check(va_list *ap, const char format);
int	ft_puthex(unsigned int num, char c);
int	printf_x(unsigned int n, int	*length, char c);
int	ft_putptr(unsigned long long nb);

#endif
