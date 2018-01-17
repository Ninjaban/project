/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <mmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:28:27 by mmarchan          #+#    #+#             */
/*   Updated: 2014/04/16 19:56:32 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*save;
	size_t	len;

	if (size == 0)
		return (0);
	save = ft_memchr(dst, '\0', size);
	if (save == NULL)
		return (size + ft_strlen(src));
	len = save - dst + ft_strlen(src) + 1;
	if (len >= size)
		len = size - 1;
	ft_memcpy(save, src, len - (size_t)(save - dst));
	dst[len] = '\0';
	return (save - dst + ft_strlen(src));
}
