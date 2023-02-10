/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:35:44 by kmehour           #+#    #+#             */
/*   Updated: 2023/02/09 20:41:22 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	count_chunks(char const *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	**free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static char	**split(char **tab, char const *str, int word_count, char c)
{
	int		i;
	int		j;
	int		pin;

	i = 0;
	j = 0;
	while (j < word_count)
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			pin = i;
		while (str[i] && str[i] != c)
			i++;
		if (pin != i)
			tab[j] = ft_substr((char *)str, pin, (i - pin));
		if (!tab[j++])
			return (free_tab(tab));
	}
	return (tab);
}

char	**ft_split(char const *str, char c)
{
	int		word_count;
	char	**tab;

	if (!str)
		return (NULL);
	word_count = count_chunks(str, c);
	tab = NULL;
	tab = (char **) malloc(sizeof(char *) * (word_count + 1));
	if (!tab)
		return (NULL);
	tab[word_count] = NULL;
	return (split(tab, str, word_count, c));
}
