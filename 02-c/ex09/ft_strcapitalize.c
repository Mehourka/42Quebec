char	*ft_strlowcase(char *str)
{
	int	i;

	// Return empty string
	if (str[0] == '\0')
		return (str);
	// If first char is lowercase make it upper
	if (str[0]>= 'a' && str[0] <= 'z')
		str[0] += ('A' - 'a');
	//Transform the rest to lowercase
	i = 1;
	while (str[i])
	{
		if (i == 0 && str[i]>= 'A' && str[i] <= 'Z')
		if (str[i]>= 'A' && str[i] <= 'Z')
			str[i] += ('a' - 'A');
		i++;
	}
	return (str);
}
