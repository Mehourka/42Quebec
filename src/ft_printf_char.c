#include <unistd.h>

int ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}


int ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while(str[i])
		write(1, &str[i++], 1);
	return (i);
}
