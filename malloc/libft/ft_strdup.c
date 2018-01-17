/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <mmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:22:21 by mmarchan          #+#    #+#             */
/*   Updated: 2014/04/16 19:54:39 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strdup(const char *s1)
{
	char	*save;
	int		len;
	int		count;

	len = ft_strlen(s1);
	count = -1;
	if ((save = (char *)malloc(sizeof(*save) * (len + 1))) == (NULL))
		return (NULL);
	while (++count < len)
		save[count] = s1[count];
	save[count] = 0;
	return (save);
}
