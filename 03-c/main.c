#include <stdio.h>
#include <unistd.h>

int ft_strcmp(char *s1, char *s2) __attribute__((weak));
int	ft_strncmp(char *s1, char *s2, unsigned int n) __attribute__((weak));
char	*ft_strcat(char *dest, char *src) __attribute__((weak));
char	*ft_strncat(char *dest, char *src, unsigned int nb) __attribute__((weak));


int main(void)
{
	// Exercice 00
	if (ft_strcmp)
	{
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

	// Exercice 02
	if (ft_strcat)
	{
		char dest[10] = "Quebec ";
		printf("%s",
			ft_strcat(dest, "42\n")
		);
	}

	// Exercice 03
	if (ft_strncat)
	{
		char dest[20] = "Quebec ";
		printf("%s",
			ft_strncat(dest, "42\nNOPE\n", 3)
		);
	}


}
