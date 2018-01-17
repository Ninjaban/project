/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <mmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 09:31:05 by mmarchan          #+#    #+#             */
/*   Updated: 2014/04/16 19:57:38 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*save;
	int		count;

	count = 0;
	save = NULL;
	if (s != NULL)
	{
		save = ft_strnew(ft_strlen(s));
		ft_strcpy(save, s);
		while (save[count] != '\0')
		{
			save[count] = f(save[count]);
			count++;
		}
	}
	return (save);
}
