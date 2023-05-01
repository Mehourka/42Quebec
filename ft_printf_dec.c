# include <unistd.h>
# include <stdio.h>

int	ft_numlen_dec(int num)
{
	int l;

	l = 1;
	if (num < 0)
		l++;
	while (num / 10)
	{
		num /= 10;
		l++;
	}
	return l;
}

int	ft_putnbr(int n)
{
	long nb;
	char c;

	nb = n;
	if (nb < 0)
	{
		nb *= (-1);
		write(1, "-", 1);
	}
	c = '0' + nb % 10;
	if (nb > 9)
		ft_putnbr(nb/10);
	write(1, &c, 1);
	return ft_numlen_dec(n);
}
