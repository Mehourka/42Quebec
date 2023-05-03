/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:44:21 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/03 17:31:49 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// Returns the lenghts of a char *str
int	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

// Search for char in char *str
// returns index if found, else returns -1.
int	ft_strichr(char const *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

// Joins two strings into a new malloc'd one
char	*ft_strjoin(char *str1, char *str2)
{
	char	*joined;
	int		i;
	int		tot_size;
	int		j;

	i = 0;
	j = 0;
	if (!str1)
	{
		str1 = malloc(sizeof(char));
		if (!str1)
		{
			return (NULL);
		}
		str1[0] = '\0';
	}
	tot_size = ft_strlen(str1) + ft_strlen(str2) + 1;
	joined = (char *)malloc(tot_size * sizeof(char));
	if (!joined)
	{
		free(str1);
		return (NULL);
	}
	while (str1 && str1[j])
		joined[i++] = str1[j++];
	j = 0;
	while (str2 && str2[j])
		joined[i++] = str2[j++];
	joined[i] = '\0';
	free(str1);
	return (joined);
}
