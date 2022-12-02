int ft_iterative_factorial(int nb)
{
	int result;

	result = 1;
	while(nb > 1)
	{
		result *= nb;
		nb--;
	}
	return (result);
}

#include <stdio.h>
int main(void)
{
	printf("%i\n", ft_iterative_factorial(5));
}
