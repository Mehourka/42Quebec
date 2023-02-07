/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:35:44 by kmehour           #+#    #+#             */
/*   Updated: 2023/02/05 19:56:07 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

int	count_chunks(char const *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] != c)
			&& (i == 0 || str[i - 1] == c))
		{
			count++;
			while (str[i] == c)
				i++;
		}
		i++;
	}
	return (count);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	size_t	len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	if (n < len)
		len = n;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, len + 1);
	return (str);
}

int	word_len(char const *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && (str[len] != c))
		len++;
	return (len);
}

char	*get_chunk(char const *str, char c)
{
	int		len;
	char	*new_str;

	len = word_len(str, c);
	new_str = ft_strndup(str, len);
	return (new_str);
}

char	**ft_split(char const *str, char c)
{
	int		word_count;
	char	**tab;
	int		i;
	int		j;

	word_count = count_chunks(str, c);
	tab = NULL;
	tab = (char **) malloc(sizeof(char *) * (word_count + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] && (str[i] != c)
			&& (i == 0 || str[i - 1] == c))
		{
			tab[j++] = get_chunk(&str[i], c);
			i += word_len(&str[i], c);
		}
		else
			i++;
	}
	tab[j] = 0;
	return (tab);
}
