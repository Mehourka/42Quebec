# include <unistd.h>
# include <stdio.h>
# include "lib/ft_printf.h"

int	ft_numlen_hex(unsigned num)
{
	int	l;

	l = 1;
	if (num < 0)
		l++;
	while (num / 16)
	{
		num /= 16;
		l++;
	}
	return (l);
}

int	ft_putnbr_base(long n, char* base)
{
	long	nb;
	char	c;

	nb = n;
	if (nb < 0)
	{
		nb *= (-1);
		ft_putchar('-');
	}
	c = base[nb % 16];
	if (nb > 15)
		ft_putnbr_base(nb/16, base);
	write(1, &c, 1);
	return ft_numlen_hex(n);
}

int	ft_puthex(int n, int ucase)
{
	char*		base;
	char*		prefix;
	unsigned	nb;

	nb = n;
	base = "0123456789abcdef";
	if (ucase)
		base = "0123456789ABCDEF";
	return ft_putnbr_base(nb, base);
}

int	ft_putptr(int n)
{
	char*	prefix;
	int		count;

	prefix = "0x";
	count = 2;
	ft_putstr(prefix);
	count += ft_puthex(n, 0);
	return count;
}
