/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmehour <kmehour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:45:07 by kmehour           #+#    #+#             */
/*   Updated: 2023/01/17 11:10:49 by kmehour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*destination;

	if (!dst)
		return (NULL);
	destination = (unsigned char *) dst;
	source = (unsigned char *) src;
	if (n == 0 || dst == src || !src || !dst)
		return (dst);
	while (n--)
		*destination++ = *source++;
	return (dst);
}
