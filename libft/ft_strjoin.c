/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:48:37 by kmehour           #+#    #+#             */
/*   Updated: 2023/02/05 19:48:12 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	dest_size;
	char	*dest;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest_size = s1_len + s2_len + 1;
	dest = (char *)malloc(dest_size);
	if (!dest)
		return (NULL);
	ft_memcpy(dest, s1, s1_len);
	ft_memcpy((dest + s1_len), s2, (s2_len + 1));
	return (dest);
}
