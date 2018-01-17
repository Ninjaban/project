/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarchan <mmarchan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 16:57:02 by mmarchan          #+#    #+#             */
/*   Updated: 2014/04/16 19:55:19 by mmarchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_striter(char *s, void (*f)(char *))
{
	int		count;

	count = 0;
	if (s != NULL && f != NULL)
	{
		while (s[count] != '\0')
		{
			f(&s[count]);
			count++;
		}
	}
}
