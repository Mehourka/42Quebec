#include <stdio.h>


unsigned int str_len(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;

	// i points to dest tail
	i = str_len(dest);
	// j points to str strat
	j = 0;
	while(src[j] && i < (size - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (str_len(src));
}

unsigned int str_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

// int main(void)
// {
// 		char dest[15] = "Quebec ";
// 	printf("%i : %s\n",
// 		ft_strlcat(dest, "42\nNOTTHIS", sizeof(dest)),
// 		dest
// 	);
// }
