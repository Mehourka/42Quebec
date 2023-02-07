/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:54:00 by kmehour           #+#    #+#             */
/*   Updated: 2023/02/05 19:47:06 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/* The strdup() function allocates sufficient memory for a copy of the
string s1, does the copy, and returns a pointer to it.  The pointer may
subsequently be used as an argument to the function free(3).

If insufficient memory is available, NULL is returned and errno is set to
ENOMEM.

The strndup() function copies at most n characters from the string s1
always NUL terminating the copied string. */
char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	return (str);
}
