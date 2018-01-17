/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <mmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 16:47:53 by mmarchan          #+#    #+#             */
/*   Updated: 2014/04/16 19:45:09 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*save;

	i = 0;
	save = b;
	while (i < len)
	{
		save[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
