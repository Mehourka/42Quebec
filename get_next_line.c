/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:44:22 by kmehour           #+#    #+#             */
/*   Updated: 2023/05/03 17:07:32 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*load(int fd, char *cache)
{
	int			ret;
	char		*buff;

	ret = BUFFER_SIZE;
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (ft_strichr(cache, '\n') < 0 && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		buff[ret] = '\0';
		cache = ft_strjoin(cache, buff);
	}
	free(buff);
	return (cache);
}

static char	*get_line(char *cache)
{
	char	*next_line;
	int i;

	i = 0;
	// get all chars before \n in a new char*
	if (!cache || !cache[0])
		return NULL;
	
	while(cache[i] && cache[i - 1] != '\n')
		i++;
	next_line = malloc(i * sizeof(char) + 1);
	next_line[i--] = '\0';
	while(i >= 0)
	{
		next_line[i] = cache[i];
		i--;
	}
	return(next_line);
}

static char	*prune(char *cache)
{
	int		i;
	int		j;
	char	*pruned;

	i = 0;
	j = 0;
	
	// get all chars before \n in a new char*
	if (!cache || !cache[0])
	{
		return NULL;
	}
	
	while(cache[i] && cache[i] != '\n')
		i++;
	
	if (cache[i] == '\n')
		i++;
		
	pruned = malloc((ft_strlen(cache + i) + 1) * sizeof(char));
	

	while(cache[i])
		pruned[j++] = cache[i++];
	
	free(cache);
	return pruned;
}

char	*get_next_line(int fd)
{
	char static	*cache;
	char		*next_line;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// load
	cache = load(fd, cache);
	// printf("\n\nCache : %s\n", cache);
	// get line
	next_line = get_line(cache);
	// printf("Next line : %s\n", next_line);
	// prune
	cache = prune(cache);

	// printf("Next line : %s \n", next_line);
	// printf("Pruned Cache : %s \n\n", cache);
	return (next_line);

}
