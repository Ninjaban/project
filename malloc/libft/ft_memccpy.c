/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <mmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:10:42 by mmarchan          #+#    #+#             */
/*   Updated: 2014/04/16 19:41:04 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char			*dst;
	const char		*src;
	unsigned char	save;

	dst = s1;
	src = s2;
	save = 0;
	while (n > 0)
	{
		save = *src++;
		*dst++ = save;
		if (save == (unsigned char)c)
			return (dst);
		n--;
	}
	return (NULL);
}
