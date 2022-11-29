int str_len(char *str);

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	// i points to dest tail
	i = str_len(dest);
	// j points to str strat
	j = 0;
	while(src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
