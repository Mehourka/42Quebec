unsigned int	str_len(char *str);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (str_len(src));
}

unsigned int	str_len(char *str)
{
	unsigned int i = 0;

	while (str[i])
		i++;
	return (i);
}
