int str_len(char *str);

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int j;

	// i points to dest tail
	i = str_len(dest);
	// j points to str strat
	j = 0;
	while(src[j] && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	// Add NUL-character ??
	// dest[i] = '\0';
	return (dest);
}

int str_len(char *str)
{
	int	i;

	int = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
