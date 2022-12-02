int ft_iterative_power(int nb, int power)
{
	int i;
	int result;

	i = 0;
	result = 1;

	if (power < 0)
		return 0;

	while(i < power)
	{
		result *= nb;
		i++;
	}
	return (result);
}

#include <stdio.h>
int main(void)
{
	printf("%i\n", ft_iterative_power(5,-1));
}
