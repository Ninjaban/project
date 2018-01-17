/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <mmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:22:23 by mmarchan          #+#    #+#             */
/*   Updated: 2014/04/16 19:08:16 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			count;

	str = (unsigned char *)s;
	count = 0;
	while (count < n)
		str[count++] = '\0';
}
