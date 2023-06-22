#include "ft_printf.h"

static int	ft_strlen(const char *s)
{
	int	len;
	
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_putstr(char *s)
{
	if (s == NULL)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}
