#include <stdio.h>
#include <unistd.h>

int ft_strcmp(char *s1, char *s2) __attribute__((weak));


int main(void)
{
	// Exercice 0
	if (ft_strcmp)
	{
		int result = ft_strcmp("a", "b");
		printf("%i", result);
	}

}
