#include <stdio.h>
#include <unistd.h>

int ft_strcmp(char *s1, char *s2) __attribute__((weak));
int	ft_strncmp(char *s1, char *s2, unsigned int n) __attribute__((weak));

int main(void)
{
	// Exercice 00
	if (ft_strcmp)
	{
		int result = ;
		printf("%i",
			ft_strcmp("abc1", "abc2")
		);
	}

		// Exercice 01
	if (ft_strncmp)
	{
		printf("%i",
			ft_strncmp("ABC2", "ABC1", 4)
		);
	}
}
