/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <mmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:35:45 by mmarchan          #+#    #+#             */
/*   Updated: 2014/04/16 20:01:02 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 != '\0' && n > 0)
	{
		if (ft_strlen(s2) > n)
			return (NULL);
		if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0)
			return ((char *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
