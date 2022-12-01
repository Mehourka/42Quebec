char *skip_spaces(char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == ' ')
	{
		str++;
	}
	return (str);
}

char *get_signe(char *str, int *signe)
{
	while(*str == '+' || *str == '-')
	{
		if(*str == '-')
			*signe *= -1;
		str++;
	}
	return (str);
}

int power(int base, int exp)
{
	int i;
	int result;

	i = 0;
	result = 1;
	while(i < exp)
	{
		result *= base;
		i++;
	}
	return (result);
}

int number_len(char *str)
{
	int i;

	i = 0;
	while(str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}


int ft_atoi(char *str)
{
	int signe;
	int num_len;
	int i;
	int result;
	char *new_str;

	i = 0;
	signe = 1;
	result = 0;
	new_str = skip_spaces(str);
	new_str = get_signe(new_str, &signe);
	num_len = number_len(new_str);
	while (i < num_len)
	{
		result += (new_str[num_len - 1 -i] - '0') * power(10, i);
		i++;
	}
	return (signe * result);
}

/*
#include <stdio.h>
#include <unistd.h>
int main(void)
{
	char str[] = "  \n --++-123456r12";
	printf("%i\n", ft_atoi(str));
}
*/

