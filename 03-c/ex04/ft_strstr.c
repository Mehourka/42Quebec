int	my_strncmp(char *s1, char *s2, unsigned int n);
int str_len(char *str);
#include <stdio.h>
char	*ft_strstr(char *str, char *to_find)
{
	int needle_len;
	int hay_len;
	int i;
	i = 0;
	hay_len = str_len(str);
	needle_len = str_len(to_find);


	// printf("hay: %i\nneedle %i", hay_len, needle_len);


	while(i <= (hay_len - needle_len))
	{
		if (my_strncmp(&str[i], to_find, (unsigned int)needle_len) == 0)
			return (&str[i]);
		i++;
	}
	return ((void *)0);
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

int	my_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;



	// printf("Comparing '%s' to '%s' with n=%i", s1, s2, n);


	i = 0;
	while (s1[i] && s2[i] && i < (n - 1))
	{
		if (s1[i] != s2[i])
		{
			break;
		}
		i++;
	}

	if (s1[i] == s2[i])
		return (0);
	else if (s1[i] > s2[i])
		return (1);
	else
		return (-1);
}
