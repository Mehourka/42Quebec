#include <unistd.h>
#include <stdio.h>

void print_hexa(int n);

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		// If character is printable
		if (str[i] >= 32)
			write(1, &str[i], 1);
		else
		{
			print_hexa(str[i]);
		}
		i++;
	}
}

void print_hexa(int n)
{
	char	hexa_char[2];
	int	i;
	int mod;

	i = 0;
	while (i < 2)
	{
		mod = n % 16;
		if (mod < 10)
			hexa_char[i] = mod + '0';
		else
			hexa_char[i] = mod - 10 + 'a';
		n = n / 16;
		i++;
	}

	write(1, "\\", 1);
	write(1, &hexa_char[1], 1);
	write(1, &hexa_char[0], 1);
}
