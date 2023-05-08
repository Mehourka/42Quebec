#include "libft.h"

char *ft_strjoin(const char *str1, const char *str2)
{
	char *new_string;
	size_t len_str1;
	size_t len_str2;

	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	new_string = malloc(len_str1 + len_str2 + 1);
	if (!new_string)
		return (NULL);
		
	new_string[len_str1 + len_str2] = '\0';

	ft_memcpy(new_string, (void *)str1, len_str1);
	ft_memcpy((new_string + len_str1), (void *) str2, len_str2);

	return (new_string);
}