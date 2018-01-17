/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <mmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:29:56 by mmarchan          #+#    #+#             */
/*   Updated: 2014/04/16 19:43:03 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*dst;
	const char	*src;

	i = 0;
	dst = s1;
	src = s2;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
