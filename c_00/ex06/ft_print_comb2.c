#include <unistd.h>

void	format_2digits(int n);

void	ft_print_comb2(void)
{
	int	i;
	int	j;
	int	max = 99;

	i = 0;
	while (i <= max)
	{
		j = i + 1;
		while (j <= max)
		{
			format_2digits(i);
			write (1, " ", 1);
			format_2digits(j);
			if (i < (max - 1))
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}

void	format_2digits(int n)
{
	char	str[2];
	int		i;

	i = 1;
	while (i >= 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	write(1, str, 2);
}
