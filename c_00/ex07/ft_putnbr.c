#include <unistd.h>

void reverse_print(char *str, int i);

void ft_putnbr(int nb){

	char str_num[10];
	int i;

	if (nb == 0)
		write(1, "0", 1);

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = - nb;
	}

	i = 0;
	while (nb > 0)
	{
		str_num[i] = nb % 10 + '0';
		nb = nb / 10;
		i++;
	}

	reverse_print(str_num, i);
}

void reverse_print(char *str, int size)
{
	int i;

	i = size - 1;
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
}


