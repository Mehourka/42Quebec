int validate_base(char *base)
{
	//check that base is at least size 2 and of unique characters != +/-
	// returns the base (size) as int
	int size;
	int i;
	int j;

	size = 0;
	while(base[size])
		size++;
	if (size <= 1)
		return (0);

	i = 0;
	while(i < size - 1)
	{
		j = i + 1;
		while(j < size)
		{
			if (base[i] == base[j] || base[j] == '+' || base[j] == '-')
				return (0);
			j++;
		}
	i++;
	}
	return (size);
}

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

int number_len(char *str, char *base)
{
	int i;
	int j;
	int valid;

	i = 0;
	while(str[i])
	{
		j = 0;
		valid = 0;
		while(base[j])
		{
			if (str[i] == base[j])
				valid++;
			j++;
		}
		if (!valid)
			return (i);
		i++;
	}
	return (i);
}

int decimal(char n, char *base)
{
	int i;

	i = 0;
	while(base[i])
	{
		if (base[i] == n)
			return i;
		i++;
	}
	return -1;
}


#include <stdio.h>

int ft_atoi_base(char *str, char *base)
{
	int signe;
	int num_len;
	int i;
	int result;
	char *new_str;
	int base_int;


	i = 0;
	signe = 1;
	result = 0;
	new_str = skip_spaces(str);
	new_str = get_signe(new_str, &signe);
	num_len = number_len(new_str, base);

	base_int = validate_base(base);

	while (i < num_len)
	{
		result += decimal(new_str[num_len - 1 -i], base) * power(base_int, i);
		i++;
	}
	return (signe * result);

}

#include <unistd.h>

#include<stdio.h>
int main(void)
{
	// char *bin = "01";
	// char *hexa = "0123456789abcdef";
	char *octa = "01234567";
	// char *err1 = "0";
	// char *err2 = "11";
	// char *err3 = "12+";
	printf("%i\n", ft_atoi_base("12", octa));

}
