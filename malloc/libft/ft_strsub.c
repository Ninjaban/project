/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <mmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/05 12:31:29 by mmarchan          #+#    #+#             */
/*   Updated: 2014/04/16 20:04:33 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (len + 1));
	ft_strncpy(tmp, s + start, len);
	tmp[len] = '\0';
	return (tmp);
}
