/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <mmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 09:44:09 by mmarchan          #+#    #+#             */
/*   Updated: 2014/04/16 19:58:01 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*save;
	unsigned int	count;

	count = 0;
	save = NULL;
	if (s != NULL)
	{
		save = ft_strnew(ft_strlen(s));
		ft_strcpy(save, s);
		while (save[count] != '\0')
		{
			save[count] = f(count, save[count]);
			count++;
		}
	}
	return (save);
}
