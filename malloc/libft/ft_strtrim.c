/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <mmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 17:05:31 by mmarchan          #+#    #+#             */
/*   Updated: 2014/04/16 20:05:08 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

static int	is_white(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	char	*ret;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (is_white(s[i]))
		s++;
	while (s[i])
		i++;
	while (i-- > 0 && is_white(s[i]))
		;
	ret = ft_strsub(s, 0, i + 1);
	if (ret)
	{
		return (ret);
	}
	return (NULL);
}
