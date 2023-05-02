# include <unistd.h>
# include <stdio.h>
# include "ft_printf.h"

int	ft_numlen_hex(unsigned long num)
{
	int	l;

	l = 1;
	while (num / 16)
	{
		num /= 16;
		l++;
	}
	return (l);
}

int	ft_putnbr_base(unsigned long n, char* base)
{
	long unsigned	nb;
	char	c;

	nb = n;
	c = base[nb % 16];
	if (nb > 15)
		ft_putnbr_base(nb/16, base);
	write(1, &c, 1);
	return ft_numlen_hex(n);
}

int	ft_puthex(unsigned long n, int ucase)
{
	char*		base;
	char*		prefix;

	base = "0123456789abcdef";
	if (ucase)
		base = "0123456789ABCDEF";
	return ft_putnbr_base(n, base);
}

int	ft_putptr(unsigned long n)
{
	char*	prefix;
	int		count;

	if (!n)
	{
		ft_putstr("(nil)");
		return (5);
	}
	prefix = "0x";
	count = 2;
	ft_putstr(prefix);
	count += ft_puthex(n, 0);
	return count;
}
